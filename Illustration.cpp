#include <iostream>
#include "Illustration.h"
#include "Tool.h"
#include "TitleScreen.h"
using namespace std;

//输出图鉴标题(最先）
void Illustration::Header_Print01(Tool& t)
{
	t.gotoXY(53, 2);
	cout << "┋敌人档案室┋";
	t.gotoXY(45, 4);
	cout << "出";
	t.gotoXY(45, 5);
	cout << "口";
	t.gotoXY(73, 4);
	cout << "书";
	t.gotoXY(73, 5);
	cout << "架";
	t.gotoXY(58, 4);
	cout << "●";

	t.gotoXY(54, 12);
	cout << "1.森林兔兔";
	t.gotoXY(54, 13);
	cout << "2.树苗鼹鼠";
	t.gotoXY(54, 14);
	cout << "3.混音带";
	t.gotoXY(54, 15);
	cout << "4.毁灭音箱";
}

//输出图鉴标题(查看页面）
void Illustration::Header_Print02(Tool& t, int judge) 
{
	t.gotoXY(53, 2);
	cout << "┋敌人档案室┋";
	t.gotoXY(45, 4);
	cout << "出";
	t.gotoXY(45, 5);
	cout << "口";
	t.gotoXY(58, 4);
	cout << "●";

	//判断输出哪个敌人信息
	switch (judge)
	{
	case 1:
		ForestBunny(t);
		break;
	case 2:
		SproutMole(t);
		break;
	case 3:
		Mixtape(t);
		break;
	case 4:
		DoomBox(t);
		break;
	default:
		break;
	}
}

//选择查看敌人
void Illustration::Select(Tool& t)
{
	t.gotoXY(48, 8);
	cout << "你想了解哪个敌人的信息呢？";
	t.gotoXY(48, 9);
	cout << "输入序号：";

	int choose;
	while (true)
	{
		try {
			if (!(cin >> choose)) //判断是否为int型
			{
				throw std::runtime_error("输入有误,请重新输入！");
			}

			if (choose < 1 || choose > 4)  //判断输入数字是否在范围内
			{
				throw std::runtime_error("输入有误,请重新输入！");
			}

			switch (choose)
			{
			case 1: //森林兔兔
				system("cls");
				Execute(t, 2, 1);
				break;
			case 2: //树苗鼹鼠
				system("cls");
				Execute(t, 2, 2);
				break;
			case 3: //混音带
				system("cls");
				Execute(t, 2, 3);
				break;
			case 4: //毁灭音箱
				system("cls");
				Execute(t, 2, 4);
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
			t.clearLine(48, 8);
			t.clearLine(48, 9);
			t.gotoXY(50, 8);
			cout << e.what() << endl;
			t.wait(500);
			Select(t);
		}
	}
}

//显示人物图标
void Illustration::Position(int x0, int y0, int x1, int y1, Tool& t)
{
	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	if (x0 != x1 || y0 != y1)
	{
		t.gotoXY(44 + 2 * x0, 2 + y0);  //可以移动，原本位置被空格覆盖
		cout << "  ";
		t.gotoXY(44 + 2 * x1, 2 + y1);  //新位置显示人物图标
		cout << "●";
	}
}

//判断下一步的数字
int Illustration::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//行动所处位置判断
void Illustration::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t, int judge)
{
	TitleScreen x;
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
	case 2:  //返回入口
		system("cls");
		if (judge == 1)  //主图鉴返回菜单页面
			x.Execute_Title(2);
		else             //副图鉴返回主图鉴页面
			Execute(t, 1, 0);
		break;
	case 3:   
		if (judge == 1) //查看图鉴
			Select(t);
		else  //图鉴内部页面无查看选项
			break;
		break;
	default:
		break;
	}
}

//图鉴页面执行
void Illustration::Execute(Tool& t, int judge1, int judge2)
{
	if (judge1 == 1)
		Header_Print01(t);
	else
		Header_Print02(t,judge2);

	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	int x0 = 7, y0 = 2, x1 = 7, y1 = 2;
	int clue;
	while (1)
	{
		t.sidejudge(x1, y1);
		clue = ClueJudge(x1, y1);
		Movement(clue, x0, y0, x1, y1, t, judge1);
		x1 = x0;
		y1 = y0;
	}
}

//森林兔兔
void Illustration::ForestBunny(Tool& t)
{
	t.gotoXY(54, 8);
	cout << "森林兔兔";
	t.gotoXY(51, 10);
	cout << "毛绒绒的可爱生物";
	t.gotoXY(51, 11);
	cout << "也可能在毫无预警的";
	t.gotoXY(51, 12);
	cout << "情况下袭击人类....";
	t.gotoXY(51, 14);
	cout << "----OMORI";

	t.gotoXY(51, 17);
	cout << "我觉得应该会是相当";
	t.gotoXY(51, 18);
	cout << "可爱的宠物呢！";
	t.gotoXY(51, 20);
	cout << "----奥布里";
}

void Illustration::SproutMole(Tool& t)
{
	t.gotoXY(56, 8);
	cout << "树苗鼹鼠";
	t.gotoXY(51, 10);
	cout << "危险而且带有敌意的丑陋";
	t.gotoXY(51, 11);
	cout << "植物生物, 它会说自己很";
	t.gotoXY(51, 12);
	cout << "聪明, 但不要相信它, 它";
	t.gotoXY(51, 13);
	cout << "一点都不聪明, 闻起来还";
	t.gotoXY(51, 14);
	cout << "是脏衣服的味道。";
	t.gotoXY(51, 16);
	cout << "----OMORI";
}

//混音带
void Illustration::Mixtape(Tool& t)
{
	t.gotoXY(56, 8);
	cout << "混音带";
	t.gotoXY(51, 10);
	cout << "过往时代的遗物......";
	t.gotoXY(51, 11);
	cout << "虽然它很快就要退出历史";
	t.gotoXY(51, 12);
	cout << "舞台了, 但看起来它还是";
	t.gotoXY(51, 13);
	cout << "很开心的样子。";
	t.gotoXY(51, 15);
	cout << "----OMORI";

	t.gotoXY(51, 18);
	cout << "我过去还有一阵子挺喜欢";
	t.gotoXY(51, 19);
	cout << "收集这些东西的！原来它";
	t.gotoXY(51, 20);
	cout << "们都跑到这里来了啊....";
	t.gotoXY(51, 22);
	cout << "----英雄";
}

void Illustration::DoomBox(Tool& t)
{
	t.gotoXY(54, 8);
	cout << "毁灭音箱";
	t.gotoXY(51, 10);
	cout << "这是手提音箱死后复活的";
	t.gotoXY(51, 11);
	cout << "怨灵, 它在生前是一种用";
	t.gotoXY(51, 12);
	cout << "来大声传送噪音的工具。";
	t.gotoXY(51, 14);
	cout << "----OMORI";
}

