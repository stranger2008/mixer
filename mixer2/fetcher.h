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

	//��ȡ���http json���ݣ��������õ�context�е�ad_result_��
	void RequestAdServer(Context* context);

	//��ȡ�Ƽ�http json���ݣ��������õ�context�е�re_result_��
	void RequestReServer(Context* context);

	void RequestDone(Context* context);

private:

	map<string,string> posIdToMap();

	string getAdPosIdFromMap(map<string,string> params,string key);

};
  
#endif 