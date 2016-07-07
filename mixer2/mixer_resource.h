#ifndef __MIXER_RESOURCE_H__
#define __MIXER_RESOURCE_H__  
  
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <string>

using namespace std;
  
  
class MixerResource{

public:
    MixerResource();
    string get(string path);
    short int errCode();
private:
    short int err_code;
    boost::property_tree::ptree m_pt;
};

#endif