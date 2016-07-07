#ifndef RECOMMEND_MIXER_SERVICE_IMPL_H_
#define RECOMMEND_MIXER_SERVICE_IMPL_H_

#include "context.h"

class MixerImpl{

 public:
	 char* FetchDone(string req_str);

 private:
	 void PackSkuJson(Context* context,std::string & strResponse);
	 void reqToMap(Context* context,string req_str);

};

#endif  // RECOMMEND_MIXER_SERVICE_IMPL_H_
