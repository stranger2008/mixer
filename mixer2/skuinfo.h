#ifndef __MIXER_SKUINFO_H__  
#define __MIXER_SKUINFO_H__  
  
#include <string>
#include <iostream>

using namespace std;
 
class SkuInfo
{
	private: 
		double weight;             // 推荐商品的权重(推荐透传，广告为空)
		string sku_id;               // 推荐商品的skuid，或店铺id(针对店铺广告)
		string title;              // 商品标题
		string jd_price;           // 京东渠道专享价
		string mkt_price;          // 市场价
		string img_url;            // 商品图片url
		string brand;              // 品牌名称
		int have_similar;          // 是否有看相似结果，1 有，0 没有
		string cid3;                  // 商品三级分类ID
		string clk;                // 点击本商品时需埋点，发送到点击流的url请求(推荐透传，广告为空)
		string impr;               // 点击流系统使用(推荐透传，广告为空，已知购物车会使用)
		int lp_type;               // 是否是店铺首页（店铺广告使用，为1则使用店铺id跳转，为0则使用target_url做landing page），首页推荐店铺广告使用
		string target_url;         // 活动广告跳转url，首页推荐店铺广告使用
		int source_type;           // 0(来自于推荐)，1(来自于广告)
		string clk_url;            // 点击本商品时需埋点，发送到点击流的url请求（内网地址，需要客户端访问服务器端后，由服务器端发起点击请求）
		string impression_url;     // 曝光url，mixer对最终返回的广告请求曝光日志
		string spu_id;               // 商品spuid
		string sid;                // 商品sid，推荐无此字段
		string pcp_price;          // 京东主站价
		int rect_type;             // 推荐类型

	public:

		double getWeight() {
			return weight;
		}

		void setWeight(double weight) {
			this->weight = weight;
		}

		string getSku_id() {
			return sku_id;
		}

		void setSku_id(string sku_id) {
			this->sku_id = sku_id;
		}

		string getTitle() {
			return title;
		}

		void setTitle(string title) {
			this->title = title;
		}

		string getJd_price() {
			return jd_price;
		}

		void setJd_price(string jd_price) {
			this->jd_price = jd_price;
		}

		string getMkt_price() {
			return mkt_price;
		}

		void setMkt_price(string mkt_price) {
			this->mkt_price = mkt_price;
		}

		string getImg_url() {
			return img_url;
		}

		void setImg_url(string img_url) {
			this->img_url = img_url;
		}

		string getBrand() {
			return brand;
		}

		void setBrand(string brand) {
			this->brand = brand;
		}

		int getHave_similar() {
			return have_similar;
		}

		void setHave_similar(int have_similar) {
			this->have_similar = have_similar;
		}

		string getCid3() {
			return cid3;
		}

		void setCid3(string cid3) {
			this->cid3 = cid3;
		}

		string getClk() {
			return clk;
		}

		void setClk(string clk) {
			this->clk = clk;
		}

		string getImpr() {
			return impr;
		}

		void setImpr(string impr) {
			this->impr = impr;
		}

		int getLp_type() {
			return lp_type;
		}

		void setLp_type(int lp_type) {
			this->lp_type = lp_type;
		}

		string getTarget_url() {
			return target_url;
		}

		void setTarget_url(string target_url) {
			this->target_url = target_url;
		}

		int getSource_type() {
			return source_type;
		}

		void setSource_type(int source_type) {
			this->source_type = source_type;
		}

		string getClk_url() {
			return clk_url;
		}

		void setClk_url(string clk_url) {
			this->clk_url = clk_url;
		}

		string getImpression_url() {
			return impression_url;
		}

		void setImpression_url(string impression_url) {
			this->impression_url = impression_url;
		}

		string getSpu_id() {
			return spu_id;
		}

		void setSpu_id(string spu_id) {
			this->spu_id = spu_id;
		}

		string getSid() {
			return sid;
		}

		void setSid(string sid) {
			this->sid = sid;
		}

		string getPcp_price() {
			return pcp_price;
		}

		void setPcp_price(string pcp_price) {
			this->pcp_price = pcp_price;
		}

		int getRect_type() {
			return rect_type;
		}

		void setRect_type(int rect_type) {
			this->rect_type = rect_type;
		}

};  
  
#endif 