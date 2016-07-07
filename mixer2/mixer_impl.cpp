#include <iostream>
#include <string>
#include <map>
#include "fetcher.h"
#include "context.h"
#include "merger.h"
#include "mixer_resource.h"
#include "skuinfo.h"
#include "mixer_impl.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <boost/tokenizer.hpp>

char* MixerImpl::FetchDone(string req_str) {
	Context* context = new Context();
	context->context_start_time_ = context->GetTimeStampInUs();

	//request的参数转换成map
	reqToMap(context,req_str);
	//cout << " ---- [[" << context->getReqValueFromMap("pdd") << "]" << endl;
	string mixerCont;
	//获取推荐系统推荐位ID
	context->re_pos_id_ = context->getReqValueFromMap("p");

	//获取数据
	Fetcher* fetcher = new Fetcher();
	//fetcher->RequestAdServer(context);
	//fetcher->RequestReServer(context);
	fetcher->RequestDone(context);

	//融合数据
	Merger* merger = new Merger();
	merger->MergeSku(context);
	/*
	vector<SkuInfo*> test_vec = context->mixer_result_;
	int t_count = test_vec.size();
	for(int i = 0; i < t_count; i++) {
		 cout<< test_vec[i]->getSku_id() << " " << test_vec[i]->getTitle() << " " << test_vec[i]->getRect_type() << " ";
		 cout << test_vec[i]->getJd_price() << " " << test_vec[i]->getImg_url() << " " << test_vec[i]->getHave_similar() << " " << test_vec[i]->getCid3() << " " << test_vec[i]->getLp_type() << " ";
		 cout << test_vec[i]->getTarget_url() << " " << test_vec[i]->getSource_type() << " " << test_vec[i]->getImpression_url() << " " << test_vec[i]->getSpu_id() << " " << test_vec[i]->getSid();
		 cout << test_vec[i]->getClk() << " " << test_vec[i]->getClk_url() << endl;
	}
	cout << "ad_result size : " << t_count << endl;
	*/
	PackSkuJson(context,mixerCont);

	delete context;
	delete fetcher;
	delete merger;

	char* p=(char*)mixerCont.data();
	return p;
}

void MixerImpl::reqToMap(Context* context,string req_str){
	map<string,string> params;
	vector<string> tokens;
    boost::char_separator<char> sep("&");
    boost::tokenizer<boost::char_separator<char> > tok(req_str, sep);
    tokens.clear();
    std::copy(tok.begin(), tok.end(), std::back_inserter(tokens));   
    for (size_t i = 0; i < tokens.size(); ++ i){
        int pos_ = tokens[i].find_first_of("=");
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
	context->req_params = params;
}

void MixerImpl::PackSkuJson(Context* context,std::string & strResponse){
	std::string encode = context->getReqValueFromMap("ec");
	if (encode != "utf-8") {
		//非utf-8时默认用gbk编码方式
		encode = "gbk";
	}

	rapidjson::Document document;
	document.SetObject();
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

	rapidjson::Value str_val;
	document.AddMember("encode", str_val.SetString(encode.c_str(), allocator), allocator);
	document.AddMember("success", true, allocator);
	document.AddMember("error_msg", "", allocator);

	rapidjson::Value val_data(rapidjson::kArrayType);
	for (size_t i = 0; i < context->mixer_result_.size(); ++i) {
		SkuInfo* sku_info = context->mixer_result_[i];
		rapidjson::Value data_elem(rapidjson::kObjectType);
		data_elem.AddMember("w", sku_info->getWeight(), allocator);
		data_elem.AddMember("sku", str_val.SetString(sku_info->getSku_id().c_str(), allocator), allocator);
		data_elem.AddMember("spu", str_val.SetString(sku_info->getSku_id().c_str(), allocator), allocator);
		data_elem.AddMember("t", str_val.SetString(sku_info->getTitle().c_str(), allocator), allocator);
		data_elem.AddMember("jp", str_val.SetString(sku_info->getJd_price().c_str(), allocator), allocator);
		data_elem.AddMember("mp", str_val.SetString(sku_info->getMkt_price().c_str(), allocator), allocator);
		data_elem.AddMember("pcp", str_val.SetString(sku_info->getPcp_price().c_str(), allocator), allocator);
		data_elem.AddMember("img", str_val.SetString(sku_info->getImg_url().c_str(), allocator), allocator);
		data_elem.AddMember("bn", str_val.SetString(sku_info->getBrand().c_str(), allocator), allocator);
		data_elem.AddMember("have_similar", sku_info->getHave_similar(), allocator);
		rapidjson::Value val_subsku(rapidjson::kArrayType);
		data_elem.AddMember("subsku", val_subsku, allocator);
		data_elem.AddMember("c3", str_val.SetString(sku_info->getCid3().c_str(), allocator), allocator);
		data_elem.AddMember("clk", str_val.SetString(sku_info->getClk().c_str(), allocator), allocator);
		data_elem.AddMember("impr", str_val.SetString(sku_info->getImpr().c_str(), allocator), allocator);
		data_elem.AddMember("lp_type", sku_info->getLp_type(), allocator);
		data_elem.AddMember("target_url", str_val.SetString(sku_info->getTarget_url().c_str(), allocator), allocator);
		data_elem.AddMember("source", sku_info->getSource_type(), allocator);
		data_elem.AddMember("clk_url", str_val.SetString(sku_info->getClk_url().c_str(), allocator), allocator);
		data_elem.AddMember("sid", str_val.SetString(sku_info->getSid().c_str(), allocator), allocator);

		val_data.PushBack(data_elem, allocator);
	}
	document.AddMember("data", val_data, allocator);
	document.AddMember("flow", context->flow_type_, allocator);
	document.AddMember("impr", str_val.SetString(context->impr_.c_str(), allocator), allocator);

	
	uint64_t time_end = context->GetTimeStampInUs();
	uint64_t latency = (time_end - context->context_start_time_);
	document.AddMember("latency", latency, allocator);

	//TODO
	document.AddMember("timestamp", "", allocator);

	rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);
    std::string reststring = buffer.GetString();
	
	string callback = context->getReqValueFromMap("callback");
	if (!callback.empty()) {
      reststring = callback + "(" + buffer.GetString() + ")";
    }
	//std::cout << "+++++++++++++++++++++++++++++++++" << reststring << std::endl;

	strResponse = reststring;
}