#ifndef SERVERS_MIXER_SRC_MIXER_PROC_H
#define SERVERS_MIXER_SRC_MIXER_PROC_H

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "skuinfo.h"
#include "context.h"

using namespace std;

class Merger {

 public:

  bool IfDuplicateSku(const std::set<string>& no_dup_sku_id_set,string sku_id,string spu_id);

  bool GetValidSkuIdx(const std::vector<SkuInfo*>& sku_vec,const std::set<string>& no_dup_sku_id_set,Context* context, int32_t* cur_index);

  void MergeSku(Context* context);

};

#endif
