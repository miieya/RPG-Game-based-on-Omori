#ifndef BUYMENU_H
#define BUYMENU_H
#include "ShopGoods.h"
#include "Pack.h"
#include "Fight.h"
#include "Tool.h"

class BuyMenu
{
public:

	void map_Print(Tool& t, Fight& f);

	void tofu(Tool&);
	void candy(Tool&);
	void pulm_juice(Tool&);
	void breadfruit_juice(Tool&);

	void confetti(Tool&);
	void rain_cloud(Tool&);
	void air_horn(Tool&);

	void buytofu(Tool&, Fight& fight);
	void buycandy(Tool&, Fight& fight);
	void buypulm_juice(Tool&, Fight& fight);
	void buybreadfruit_juice(Tool&, Fight& fight);

	void buyconfetti(Tool&, Fight& fight);
	void buyrain_cloud(Tool&, Fight& fight);
	void buyair_horn(Tool&, Fight& fight);
	void buy_choose(Tool&, Fight& fight);

	void Position(int x0, int y0, int x1, int y1, Tool& t);
	int  ClueJudge(int x1, int y1);
	void Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t, Fight& fight);
	void Execute_buymenu(Tool& t, int judge, Fight& fight);

	int map[19][25] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,1,1,1,1,1,1,1,1,0,0,0,2,2,0,0,12,12,0,0,0,0,1,
						1,0,0,1,1,1,1,1,1,1,1,0,0,0,3,3,0,0,13,13,0,0,0,0,1,
						1,0,0,1,1,1,1,1,1,1,1,0,0,0,4,4,0,0,14,14,0,0,0,0,1,
						1,0,0,1,1,1,1,1,1,1,1,0,0,0,5,5,0,0,15,15,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,1,1,1,1,1,1,1,1,0,0,0,6,6,0,0,16,16,0,0,0,0,1,
						1,0,0,1,1,1,1,1,1,1,1,0,0,0,7,7,0,0,17,17,0,0,0,0,1,
						1,0,0,1,1,1,1,1,1,1,1,0,0,0,8,8,0,0,18,18,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	ShopGoods shop;
	//Pack MyPack;
	//2¡¢µçÄÔ  3¡¢»­±¾  4¡¢Ö½½íºÐ   5¡¢ß÷ÎØ  6¡¢µÆÅÝ   7¡¢ÃÅ   8¡¢Ð¡µ¶
};
#endif
