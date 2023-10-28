#include"treemap.h"
#include"buy menu.h"
#include "NeighborRoom.h"
#include "Fight.h"
#include<iostream>
using namespace std;

int treemap::ifSuccess = -1;

void treemap::Begin_Print(Tool& t)
{
	const char* str1 = "第    一    章";
	const char* str2 = "辽  阔  森  林";

	t.gotoXY(50, 5);
	t.printMessage(str1);
	t.wait(2000);
	//system("cls");
	t.gotoXY(50, 7);
	t.printMessage(str2);
	t.wait(1000);
	system("cls");
}

void treemap::map_Print(Tool& t, int judge)
{
	t.gotoXY(40, 5);

	for (int i = 0; i < 19; i++)
		cout << "树";
	cout << endl;

	for (int i = 9, m = 11, s = 1; i > 0; i--)
	{
		t.gotoXY(40, 5 + s);
		for (int j = 0; j < i; j++)
			cout << "树";
		for (int k = 0; k < m - i; k++)
			cout << " ";
		for (int t = 0; t < i; t++)
			cout << "树";
		cout << endl;
		m += 3;
		s++;
	}

	for (int i = 2, m = 34, s = 1; i < 10; i++)
	{
		t.gotoXY(40, 14 + s);
		for (int j = 0; j < i; j++)
			cout << "树";
		for (int k = 0; k < m - i - 2; k++)
			cout << " ";
		for (int t = 0; t < i; t++)
			cout << "树";
		cout << endl;
		m -= 3;
		s++;
	}
	t.gotoXY(40, 23);
	for (int i = 0; i < 19; i++)
		cout << "树";
	cout << endl;


	t.gotoXY(50, 15);
	cout << "邮箱";

	t.gotoXY(66, 13);
	cout << "拼图";

	if (judge == 1)
	{
		t.gotoXY(52, 11);
		t.setPrintColor(0x04);
		cout << "●";
		t.setPrintColor(0x07);
	}

	/*t.gotoXY(57, 22);
	cout << "门";*/
}

void treemap::mailbox(Tool& t)
{
	t.gotoXY(40, 25);
	const char* str1 = "没错！没错！尊贵的客人……";
	t.printMessage_Quick(str1);
	t.wait(500);
	//t.clearLine(40, 25);

	t.gotoXY(40, 26);
	const char* str2 = "欢迎来到我的小店！请随便看看！嘻嘻嘻……";
	t.printMessage_Quick(str2);
	t.wait(1000);
	//t.clearLine(40, 25);

	mailbox_choose(t);
}

void treemap::mailbox_choose(Tool& t)
{
	t.gotoXY(40, 27);
	cout << "购买 (Y键)";
	t.gotoXY(40, 28);
	cout << "离开 (N键)";

	char choose;
	while (true)
	{
		t.gotoXY(50, 27);
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
			BuyMenu v;
			switch (choose)
			{
			case 'Y':  //购买零食or玩具
				//覆盖提问
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 25 + i);
				}
				system("cls");
				v.Execute_buymenu(t, 0, fight);
				t.gotoXY(40, 25);

				//一段时间后，清除提问和人物图标重新进入地图
				t.wait(2000);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);

				if (ifSuccess == -1)
					Execute_treemap(t, 0, 1);
				else
					Execute_treemap(t, 0, 2);
				break;
			case 'y':  //同'Y'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 25 + i);
				}
				system("cls");
				v.Execute_buymenu(t, 0, fight);
				t.gotoXY(40, 25);
				t.wait(2000);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);

				if (ifSuccess == -1)
					Execute_treemap(t, 0, 1);
				else
					Execute_treemap(t, 0, 2);
				break;
			case 'N':  //离开
				//立即清除提问和人物图标重新进入地图
				for (int i = 0; i <= 3; i++)
				{
					t.clearLine(40, 25 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				if (ifSuccess == -1)
					Execute_treemap(t, 0, 1);
				else
					Execute_treemap(t, 0, 2);
				break;
			case 'n':  //同'N'
				for (int i = 0; i <= 3; i++)
				{
					t.clearLine(40, 25 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				if (ifSuccess == -1)
					Execute_treemap(t, 0, 1);
				else
					Execute_treemap(t, 0, 2);
				break;
			default:
				throw std::runtime_error("输入有误,请重新输入！");
			}
		}

		catch (const std::exception& e)
		{
			cin.clear(); // 清除错误状态
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误的输入

			//覆盖
			t.clearLine(40, 25);
			t.clearLine(40, 26);
			t.gotoXY(40, 25);
			cout << e.what() << endl;
			t.wait(500);
			t.clearLine(40, 25);
			mailbox_choose(t);
		}
	}
}

void treemap::Jigsaw(Tool& t)
{
	t.gotoXY(40, 25);
	const char* str1 = "一些破碎的拼图……";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 25);
}

void treemap::ForestRabbit(Tool& t)
{
	t.gotoXY(40, 25);
	const char* str1 = "森林兔兔！开启战斗模式";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 25);
}

void treemap::Position(int x0, int y0, int x1, int y1, Tool& t)
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

void treemap::door_choose(Tool& t)
{
	NeighborRoom s;
	/*t.gotoXY(40, 20);
	const char* str1 = "。";
	t.printMessage_Quick(str1);*/
	t.gotoXY(40, 25);
	const char* str2 = "你想要回去吗?";
	t.printMessage_Quick(str2);

	t.wait(200);
	t.gotoXY(40, 26);
	cout << "打开门     (Y键)";
	t.gotoXY(40, 27);
	cout << "什么也不做 (N键)";

	char choose;
	while (true)
	{
		t.gotoXY(57, 27);
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
				s.Execute_NeighborRoom(t, 0);
				break;
			case 'y':  //同'Y'
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				s.Execute_NeighborRoom(t, 0);
				break;
			case 'N':  //什么都不做
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 25 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				if (ifSuccess == -1)
					Execute_treemap(t, 0, 1);
				else
					Execute_treemap(t, 0, 2);
				break;
			case 'n':  //同'N'
				for (int i = 0; i <= 3; i++)
				{
					t.clearLine(40, 25 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				if (ifSuccess == -1)
					Execute_treemap(t, 0, 1);
				else
					Execute_treemap(t, 0, 2);
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

//判断下一步的数字
int treemap::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//行动所处位置判断
void treemap::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t)
{
	NeighborRoom n;
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
	case 2:
		mailbox(t);
		break;
	case 3:
		Jigsaw(t);
		break;
	case 4:
		ForestRabbit(t);
		t.wait(500);
		system("cls");

		ifSuccess = fight.Level_01();
		t.wait(3000);
		system("cls");
		if (ifSuccess == -1) //失败
			Execute_treemap(t, 0, 1);
		else //成功,删除敌人
		{
			map[6][6] = 0;
			Execute_treemap(t, 0, 2);
		}
		break;
	case 5: //门
		door_choose(t);
		break;
	default:
		break;
	}
}

//执行函数
void treemap::Execute_treemap(Tool& t, int judge1, int judge2)
{
	//judge==1时为最初页面，其余为选项返回，重新进入地图情况
	if (judge1 == 1)
	{
		Begin_Print(t);
	}

	//judge==1为战斗前,judge==2为战斗胜利后
	if (judge2 == 1)
		map_Print(t, 1);
	else
		map_Print(t, 2);

	t.gotoXY(28, 11);
	int x0 = 5, y0 = 6, x1 = 9, y1 = 16;
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