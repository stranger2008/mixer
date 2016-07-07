#include "fetcher.h"
#include "skuinfo.h"
#include "mixer_def.h"
#include "httpclient.h"
#include "rapidjson/document.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include "mixer_resource.h"
#include <boost/tokenizer.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

#define psln(x) std::cout << #x " = " << (x) << std::endl

using namespace boost;
using namespace std;

#define AD_REQUEST_URL "http://x.jd.com/ShowInterface?ad_type=7&spread_type=1&mobile_type=2&device_type=16&template=0&" 

#define RE_REQUEST_URL "http://diviner.jd.com/diviner?"
//#define RE_REQUEST_URL "http://diviner.jd.com/diviner?p=620003&uuid=1203019024&sku=&skus=&pin=&c1=&c2=&c3=&lid=1&lim=8&sp=&hi=&fe=&fne=&ro=&ec=gbk"

Fetcher::Fetcher(void)
{}
  
Fetcher::~Fetcher(void)
{}

map<string,string> Fetcher::posIdToMap(){
	map<string,string> params;
	vector<string> tokens;
    boost::char_separator<char> sep(",");
    boost::tokenizer<boost::char_separator<char> > tok(MIXER_RE_POS_TO_AD_POS, sep);
    tokens.clear();
    std::copy(tok.begin(), tok.end(), std::back_inserter(tokens));   
    for (size_t i = 0; i < tokens.size(); ++ i){
        int pos_ = tokens[i].find_first_of(":");
		string p_key = tokens[i].substr(0,pos_);
		string p_value = tokens[i].substr(pos_+1,tokens[i].length());
		params.insert(map<string,string>::value_type(p_key,p_value));
    }
	/*
	map<string,string>::iterator it = params.begin();
	string queryStr = "";
    for(it=params.begin();it!=params.end();++it){
        cout<<"key: "<<it->first <<" value: "<<it->second<<endl;
	}
	*/
	return params;
}

string Fetcher::getAdPosIdFromMap(map<string,string> params,string key){
	map<string,string>::iterator it = params.begin();
	for(it=params.begin();it!=params.end();++it){
		string _key = it->first;
		string _value = it->second;
		if(_key == key){
			return _value;
		}
	}
	return "";
}

int Fetcher::FetchHttpData(map<string,string> params, std::string & strResponse, int rec_type){  
    map<string,string>::iterator it = params.begin();
	string queryStr = "";
	//cout<<"rec_type : "<<rec_type<<endl;
	int i = 1;
    for(it=params.begin();it!=params.end();++it){
        //cout<<"key: "<<it->first <<" value: "<<it->second<<endl;
		if(it->first == "callback"){
			continue;
		}
		if(i > 1){
			queryStr += "&";
		}
		queryStr += it->first + "=" + it->second;
		i++;
	}
	if(rec_type == FROM_RE_TYPE){
		queryStr = RE_REQUEST_URL + queryStr;
	}else if(rec_type == FROM_AD_TYPE){
		queryStr = AD_REQUEST_URL + queryStr;
	}
	cout << "ad query url : " << queryStr << endl;
	CHttpClient* httpClient = new CHttpClient();
	int res = httpClient->Get(queryStr,strResponse);
	delete httpClient;
    return 0;
}


