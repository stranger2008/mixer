#include "mixer_resource.h"

#define CONF_PATH "mixer.ini"

MixerResource::MixerResource(){
	string ini_file = CONF_PATH;
	if (access(ini_file.c_str(), 0) == 0) {
		this->err_code = 0;
		boost::property_tree::ini_parser::read_ini(ini_file, this->m_pt);
	} else {
		this->err_code = 1;
	}
}

short MixerResource::errCode(){
	return this->err_code;
}

string MixerResource::get(string path){
	if (this->err_code == 0) {
		return this->m_pt.get<string>(path);
	} else {
		return "";
	}
}