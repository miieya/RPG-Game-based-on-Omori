#include "Pack.h"

//int Pack::GoldCoin = 0;
//int Pack::snack_num = 0;
//int Pack::toy_num = 0;
//snack Pack::ShopSnack[];
//Toy Pack::ShopToy[];

Pack::Pack() :GoldCoin(0), snack_num(0), toy_num(0) {};

Pack::Pack(int coin, int Snacknum, int Toolnum)
{
	this->GoldCoin = coin;
	this->snack_num = Snacknum;
	this->toy_num = Toolnum;
}