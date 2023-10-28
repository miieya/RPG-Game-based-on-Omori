#include <iostream>
#include <conio.h>
#include "TitleScreen.h"
#include "WhiteSpace.h"
#include "Illustration.h"
#include "Tool.h"
using namespace std;

//输出标题、菜单选项(最初显示）
void TitleScreen::Menu_Print_First(Tool& t)
{
	//输出标题
	t.gotoXY(54, 3);
	const char* str1 = "O M O R I";
	t.printMessage(str1);

	//输出红色标题
	t.wait(500);
	t.setPrintColor(0x04);
	t.gotoXY(54, 3);
	t.printMessage(str1);

	//变回白色标题
	t.setPrintColor(0x07);
	t.wait(200);
	t.gotoXY(54, 3);
	t.printMessage(str1);

	//输出角色初始位置
	t.wait(300);
	t.gotoXY(58, 3);
	cout << "●";

	//输出菜单
	t.wait(500);
	t.gotoXY(54, 6);
	const char* str2 = "游戏入口";
	const char* str3 = "设置入口";
	const char* str4 = "图鉴入口";
	const char* str5 = "退出入口";
	t.printMessage(str2);
	t.wait(200);
	t.gotoXY(54, 9);
	t.printMessage(str3);
	t.wait(200);
	t.gotoXY(54, 12);
	t.printMessage(str4);
	t.wait(200);
	t.gotoXY(54, 15);
	t.printMessage(str5);
	t.wait(200);
}

//输出标题、菜单选项(快速显示）
void TitleScreen::Menu_Print_After(Tool& t)
{
	t.gotoXY(54, 3);
	cout << "O M O R I" << endl;

	t.wait(300);
	t.gotoXY(58, 3);
	cout << "●";

	t.gotoXY(54, 6);
	cout << "游戏入口" << endl;
	t.gotoXY(54, 9);
	cout << "设置入口" << endl;
	t.gotoXY(54, 12);
	cout << "图鉴入口" << endl;
	t.gotoXY(54, 15);
	cout << "退出入口" << endl;
}

//输出确认页面
void TitleScreen::Confirm_Print_Exit(Tool& t, int judge)
{
	//输出选项
	t.gotoXY(52, 3);
	if (judge == 1)
		cout << "确认进入游戏？" << endl;
	else if (judge == 2)
		cout << "确认进入设置？" << endl;
	else if (judge == 3)
		cout << "确认进入图鉴？" << endl;
	else if (judge == 4)
		cout << "确认退出游戏？" << endl;

	t.gotoXY(56, 6);
	cout << "确认" << endl;
	t.gotoXY(56, 9);
	cout << "取消" << endl;

	//输出角色初始位置
	t.wait(300);
	t.gotoXY(58, 4);
	cout << "●";
}

//显示人物图标(菜单页面）
void TitleScreen::Position_Title(int x0, int y0, int x1, int y1, Tool& t)
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

//判断下一步的数字(菜单地图）
int TitleScreen::ClueJudge_Title(int x1, int y1)
{
	int number = map_Title[y1][x1];
	return number;
}

//判断下一步的数字(确认地图）
int TitleScreen::ClueJudge_Confirm(int x1, int y1)
{
	int number = map_Confirm[y1][x1];
	return number;
}

//行动所处位置判断(菜单地图）
void TitleScreen::Movement_Title(int number, int& x0, int& y0, int x1, int y1, Tool& t)
{
	Illustration i;
	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	switch (number)
	{
	case 0:  //可移动 -- 人物图标变动，并更新位置
		Position_Title(x0, y0, x1, y1, t);
		x0 = x1; 
		y0 = y1;
		break;
	case 1:  //空气墙，不可前进
		break;
	case 2:  //开始游戏入口
		system("cls");
		Execute_Confirm(t, 1, 1);
		break;
	case 3:   //设置入口
		system("cls");
		Execute_Confirm(t, 2, 2);
		break;
	case 4:   //图鉴入口
		system("cls");
		i.Execute(t, 1, 0);
		Execute_Confirm(t, 3, 3);
		break;
	case 5:   //退出入口
		system("cls");
		Execute_Confirm(t, 4, 4);
		break;
	default:
		break;
	}
}

//行动所处位置判断(确认地图）
void TitleScreen::Movement_Confirm(int number, int& x0, int& y0, int x1, int y1, Tool& t, int judge)
{
	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	switch (number)
	{
	case 0:  //可移动 -- 人物图标变动，并更新位置
		Position_Title(x0, y0, x1, y1, t);
		x0 = x1;
		y0 = y1;
		break;
	case 1:  //空气墙，不可前进
		break;
	case 2:  //确认入口
	{ 
		system("cls");
		if (judge == 1) //进入游戏
		{
			t.wait(200);
			WhiteSpace w;
			w.Execute_WhiteSpace(t, 1);
		}
		else if (judge == 2)  //进入设置
		{

		}
		else if (judge == 3)  //进入图鉴
		{

		}
		else if (judge == 4) //退出游戏
		{
			t.gotoXY(47, 3);
			cout << "已退出游戏，欢迎再次游玩." << endl;

			//在下方输出光标
			t.gotoXY(47, 20);
			system("pause");
			exit(0);
		}
		break;
	}
	case 3:   //返回入口
		//清屏后快速输出首页
		system("cls");
		Execute_Title(2);
		break;
	default:
		break;
	}
}

//菜单页面执行
void TitleScreen::Execute_Title(int judge)
{
	Tool t;
	if (judge == 1)
		Menu_Print_First(t);
	else
		Menu_Print_After(t);

	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	int x0 = 7, y0 = 2, x1 = 7, y1 = 2;
	int clue;
	while (1)
	{
		t.sidejudge(x1, y1);
		clue = ClueJudge_Title(x1, y1);
		Movement_Title(clue, x0, y0, x1, y1, t);
		x1 = x0;
		y1 = y0;
	}
}

//确认页面执行
void TitleScreen::Execute_Confirm(Tool& t, int judge1, int judge2)
{
	//judeg1 -- 判断输出进入游戏/进入设置/进入图鉴/退出游戏
	//judge2 -- 判断进入游戏/进入设置/进入图鉴/退出游戏地图

	Confirm_Print_Exit(t, judge1);

	//x0,y0为当前位置，x1,y1为尝试要移动到的位置
	int x0 = 7, y0 = 2, x1 = 7, y1 = 2;
	int clue;
	while (1)
	{
		t.sidejudge(x1, y1);
		clue = ClueJudge_Confirm(x1, y1);
		Movement_Confirm(clue, x0, y0, x1, y1, t, judge2);
		x1 = x0;
		y1 = y0;
	}
}