void Fetcher::RequestAdServer(Context* context){
	string content;
	map<string,string> params;

	string uuid = context->getReqValueFromMap("uuid");
	string location_info = context->getReqValueFromMap("lid");
	string lim = context->getReqValueFromMap("lim");
	if(lim == ""){
		lim = 20;
	}
	//通过推荐系统ID找广告系统ID

	context->ad_pos_id_ = getAdPosIdFromMap(posIdToMap(),context->re_pos_id_);

	params.insert(map<string,string>::value_type("ad_ids",context->ad_pos_id_ + ":" + lim));

	//TODO cookie处理
	params.insert(map<string,string>::value_type("pin","134864899-443038"));
	params.insert(map<string,string>::value_type("device_id",uuid));
	params.insert(map<string,string>::value_type("location_info",location_info));

	FetchHttpData(params,content,FROM_AD_TYPE);
	//cout << "==================================" << endl << content.c_str();

	// parse json from string.
    using rapidjson::Document;
    Document doc;
    doc.Parse<0>(content.c_str());
    if (doc.HasParseError()) {
        rapidjson::ParseErrorCode code = doc.GetParseError();
		psln(code);
        //return 5;
    }

	//读取配置判断当前推荐位是否在mixer_re_pos_to_ad_pos（mixer.ini）里
	string re_pos_id = context->re_pos_id_;
	//MixerResource mixerResource;
	//string mixer_re_pos_to_ad_pos = mixerResource.get(MIXER_RE_POS_TO_AD_POS);
	//int re_id_pos_int = mixer_re_pos_to_ad_pos.find(re_pos_id, 0);
	int re_id_pos_int = MIXER_RE_POS_TO_AD_POS.find(re_pos_id, 0);

	// use values in parse result.
    using rapidjson::Value;
	char* doc_index_ad = (char*)context->ad_pos_id_.data();
    Value & contents = doc[doc_index_ad];
    if (contents.IsArray()) {
        for (size_t i = 0; i < contents.Size(); ++i) {

			SkuInfo* sku_info = new SkuInfo();

            Value & v = contents[i];

            if (v.HasMember("sku_id") && v["sku_id"].IsString()) {
                //psln(v["spu_id"].GetString());
				sku_info->setSku_id(v["sku_id"].GetString());
            }

            if (v.HasMember("ad_title") && v["ad_title"].IsString()) {
				sku_info->setTitle(v["ad_title"].GetString());
            }

			if (v.HasMember("ad_type") && v["ad_type"].IsString()) {
				int ad_type = atoi(v["ad_type"].GetString());
				if (WARE_TYPE == ad_type) {
					sku_info->setRect_type(SPU_TYPE);
				} else if (VENDER_TYPE == ad_type) {
					sku_info->setRect_type(SHOP_TYPE);
					if (v.HasMember("shop_id") && v["shop_id"].IsString()) {
						sku_info->setSku_id(v["shop_id"].GetString());
					}
				}
            }

			if (v.HasMember("sku_price") && v["sku_price"].IsString()) {
				sku_info->setJd_price(v["sku_price"].GetString());
            }

			if (v.HasMember("image_url") && v["image_url"].IsString()) {
				sku_info->setImg_url(v["image_url"].GetString());
            }

			if (v.HasMember("have_similar") && v["have_similar"].IsInt()) {
				sku_info->setHave_similar(v["have_similar"].GetInt());
            }

			if (v.HasMember("sku_cid3") && v["sku_cid3"].IsString()) {
				sku_info->setCid3(v["sku_cid3"].GetString());
            }
			
			if (v.HasMember("lp_type") && v["lp_type"].IsInt()) {
				sku_info->setLp_type(v["lp_type"].GetInt());
            }

			if (v.HasMember("target_url") && v["target_url"].IsString()) {
				sku_info->setTarget_url(v["target_url"].GetString());
            }

			if (v.HasMember("click_url") && v["click_url"].IsString()) {
				string click_url = v["click_url"].GetString();
				if(re_id_pos_int != string::npos){
					sku_info->setClk(click_url);
				}else{
					sku_info->setClk_url(click_url);
				}
            }

			//TODO impression_url
			if (v.HasMember("impression_url") && v["impression_url"].IsString()) {
				sku_info->setImpression_url(v["impression_url"].GetString());
            }

			if (v.HasMember("spu_id") && v["spu_id"].IsString()) {
				sku_info->setSpu_id(v["spu_id"].GetString());
            }

			if (v.HasMember("sid") && v["sid"].IsString()) {
				sku_info->setSid(v["sid"].GetString());
            }

			sku_info->setSource_type(FROM_AD_TYPE); // 来源于广告
			
			context->ad_result_.push_back(sku_info);
        }
    }
	
	/*
	vector<SkuInfo*> test_vec = context->ad_result_;
	int t_count = test_vec.size();
	for(int i = 0; i < t_count; i++) {
		 cout<< test_vec[i]->getSku_id() << " " << test_vec[i]->getTitle() << " " << test_vec[i]->getRect_type() << " ";
		 cout << test_vec[i]->getJd_price() << " " << test_vec[i]->getImg_url() << " " << test_vec[i]->getHave_similar() << " " << test_vec[i]->getCid3() << " " << test_vec[i]->getLp_type() << " ";
		 cout << test_vec[i]->getTarget_url() << " " << test_vec[i]->getSource_type() << " " << test_vec[i]->getImpression_url() << " " << test_vec[i]->getSpu_id() << " " << test_vec[i]->getSid();
		 cout << test_vec[i]->getClk() << " " << test_vec[i]->getClk_url() << endl;
	}
	cout << "ad_result size : " << t_count << endl;
	*/
	
}

