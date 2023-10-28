#include "ShopGoods.h"
#include "Item.h"
#include "Tool.h"
#include <iostream>
using namespace std;

int ShopGoods::Shopping(Pack& mypack) //���̵�
{
    int choose = 0;
    int x;
    while (1)
    {
        Cue_Info CueInfo_ = Shop_03;
        Shop_Print();

        cin >> choose;
        x = cin.get(); //��������ַ�
        putchar(x);

        switch (choose)
        {
        case 1: //��ʳ
            SnackShop(mypack);
            break;
        case 2: //���
            ToyShop(mypack);
            break;
        case 3: //����
            return 0;
            break;
        default:
            cout << "��������,������ѡ��" << endl;
            break;
        }
    }
    return 0;
}

void ShopGoods::Shop_Print()
{
    cout << "��������Ҫʲô��" << endl;
    cout << "1   ��ʳ" << endl;
    cout << "2   ���" << endl;
    cout << "3   �˳��̵�" << endl;
}

int ShopGoods::SnackShop(Pack& mypack)
{
    int iChoose = 0;
    int ret = 0;

    int i = 1;
    cout << "��������Ҫʲô��ʳ��" << std::endl;
    for (i = 1; i <= 10; i++)
    {
        cout << i << " " << Map_Snacks.at(static_cast<Snacks>(i)) << std::endl;
    }
    cout << i << " �˳��̵�" << std::endl;
    cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << std::endl;
    cout << "��ѡ��: ";

    while (1)
    {
        cin >> iChoose;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //��������ַ�

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
            cout << "δ���ţ������ڴ�" << endl;
            break;
        }

        cout << "������ѡ��" << endl;
    }
    return 0;
}

int ShopGoods::ToyShop(Pack& mypack)
{
    Tool t;
    int iChoose = 0;
    int ret = 0;

    int i = 1;
    cout << "��������Ҫʲô��ߣ�" << endl;
    for (i = 1; i <= 7; i++)
    {
        cout << i << " " << Map_Toys.at(static_cast<Toys>(i)) << endl;
    }
    cout << i << " �˳��̵�" << endl;
    cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
    cout << "��ѡ��: ";

    while (1)
    {
        std::cin >> iChoose;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //��������ַ�

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
            
            cout << "������ѡ��" << endl;
        }
        break;
        case 8:
            return 0;
        default:
            break;
        }
        cout << "������ѡ��" << endl;
    }
    return 0;
}

// �������
// ����type: 1 snack;   2 tool
int ShopGoods::InShopping(int type, int choose, Pack& MyPack)
{
    Tool t;
    if (type == 1) //������ʳ
    {
        snack _Snack = this->SackPack[choose];
        // �жϽ���Ƿ�����
        if (MyPack.GoldCoin > _Snack.pay)
        {
            if (MyPack.snack_num < 10)
            {
                //��λ��
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
                cout << "������ " << _Snack.pay << " ���� " << Map_Snacks.at(static_cast<Snacks>(_Snack.type));
                t.wait(2000);
                t.clearLine(40, 21);
            }
            else
            {
                t.gotoXY(40, 21);
                cout << "��ʳ�������������ĺ��ٹ���!";
                t.wait(2000);
                t.clearLine(40, 21);
                return -1;
            }
        }
        else
        {
            t.gotoXY(40, 21);
            cout << "��Ҳ���";
            t.wait(2000);
            t.clearLine(40, 21);
            return -1;
        }
    }
    else if (type == 2)          //�������
    {
        Toy _toy = this->ToyPack[choose];
        // �жϽ���Ƿ�����
        if (MyPack.GoldCoin > _toy.pay)
        {
            if (MyPack.toy_num < 10)
            {
                //��λ��
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
                cout << "������ " << _toy.pay << " ���� " << Map_Toys.at(static_cast<Toys>(_toy.type));
                t.wait(2000);
                t.clearLine(40, 21);
            }
            else
            {
                t.gotoXY(40, 21);
                cout << "��߲������������ĺ��ٹ���";
                t.wait(2000);
                t.clearLine(40, 21);
                return -1;
            }
        }
        else
        {
            t.gotoXY(40, 20);
            cout << "��Ҳ���";
            t.wait(2000);
            t.clearLine(40, 21);
            return -1;
        }
    }
    return 0;
}

