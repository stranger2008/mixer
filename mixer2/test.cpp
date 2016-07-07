#include <iostream>
#include <unistd.h>
#include <string>
#include <map>
#include "fetcher.h"
#include "context.h"
#include "merger.h"
#include "mixer_resource.h"
#include "skuinfo.h"
#include "mixer_impl.h"
#include <boost/date_time/posix_time/posix_time_types.hpp>  

using namespace	std;

uint64_t ss(){
	boost::posix_time::ptime time = boost::posix_time::microsec_clock::local_time();
	boost::posix_time::time_duration duration( time.time_of_day() );
	std::cout << duration.total_milliseconds() << std::endl;
	return duration.total_milliseconds();
}

int main(){

	/*
	uint64_t start_time = ss();

	sleep(1);

	uint64_t time_end = ss();

	uint64_t latency = (time_end - start_time);

	cout << latency << endl;
	*/
	string str = "p=205000&skus=1603952102&lid=1&lim=20&uuid=2095932174&ec=utf-8&callback=Grecommend.set&pin=";

	MixerImpl* mixerImpl = new MixerImpl();
	char* mixerCont = mixerImpl->FetchDone(str);
    delete mixerImpl;

	std::cout << "mixerCont+++++++++++++++++++++++++++++++++" << mixerCont << std::endl;

	return 0;
}