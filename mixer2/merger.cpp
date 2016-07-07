#include "merger.h"

bool Merger::GetValidSkuIdx(const std::vector<SkuInfo*>& sku_vec,const std::set<string>& no_dup_sku_id_set,Context* context, int32_t* cur_index) {
  for (int i = *cur_index; i < sku_vec.size(); ++i) {
    if (IfDuplicateSku(no_dup_sku_id_set,sku_vec[i]->getSku_id(),sku_vec[i]->getSpu_id())) {
      continue;
    }
    *cur_index = ++i; // 返回下次检索的起始下标
    return true;
  }
  *cur_index = sku_vec.size();
  return false;
}

bool Merger::IfDuplicateSku(const std::set<string>& no_dup_sku_id_set,string sku_id, string spu_id) {
  if ((spu_id != "" && no_dup_sku_id_set.find(spu_id)!= no_dup_sku_id_set.end())) {
    return true;
  }
  if ((sku_id != "" && no_dup_sku_id_set.find(sku_id)!= no_dup_sku_id_set.end())) {
    return true;
  }
  return false;
}

void Merger::MergeSku(Context* context) {
	const std::vector<SkuInfo*>& re_vec = context->re_result_;
	const std::vector<SkuInfo*>& ad_vec = context->ad_result_;
	std::vector<SkuInfo*>& merged_sku_vec = context->mixer_result_;

	//TODO 此处应该从context中取lim
	int ad_cnt = 6;
	bool ret;
	int32_t index_re = 0; // 查找合法推荐的起始下标
	int32_t index_ad = 0; // 查找合法广告的起始下标
	std::set<string> no_dup_sku_id_set;

	for (int i = 0; i < ad_cnt; ++i) {
		if ((i % 2 == 0 && index_re < re_vec.size() && index_ad < ad_vec.size()) || (index_ad >= ad_vec.size()) ) {
		  ret = GetValidSkuIdx(re_vec, no_dup_sku_id_set, context, &index_re);
		  if (ret) {
			merged_sku_vec.push_back(re_vec[index_re - 1]);
			if (re_vec[index_re - 1]->getSku_id() != "") {
			  no_dup_sku_id_set.insert(re_vec[index_re - 1]->getSku_id());
			}
			if (re_vec[index_re - 1]->getSpu_id() != "") {
			  no_dup_sku_id_set.insert(re_vec[index_re - 1]->getSpu_id());
			}
		  }
		} else if ((i % 2 == 1 && index_re < re_vec.size() && index_ad < ad_vec.size()) || (index_re >= re_vec.size()) ) {
		  ret = GetValidSkuIdx(ad_vec, no_dup_sku_id_set, context, &index_ad);
		  if (ret) {
			merged_sku_vec.push_back(ad_vec[index_ad - 1]);
			if (ad_vec[index_ad - 1]->getSku_id() != "") {
			  no_dup_sku_id_set.insert(ad_vec[index_ad - 1]->getSku_id());
			}
			if (ad_vec[index_ad - 1]->getSpu_id() != "") {
			  no_dup_sku_id_set.insert(ad_vec[index_ad - 1]->getSpu_id());
			}
		  }
		}

		if (index_re >= re_vec.size() && index_ad >= ad_vec.size()) {
		  break;
		}
	}

}


