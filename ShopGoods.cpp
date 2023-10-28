#include "ShopGoods.h"
#include "Item.h"
#include "Tool.h"
#include <iostream>
using namespace std;

int ShopGoods::Shopping(Pack& mypack) //逛商店
{
    int choose = 0;
    int x;
    while (1)
    {
        Cue_Info CueInfo_ = Shop_03;
        Shop_Print();

        cin >> choose;
        x = cin.get(); //清除垃圾字符
        putchar(x);

        switch (choose)
        {
        case 1: //零食
            SnackShop(mypack);
            break;
        case 2: //玩具
            ToyShop(mypack);
            break;
        case 3: //返回
            return 0;
            break;
        default:
            cout << "输入有误,请重新选择" << endl;
            break;
        }
    }
    return 0;
}

void ShopGoods::Shop_Print()
{
    cout << "请问你需要什么？" << endl;
    cout << "1   零食" << endl;
    cout << "2   玩具" << endl;
    cout << "3   退出商店" << endl;
}

int ShopGoods::SnackShop(Pack& mypack)
{
    int iChoose = 0;
    int ret = 0;

    int i = 1;
    cout << "请问你需要什么零食？" << std::endl;
    for (i = 1; i <= 10; i++)
    {
        cout << i << " " << Map_Snacks.at(static_cast<Snacks>(i)) << std::endl;
    }
    cout << i << " 退出商店" << std::endl;
    cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << std::endl;
    cout << "请选择: ";

    while (1)
    {
        cin >> iChoose;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //清除垃圾字符

        switch (iChoose)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        {
            ret = InShopping(1, iChoose, mypack);
            if (ret == 0)
            {
                return 0;
            }
        }
        break;
        case 11:
            return 0;
        default:
            cout << "未开放，敬请期待" << endl;
            break;
        }

        cout << "请重新选择" << endl;
    }
    return 0;
}

int ShopGoods::ToyShop(Pack& mypack)
{
    Tool t;
    int iChoose = 0;
    int ret = 0;

    int i = 1;
    cout << "请问你需要什么玩具？" << endl;
    for (i = 1; i <= 7; i++)
    {
        cout << i << " " << Map_Toys.at(static_cast<Toys>(i)) << endl;
    }
    cout << i << " 退出商店" << endl;
    cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
    cout << "请选择: ";

    while (1)
    {
        std::cin >> iChoose;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //清除垃圾字符

        switch (iChoose)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        {
            ret = InShopping(2, iChoose, mypack);
            if (ret == 0)
            {
                return 0;
            }
            
            cout << "请重新选择" << endl;
        }
        break;
        case 8:
            return 0;
        default:
            break;
        }
        cout << "请重新选择" << endl;
    }
    return 0;
}

// 购买机制
// 参数type: 1 snack;   2 tool
int ShopGoods::InShopping(int type, int choose, Pack& MyPack)
{
    Tool t;
    if (type == 1) //购买零食
    {
        snack _Snack = this->SackPack[choose];
        // 判断金额是否正常
        if (MyPack.GoldCoin > _Snack.pay)
        {
            if (MyPack.snack_num < 10)
            {
                //找位置
                for (int i = 0; i < 10; i++)
                {
                    if (MyPack.ShopSnack[i].type != 0)
                    {
                        MyPack.ShopSnack[i] = _Snack;
                        break;
                    }
                }
                MyPack.snack_num++;
                MyPack.GoldCoin -= _Snack.pay;

                t.gotoXY(40, 21);
                cout << "已消费 " << _Snack.pay << " 购买 " << Map_Snacks.at(static_cast<Snacks>(_Snack.type));
                t.wait(2000);
                t.clearLine(40, 21);
            }
            else
            {
                t.gotoXY(40, 21);
                cout << "零食仓已满，请消耗后再购买!";
                t.wait(2000);
                t.clearLine(40, 21);
                return -1;
            }
        }
        else
        {
            t.gotoXY(40, 21);
            cout << "金币不足";
            t.wait(2000);
            t.clearLine(40, 21);
            return -1;
        }
    }
    else if (type == 2)          //购买玩具
    {
        Toy _toy = this->ToyPack[choose];
        // 判断金额是否正常
        if (MyPack.GoldCoin > _toy.pay)
        {
            if (MyPack.toy_num < 10)
            {
                //找位置
                for (int i = 0; i < 10; i++)
                {
                    if (MyPack.ShopToy[i].type != 0)
                    {
                        MyPack.ShopToy[i] = _toy;
                        break;
                    }
                }
                MyPack.toy_num++;
                MyPack.GoldCoin -= _toy.pay;

                t.gotoXY(40, 21);
                cout << "已消费 " << _toy.pay << " 购买 " << Map_Toys.at(static_cast<Toys>(_toy.type));
                t.wait(2000);
                t.clearLine(40, 21);
            }
            else
            {
                t.gotoXY(40, 21);
                cout << "玩具仓已满，请消耗后再购买！";
                t.wait(2000);
                t.clearLine(40, 21);
                return -1;
            }
        }
        else
        {
            t.gotoXY(40, 20);
            cout << "金币不足";
            t.wait(2000);
            t.clearLine(40, 21);
            return -1;
        }
    }
    return 0;
}