void Fetcher::RequestReServer(Context* context){
	string content;

	//map<string,string> params;
	//params.insert(map<string,string>::value_type("ad_ids","1207:18"));

	FetchHttpData(context->req_params,content,FROM_RE_TYPE);
	//FetchHttpData(params,content,FROM_RE_TYPE);
	//cout << "==================================" << endl << content.c_str();

	// parse json from string.
    using rapidjson::Document;
    Document doc;
    doc.Parse<0>(content.c_str());
    if (doc.HasParseError()) {
        rapidjson::ParseErrorCode code = doc.GetParseError();
		psln(code);
        //return 5;
    }

	//读取配置判断当前推荐位是否在app_re_ware_pos（mixer.ini）里
	string re_pos_id = context->re_pos_id_;
	//MixerResource mixerResource;
	//string app_re_ware_pos = mixerResource.get(APP_RE_WARE_POS);
	//int re_id_pos_int = app_re_ware_pos.find(re_pos_id, 0);
	int re_id_pos_int = APP_RE_WARE_POS.find(re_pos_id, 0);

	// use values in parse result.
    using rapidjson::Value;
    Value & contents = doc["data"];
	if (contents.IsArray()) {
        for (size_t i = 0; i < contents.Size(); ++i) {
			SkuInfo* sku_info = new SkuInfo();
            Value & v = contents[i];

			if (v.HasMember("w") && v["w"].IsNumber()) {
				sku_info->setWeight(v["w"].GetDouble());
            }

            if (v.HasMember("sku") && v["sku"].IsInt64()) {
				int64_t s_id_int64 = v["sku"].GetInt64();
				ostringstream oss;
				oss << s_id_int64;
				sku_info->setSku_id(oss.str());
            }

			if (v.HasMember("spu") && v["spu"].IsInt64()) {
				int64_t s_id_int64 = v["spu"].GetInt64();
				ostringstream oss;
				oss << s_id_int64;
				sku_info->setSpu_id(oss.str());
            }

			if (v.HasMember("t") && v["t"].IsString()) {
				sku_info->setTitle(v["t"].GetString());
            }

			if (v.HasMember("jp") && v["jp"].IsString()) {
				sku_info->setJd_price(v["jp"].GetString());
            }

			if (v.HasMember("mp") && v["mp"].IsString()) {
				sku_info->setMkt_price(v["mp"].GetString());
            }

			if (v.HasMember("img") && v["img"].IsString()) {
				sku_info->setImg_url(v["img"].GetString());
            }

			if (v.HasMember("bn") && v["bn"].IsString()) {
				string bn_value = v["bn"].GetString();
				if(re_id_pos_int != string::npos){
					stringstream ss;
					ss<<bn_value;
					int bn_int;
					ss>>bn_int;
					sku_info->setHave_similar(bn_int);
				}else{
					sku_info->setBrand(bn_value);
				}
            }
			
			if (v.HasMember("c3") && v["c3"].IsInt64()) {
				int64_t s_id_int64 = v["c3"].GetInt64();
				ostringstream oss;
				oss << s_id_int64;
				sku_info->setCid3(oss.str());
            }

			if (v.HasMember("clk") && v["clk"].IsString()) {
				sku_info->setClk(v["clk"].GetString());
            }

			if (v.HasMember("impr") && v["impr"].IsString()) {
				sku_info->setImpr(v["impr"].GetString());
            }

			if (v.HasMember("rt") && v["rt"].IsString()) {
				stringstream ss;
				ss<<v["rt"].GetString();
				int rt_int;
				ss>>rt_int;
				sku_info->setRect_type(rt_int);
            }

			sku_info->setSource_type(FROM_RE_TYPE); // 来源于广告

			context->re_result_.push_back(sku_info);
        }
    }

	if (doc.HasMember("impr") && doc["impr"].IsString()) {
		context->impr_ = doc["impr"].GetString();
	}

	/*
	vector<SkuInfo*> test_vec = context->re_result_;
	int t_count = test_vec.size();
	for(int i = 0; i < t_count; i++) {
		cout << test_vec[i]->getSku_id() << " " << test_vec[i]->getSpu_id() << " " << test_vec[i]->getTitle() << " " << test_vec[i]->getJd_price() << " " << test_vec[i]->getMkt_price() << " " << test_vec[i]->getImg_url();
		cout << " " << test_vec[i]->getCid3() << " " << test_vec[i]->getClk() << " " << test_vec[i]->getImpr() << " " << test_vec[i]->getRect_type() << " " << test_vec[i]->getSource_type() << " " << test_vec[i]->getHave_similar();
		cout << " " << test_vec[i]->getBrand() << " " << test_vec[i]->getWeight() << endl;
	}
	cout << "re_result size : " << t_count << endl;
	*/
}

void Fetcher::RequestDone(Context* context){
	//int num = 2;
    //thread_group threads;
	//threads.create_thread(bind(&RequestAdServer, context));
	//threads.create_thread(bind(&RequestReServer, context));
	//threads.join_all();
	RequestAdServer(context);
	RequestReServer(context);
}