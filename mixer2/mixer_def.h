#ifndef SERVERS_MIXER_SRC_MIXER_DEF_H
#define SERVERS_MIXER_SRC_MIXER_DEF_H

#include <string>


  enum SourceType {
	FROM_RE_TYPE = 0, // (返回结果)来源于推荐
	FROM_AD_TYPE = 1, // (返回结果)来源于广告
  };

  static const std::string APP_RE_WARE_POS = "620003,621017";
  static const std::string MIXER_RE_POS_TO_AD_POS = "107000:1799,303000:1800,205000:1798,105000:1802,102004:1802,202002:1805,504000:1806,201002:1807,201000:1808,509001:1849,610008:1850,610014:1854,902027:1855,201000:1851,108002:1852,109000:1853";

  enum MixerFlowType {
	GROUP_MIX = 0, // 表示混合流量(同时存在广告和推荐的流量)
	GROUP_CMP_RE = 1, // 表示推荐对照流量(无广告返回的流量)
	GROUP_CMP_AD = 2 // 表示广告对照流量(无推荐返回的流量)
  };

  enum RectType {
	SKU_TYPE = 0,       // 商品sku
	SHOP_TYPE = 1,      // 店铺
	ACTIVITY_TYPE = 2,  // 活动
	TAG_TYPE = 3,       // 标签
	BRAND_TYPE = 4,     // 品牌
	SPU_TYPE = 5,       // 商品spu
	OTHER_TYPE = 99,    // 其他
  };

  enum AdType {
	UNKNOW_TYPE = 0,
	PIC_TYPE = 1,     // 图片
	WARE_TYPE = 3,    // 商品
	VENDER_TYPE = 4,  // 店铺
  };

#endif // SERVERS_MIXER_SRC_MIXER_DEF_H
