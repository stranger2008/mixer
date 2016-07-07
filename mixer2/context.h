#ifndef __MIXER_CONTEXT_H__  
#define __MIXER_CONTEXT_H__  
  
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "skuinfo.h"
#include "rapidjson/document.h"
#include <boost/date_time/posix_time/posix_time_types.hpp>

using namespace std;
  
struct Context {

	public :
		string getReqValueFromMap(string key){
			map<string,string> params = req_params;
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

		uint64_t GetTimeStampInUs(){
			boost::posix_time::ptime time = boost::posix_time::microsec_clock::local_time();
			boost::posix_time::time_duration duration( time.time_of_day() );
			std::cout << duration.total_milliseconds() << std::endl;
			return duration.total_milliseconds();
		}
	
	public :
	  map<string,string> req_params;                         //请求map
	  uint64_t context_start_time_;                              // context开始时间
	  std::string impr_;                                     // 推荐或广告返回结果中的impr
	  std::string ad_pos_id_;                                        // 请求广告的广告位
	  std::string re_pos_id_;                                        // 请求推荐的广告位
	  std::string request_ad_url_;                           // 请求广告的url
	  std::string request_re_url_;                           // 请求推荐的url
	  rapidjson::Document ad_response_dom_;                  // 请求广告返回的json(dom结构)
	  rapidjson::Document re_response_dom_;                  // 请求推荐返回的json(dom结构)
	  std::vector<SkuInfo*> ad_result_;                      // 请求广告的返回结果
	  std::vector<SkuInfo*> re_result_;                      // 请求推荐的返回结果
	  std::vector<SkuInfo*> mixer_result_;                   // 最终mixer的返回结果，内容来自ad_result_和re_result_，析构时无需单独释放内存
	  // mixer返回结果中的flow类型，0：混合流量（广告+推荐），
	  // 1：推荐对照流量（无广告），2：广告对照流量（无推荐）
	  int flow_type_;

};
  
#endif 