#ifndef SHOPGOODS
#define SHOPGOODS
#include "Item.h"
#include "Pack.h"

class ShopGoods
{
public:

	int Shopping(Pack& mypack);
	void Shop_Print();
	int SnackShop(Pack& mypack);
	int ToyShop(Pack& mypack);
	int InShopping(int type, int choose, Pack& mypack);

	snack SackPack[10];
	Toy ToyPack[7];
};

#endif // !SHOPGOODS

