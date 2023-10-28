#include<windows.h>
#include"buy menu.h"
#include"treemap.h"
#include<iostream>
using namespace std;

//Pack BuyMenu::MyPack;

void BuyMenu::map_Print(Tool& t, Fight& fight)
{
	t.gotoXY(40, 5);
	cout << "欢迎你，尊贵的顾客！";
	t.gotoXY(42, 7);
	cout << "你想要购买什么？               金币: " << fight.MyPack.GoldCoin;
	t.gotoXY(46, 9);
	cout << "零食";
	t.gotoXY(46, 10);
	cout << "豆腐       2金币";
	t.gotoXY(46, 11);
	cout << "糖果      20金币";
	t.gotoXY(46, 12);
	cout << "梅子汁     5金币";
	t.gotoXY(46, 13);
	cout << "面包果汁  20金币";
	t.gotoXY(46, 15);
	cout << "玩具";
	t.gotoXY(46, 16);
	cout << "五彩纸片  50金币";
	t.gotoXY(46, 17);
	cout << "雨云      50金币";
	t.gotoXY(46, 18);
	cout << "空气喇叭  50金币";

	for (int i = 0; i < 4; ++i)
	{
		t.gotoXY(68, 10 + i);
		cout << "查看";
		t.gotoXY(76, 10 + i);
		cout << "购买";
	}

	for (int i = 0; i < 3; i++)
	{
		t.gotoXY(68, 16 + i);
		cout << "查看";
		t.gotoXY(76, 16 + i);
		cout << "购买";
	}
}

void BuyMenu::tofu(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "豆腐";
	const char* str2 = "吃起来没什么味道……";
	const char* str3 = "恢复5点HP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::candy(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "糖果";
	const char* str2 = "小朋友最喜欢的零食。甜甜的！";
	const char* str3 = "恢复30点HP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::pulm_juice(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "梅子汁";
	const char* str2 = "酸酸甜甜的！真好喝！";
	const char* str3 = "恢复15点MP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::breadfruit_juice(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "面包果汁";
	const char* str2 = "对于魔法值的恢复有奇效！快来试试吧！";
	const char* str3 = "恢复50点MP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::confetti(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "五彩祥云";
	const char* str2 = "让所有队友变得开心";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
}

void BuyMenu::rain_cloud(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "雨云";
	const char* str2 = "让所有队友变得悲伤";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
}

void BuyMenu::air_horn(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "空气喇叭";
	const char* str2 = "让所有队友变得生气";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
}

