#ifndef PACK
#define PACK
#include "Item.h"

class Pack
{
public:
    Pack();
    Pack(int, int, int);
    int GoldCoin; // ���

    //��ʳ����ߣ����10��
    int snack_num;
    int toy_num;
    snack ShopSnack[10];
    Toy  ShopToy[10];
};
#endif // !PACK


