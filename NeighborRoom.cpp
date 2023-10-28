#include <iostream>
#include <algorithm>
#include "NeighborRoom.h"
#include "WhiteSpace.h"
#include "Tool.h"
#include "treemap.h"
using namespace std;

int NeighborRoom::cnt = 0;
int NeighborRoom::cnt2 = 0;

void NeighborRoom::Begin_Print(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "Aubrey: 嗨OMORI! 我们正觉得你马上要来呢!";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "        想和我们一起打牌吗?";
	t.printMessage_Quick(str2);
	t.wait(500);
	t.gotoXY(40, 22);
	const char* str3 = "        我们正好快要打完这一局了呢!";
	t.printMessage_Quick(str3);

	t.wait(2000);
	for (int i = 20; i <= 22; i++)
		t.clearLine(40, i);
	t.gotoXY(40, 20);
	const char* str4 = "Aubrey: 啊! 哎呀.....当我没说吧.....";
	t.printMessage_Quick(str4);
	
	t.wait(2000);
	t.clearLine(40, 20);
	t.gotoXY(40, 20);
	const char* str5 = "Kel: 哎呀.....你搞什么呀, Aubrey?!";
	t.printMessage_Quick(str5);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str6 = "     你把牌全都弄乱了嘛!";
	t.printMessage_Quick(str6);
	t.wait(500);
	t.gotoXY(40, 22);
	const char* str7 = "     我明明就快赢了呢。";
	t.printMessage_Quick(str7);

	t.wait(2000);
	for (int i = 20; i <= 22; i++)
		t.clearLine(40, i);
	t.gotoXY(40, 20);
	const char* str8 = "Hero: 好啦好啦, Kel, 没有必要生气呀。";
	t.printMessage_Quick(str8);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str9 = "      嘿, OMORI, 我们今天也一起出去玩吧!";
	t.printMessage_Quick(str9);

	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::map_Print(Tool& t)
{
	t.gotoXY(40, 5);
	cout << "墙墙墙墙墙墙墙墙墙墙墙墙墙墙墙墙墙墙";
	t.gotoXY(40, 17);
	cout << "墙墙墙墙墙墙墙墙门墙墙墙墙墙墙墙墙墙";
	t.gotoXY(44, 6);
	cout << "照片";
	t.gotoXY(50, 6);
	cout << "枕头";
	t.gotoXY(44, 10);
	cout << "桌桌";
	t.gotoXY(44, 11);
	cout << "桌桌";

	t.setPrintColor(0x0E);
	t.gotoXY(58, 10);
	cout << "●";
	t.setPrintColor(0x05);
	t.gotoXY(56, 11);
	cout << "●";
	t.setPrintColor(0x03);
	t.gotoXY(54, 10);
	cout << "●";
	t.setPrintColor(0x07);
	t.gotoXY(56, 16);
	cout << "●";

	t.gotoXY(66, 12);
	cout << "洞";
	t.gotoXY(62, 15);
	cout << "电视";

	for (int i = 6; i <= 16; i++)
	{
		t.gotoXY(40, i);
		cout << "墙";
		t.gotoXY(74, i);
		cout << "墙";
	}

	t.gotoXY(70, 6);
	cout << "楼梯";
	t.gotoXY(70, 7);
	cout << "楼梯";
	t.gotoXY(72, 8);
	cout << "蛇";
}

void NeighborRoom::Photo(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "一张熟悉的人的照片。";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::Pillow(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "一个松软的枕头,形状是一个女孩子的头。";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::Hole(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "一个猫形的洞。";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::TV(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "电视上放着一部电影。";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "四个男孩在铁路轨道上走着。";
	t.printMessage_Quick(str2);

	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::Snack(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "嘶嘶嘶嘶嘶嘶嘶.....？";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::Aubrey(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "Aubrey: OMORI! 我就知道我可以依靠你!";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "        你就是最棒的。";
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::Kel(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "Kel: 哎~~~~呀....";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "     Aubrey总是想要怎么样就能怎么样。";
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::Hero(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "Hero: 嘿OMORI, 能见到你真是太好了。";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "      这两个人呀, 总是彼此之间闹别扭。";
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::door_choose(Tool& t)
{
	WhiteSpace s;
	t.gotoXY(40, 20);
	const char* str1 = "一扇白色的门投下了淡淡的影子。";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "你想要做些什么?";
	t.printMessage_Quick(str2);

	t.wait(200);
	t.gotoXY(40, 23);
	cout << "打开门     (Y键)";
	t.gotoXY(40, 24);
	cout << "什么也不做 (N键)";

	char choose;
	while (true)
	{
		t.gotoXY(57, 24);
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

			NeighborRoom n;
			switch (choose)
			{
			case 'Y':  //出门
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				s.Execute_WhiteSpace(t, 0);
				break;
			case 'y':  //同'Y'
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				s.Execute_WhiteSpace(t, 0);
				break;
			case 'N':  //什么都不做
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
				break;
			case 'n':  //同'N'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
				break;
			default:
				throw std::runtime_error("输入有误,请重新输入！");
			}
		}

		catch (const std::exception& e)
		{
			cin.clear(); // 清除错误状态
			cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误的输入

			//覆盖
			t.clearLine(40, 23);
			t.clearLine(40, 24);
			t.gotoXY(40, 23);
			cout << e.what() << endl;
			t.wait(500);
			t.clearLine(40, 23);
			door_choose(t);
		}
	}
}

void NeighborRoom::stair_choose(Tool& t, treemap& s)
{
	t.gotoXY(40, 21);
	const char* str2 = "你想要出门吗?";
	t.printMessage_Quick(str2);

	t.wait(200);
	t.gotoXY(40, 23);
	cout << "打开门     (Y键)";
	t.gotoXY(40, 24);
	cout << "什么也不做 (N键)";

	char choose;
	while (true)
	{
		t.gotoXY(57, 24);
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

			switch (choose)
			{
			case 'Y':  //出门
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				if (cnt == 0)
				{
					NeighborRoom::cnt++;
					s.Execute_treemap(t, 1, 1);

				}
				else
				{
					if (s.ifSuccess == -1)
						s.Execute_treemap(t, 0, 1);
					else
						s.Execute_treemap(t, 0, 2);
				}
				break;
			case 'y':  //同'Y'
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				if (cnt == 0)
				{
					NeighborRoom::cnt++;
					s.Execute_treemap(t, 1, 1);

				}
				else
				{
					if (s.ifSuccess == -1)
						s.Execute_treemap(t, 0, 1);
					else
						s.Execute_treemap(t, 0, 2);
				}	
				break;
			case 'N':  //什么都不做
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
				break;
			case 'n':  //同'N'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
				break;
			default:
				throw std::runtime_error("输入有误,请重新输入！");
			}
		}

		catch (const std::exception& e)
		{
			cin.clear(); // 清除错误状态
			cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误的输入

			//覆盖
			t.clearLine(40, 23);
			t.clearLine(40, 24);
			t.gotoXY(40, 23);
			cout << e.what() << endl;
			t.wait(500);
			t.clearLine(40, 23);
			door_choose(t);
		}
	}
}

void NeighborRoom::Position(int x0, int y0, int x1, int y1, Tool& t)
{
	if (x0 != x1 || y0 != y1)
	{
		t.gotoXY(40 + 2 * x0, 5 + y0);
		cout << "  ";
		t.gotoXY(40 + 2 * x1, 5 + y1);
		cout << "●";
	}
}

int NeighborRoom::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

void NeighborRoom::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t)
{
	treemap tree;
	WhiteSpace s;
	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	switch (number)
	{
	case 0:  //可移动 -- 人物图标变动，并更新位置
		Position(x0, y0, x1, y1, t);
		x0 = x1;
		y0 = y1;
		break;
	case 1:  //空气墙，不可前进
		break;
	case 2:  //照片
		Photo(t);
		break;
	case 3:  //枕头
		Pillow(t);
		break;
	case 4:  //洞
		Hole(t);
		break;
	case 5:  //电视
		TV(t);
		break;
	case 6:  //楼梯
		stair_choose(t, tree);
		break;
	case 7:  //蛇
		Snack(t);
		break;
	case 8: //门
		door_choose(t);
		break;
	case 9:
		Aubrey(t);
		break;
	case 10:
		Kel(t);
		break;
	case 11:
		Hero(t);
		break;
	default:
		break;
	}
}

void NeighborRoom::Execute_NeighborRoom(Tool& t, int judge)
{
	map_Print(t);

	if (judge == 1)
	{
		t.wait(1000);
		Begin_Print(t);
	}

	t.gotoXY(57, 16);
	int x0 = 8, y0 = 11, x1 = 8, y1 = 11;
	int clue;

	while (1)
	{
		t.sidejudge(x1, y1);
		clue = ClueJudge(x1, y1);
		Movement(clue, x0, y0, x1, y1, t);
		x1 = x0;
		y1 = y0;
	}
}