void BuyMenu::buytofu(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 0, fight.MyPack);
	//shop.InShopping(1, 1, MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "你想买多少个？";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "这些东西一共是";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 2 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "金币";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buycandy(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 1, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "你想买多少个？";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "这些东西一共是";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 20 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "金币";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buypulm_juice(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 4, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "你想买多少个？";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "这些东西一共是";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 5 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "金币";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buybreadfruit_juice(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 5, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "你想买多少个？";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "这些东西一共是";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 20 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "金币";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buyconfetti(Tool& t, Fight& fight)
{
	fight.goods->InShopping(2, 1, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "你想买多少个？";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "这些东西一共是";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 50 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "金币";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buyrain_cloud(Tool& t, Fight& fight)
{
	fight.goods->InShopping(2, 3, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "你想买多少个？";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "这些东西一共是";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 50 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "金币";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buyair_horn(Tool& t, Fight& fight)
{
	fight.goods->InShopping(2, 5, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "你想买多少个？";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "这些东西一共是";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 50 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "金币";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buy_choose(Tool& t, Fight& fight)
{
	t.gotoXY(40, 22);
	const char* str1 = "还要继续买吗？";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 23);
	cout << "再买点 (Y键)";
	t.gotoXY(40, 24);
	cout << "不买了 (N键)";

	char choose;
	while (true)
	{
		t.gotoXY(50, 25);
		try {
			if (!(cin >> choose)) //判断是否为char型
			{
				throw std::runtime_error("输入有误,请重新输入！");
			}

			//判断输入字母是否在范围内
			if (!(choose == 'Y' || choose == 'y' || choose == 'N' || choose == 'n'))
			{
				throw std::runtime_error("输入有误,请重新输入！");
			}
			treemap v;
			switch (choose)
			{
			case 'Y':  //继续购买
				//覆盖提问
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 22 + i);
				}
				t.gotoXY(40, 25);

				//一段时间后，清除提问和人物图标重新进入地图
				t.wait(200);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);
				system("cls");
				Execute_buymenu(t, 0, fight);
				break;
			case 'y':  //同'Y'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 21 + i);
				}
				t.gotoXY(40, 25);
				t.wait(200);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);
				system("cls");
				Execute_buymenu(t, 0, fight);
				break;
			case 'N':  //离开
				//立即清除提问和人物图标重新进入地图
				for (int i = 0; i <= 3; i++)
				{
					t.clearLine(40, 22 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				system("cls");
				if (v.ifSuccess == -1)
					v.Execute_treemap(t, 0, 1);
				else
					v.Execute_treemap(t, 0, 2);
				break;
			case 'n':  //同'N'
				for (int i = 0; i <= 3; i++)
				{
					t.clearLine(40, 21 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				system("cls");
				if (v.ifSuccess == -1)
					v.Execute_treemap(t, 0, 1);
				else
					v.Execute_treemap(t, 0, 2);
				break;
			default:
				throw std::runtime_error("输入有误,请重新输入！");
			}
		}

		catch (const std::exception& e)
		{
			cin.clear(); // 清除错误状态
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误的输入

			//覆盖
			t.clearLine(40, 25);
			t.clearLine(40, 26);
			t.gotoXY(40, 25);
			cout << e.what() << endl;
			t.wait(500);
			t.clearLine(40, 25);
			buy_choose(t,fight);
		}
	}
}

void BuyMenu::Position(int x0, int y0, int x1, int y1, Tool& t)
{
	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	if (x0 != x1 || y0 != y1)
	{
		t.gotoXY(40 + 2 * x0, 5 + y0);  //可以移动，原本位置被空格覆盖
		cout << "  ";
		t.gotoXY(40 + 2 * x1, 5 + y1);  //新位置显示人物图标
		cout << "●";
	}
}

//判断下一步的数字
int BuyMenu::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//行动所处位置判断
void BuyMenu::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t, Fight& fight)
{
	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	switch (number)
	{
	case 0:  //可移动 -- 人物图标变动，并更新位置
		Position(x0, y0, x1, y1, t);
		x0 = x1;
		y0 = y1;
		break;
	case 1:
		break;
	case 2:
		tofu(t);
		break;
	case 3:
		candy(t);
		break;
	case 4:
		pulm_juice(t);
		break;
	case 5:
		breadfruit_juice(t);
		break;
	case 6:
		confetti(t);
		break;
	case 7:
		rain_cloud(t);
		break;
	case 8:
		air_horn(t);
		break;
	case 12:
		buytofu(t, fight);
		break;
	case 13:
		buycandy(t, fight);
		break;
	case 14:
		buypulm_juice(t, fight);
		break;
	case 15:
		buybreadfruit_juice(t, fight);
		break;
	case 16:
		buyconfetti(t, fight);
		break;
	case 17:
		buyrain_cloud(t, fight);
		break;
	case 18:
		buyair_horn(t, fight);
		break;
	default:
		break;
	}
}

//执行函数
void BuyMenu::Execute_buymenu(Tool& t, int judge, Fight& fight)
{
	//judge==1时为最初页面，其余为选项返回，重新进入地图情况
	if (judge == 1)
	{
		t.wait(1000);
	}

	map_Print(t, fight);

	t.gotoXY(28, 11);
	int x0 = 5, y0 = 6, x1 = 9, y1 = 17;
	int clue;

	while (1)
	{
		t.sidejudge(x1, y1);
		clue = ClueJudge(x1, y1);
		Movement(clue, x0, y0, x1, y1, t, fight);
		x1 = x0;
		y1 = y0;
	}
}