#ifndef __MIXER_DATA_FETCHER_H__  
#define __MIXER_DATA_FETCHER_H__  

#include <iostream>
#include <string>
#include <map>
#include "context.h"

using namespace std;

class Fetcher{

public:

    Fetcher(void);

    ~Fetcher(void);

public:

    int FetchHttpData(map<string,string> params, string & strResponse, int rec_type);

	//获取广告http json数据，解析设置到context中的ad_result_里
	void RequestAdServer(Context* context);

	//获取推荐http json数据，解析设置到context中的re_result_里
	void RequestReServer(Context* context);

	void RequestDone(Context* context);

private:

	map<string,string> posIdToMap();

	string getAdPosIdFromMap(map<string,string> params,string key);

};
  
#endif 