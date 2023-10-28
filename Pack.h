#ifndef PACK
#define PACK
#include "Item.h"

class Pack
{
public:
    Pack();
    Pack(int, int, int);
    int GoldCoin; // 金币

    //零食或玩具：最多10个
    int snack_num;
    int toy_num;
    snack ShopSnack[10];
    Toy  ShopToy[10];
};
#endif // !PACK


