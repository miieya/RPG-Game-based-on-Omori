#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <Windows.h>
#include "WhiteSpace.h"
#include "NeighborRoom.h"
#include "Tool.h"
using namespace std;

//进入游戏首界面输出
void WhiteSpace::Begin_Print(Tool& t)
{
	const char* str1 = "欢 迎 来 到 白 色 空 间";
	const char* str2 = "从你有记忆时开始";
	const char* str3 = "你就一直躺在这里";
	const char* str4 = ". . . . . . . .";
	t.gotoXY(45, 6);
	t.printMessage(str1);
	t.wait(2000);
	system("cls");
	t.gotoXY(50, 6);
	t.printMessage(str2);
	t.wait(500);
	t.gotoXY(50, 7);
	t.printMessage(str3);
	t.wait(2000);
	system("cls");
	t.gotoXY(54, 6);
	t.printMessage(str4);
	t.wait(2000);
	system("cls");

	//设置白底黑字
	t.setPrintColor_FrontBack(30, 47);
	//白屏显示
	t.FullScreen();

}

//输出地图
void WhiteSpace::map_Print(Tool& t)
{
	t.setPrintColor_FrontBack(30, 47);
	t.gotoXY(44, 5);
	cout << "门 ";
	t.gotoXY(58, 6);
	cout << "灯泡";
	t.gotoXY(44, 9);
	cout << "      电脑            画本";
	t.gotoXY(50, 11);
	cout << "●";
	t.gotoXY(64, 14);
	cout << "纸巾盒";
	t.gotoXY(50, 16);
	cout << "喵呜";

	for (int i = 0; i <= 5; i++)
	{
		t.gotoXY(60, i);
		cout << "┊";
	}
}

//电脑
void WhiteSpace::Computer(Tool& t, int judge)
{
	//judge=1,为首先打开电脑页面  judge=2，为选择返回电脑页面
	if (judge == 1)
	{
		t.gotoXY(40, 20);
		const char* str1 = "你启动了你的笔记本电脑。";
		t.printMessage_Quick(str1);
		t.wait(1000);
		system("cls");

		Computer_Print(t);
		//逐字输出
		t.gotoXY(26, 23);
		const char* str2 = "你想要做些什么?";
		t.printMessage_Quick(str2);
	}
	
	if (judge == 0)
	{
		//输出电脑屏幕
		Computer_Print(t);
		t.gotoXY(26, 23);
		cout << "你想要做些什么?";
	}
	
	//首次打开有延迟
	if(judge==1)
		t.wait(200);
	Computer_Choose(t);
}

void WhiteSpace::Computer_Choose(Tool& t)
{
	t.gotoXY(26, 25);
	cout << "(1)盯着屏幕";
	t.gotoXY(26, 26);
	cout << "(2)打开你的日记";
	t.gotoXY(26, 27);
	cout << "(3)登出";

	int choose;
	while (true)
	{
		t.gotoXY(35, 27);
		try {
			if (!(cin >> choose)) //判断是否为int
			{
				throw std::runtime_error("输入有误,请重新输入！");
			}

			//判断输入数字是否在范围内
			if (choose < 1 || choose > 3)
			{
				throw std::runtime_error("输入有误,请重新输入！");
			}

			//覆盖选项文字
			for (int i = 23; i <= 27; i++)
			{
				t.clearLine(26, i);
			}
			
			const char* str1 = "你盯着屏幕";
			switch (choose)
			{
			case 1: 
				t.wait(100);
				t.gotoXY(26, 23);
				t.printMessage_Quick(str1);
				t.wait(1500);
				//覆盖文字后返回电脑主页面
				t.clearLine(26, 23);
				Computer(t,0);
				break;
			case 2:
				t.wait(200);
				Computer_Print_Diary(t);
				t.wait(3000);
				//覆盖日记内容
				t.clear(25, 2, 75, 20);
				Computer(t, 0);
				break;
			case 3: 
				//覆盖文字后返回白色空间
				system("cls");
				Execute_WhiteSpace(t, 0);
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

			//覆盖选择文字
			for (int i = 23; i <= 27; i++)
			{
				t.clearLine(26, i);
			}
			t.gotoXY(26, 23);
			cout << e.what() << endl;
			t.wait(500);
			//覆盖错误提示并返回电脑主界面
			t.clearLine(26, 23);
			Computer(t, 0);
		}
	}

}

//输出电脑屏幕
void WhiteSpace::Computer_Print(Tool& t)
{
	//输出电脑屏幕框
	t.gotoXY(24, 1);
	cout << "┌";
	for (int i = 0; i < 70; ++i)
		cout << "─";
	cout << "┐";

	t.gotoXY(24, 21);
	cout << "└";
	for (int i = 0; i < 70; ++i)
		cout << "─";
	cout << "┘";

	for (int i = 2; i <= 20; ++i)
	{
		t.gotoXY(24, i);
		cout << "│";
		t.gotoXY(95, i);
		cout << "│";
	}

	// "Start"按键
	t.gotoXY(26, 18);
	cout << "┌─────┐";
	t.gotoXY(26, 19);
	cout << "│Start│";
	t.gotoXY(26, 20);
	cout << "└─────┘";

	// "0:00AM"按键
	t.gotoXY(86, 18);
	cout << "┌──────┐";
	t.gotoXY(86, 19);
	cout << "│0:00AM│";
	t.gotoXY(86, 20);
	cout << "└──────┘";

	t.gotoXY(26, 23);
	const char* str1 = "你想要做些什么?";
	t.printMessage_Quick(str1);
}

//输出电脑日记
void WhiteSpace::Computer_Print_Diary(Tool& t)
{
	t.gotoXY(26, 2);
	cout << "OMORI的日记";

	int startX = 25;
	int startY = 3;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			int x = startX + col * 35;
			int y = startY + row * 5;
			t.gotoXY(x, y);
			cout << "┌────────────────────────────────┐";
			t.gotoXY(x, y + 1);
			cout << "│第???天                         │";
			t.gotoXY(x, y + 2);
			cout << "│今天,我呆在白色空间里,一切都很好│";
			t.gotoXY(x, y + 3);
			cout << "│今天,我去找朋友玩,一切都很好    │";
			t.gotoXY(x, y + 4);
			cout << "└────────────────────────────────┘";
		}
	}
}

//画本
void WhiteSpace::ArtBook(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "你的绘画本, 上面画满了你的涂鸦。";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

//纸巾盒
void WhiteSpace::TissueBox(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "一个纸巾盒, 用来拭去你的悲伤。";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

//喵呜
void WhiteSpace::Cat(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "喵？(正在等待某件事情的发生吗?)";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

//灯泡
void WhiteSpace::Bulb(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "从不知何处的天花板上悬挂下来的灯泡";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "要往灯泡里看吗？";
	t.printMessage_Quick(str2);

	t.wait(200);
	Bulb_Choose(t);
}

//灯泡选项
void WhiteSpace::Bulb_Choose(Tool& t)
{
	t.gotoXY(40, 23);
	cout << "是 (Y键)";
	t.gotoXY(40, 24);
	cout << "否 (N键)";

	char choose;
	while (true)
	{
		t.gotoXY(50, 24);
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

			const char* str1 = "里面漆黑一片。你什么也看不见。";
			switch (choose)
			{
			case 'Y':  //往灯泡里看
				//覆盖提问
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				//输出str1
				t.gotoXY(40, 20);
				t.printMessage_Quick(str1);
				//一段时间后，清除提问和人物图标重新进入地图
				t.wait(2000);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);
				Execute_WhiteSpace(t, 0);
				break;
			case 'y':  //同'Y'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(40, 20);
				t.printMessage_Quick(str1);
				t.wait(2000);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);
				Execute_WhiteSpace(t, 0);
				break;
			case 'N':  //不看
				//立即清除提问和人物图标重新进入地图
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				Execute_WhiteSpace(t, 0);
				break;
			case 'n':  //同'N'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				Execute_WhiteSpace(t, 0);
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
			Bulb_Choose(t);
		}
	}
}

//门
void WhiteSpace::Door(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "一扇白色的门投下了淡淡的影子。";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "你想要做些什么?";
	t.printMessage_Quick(str2);

	t.wait(200);
	Door_Choose(t);
}

//门的选项
void WhiteSpace::Door_Choose(Tool& t)
{
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
				if (n.cnt2 == 0)
				{
					n.Execute_NeighborRoom(t, 1);
					n.cnt2++;
				}
				else
					n.Execute_NeighborRoom(t, 0);
				break;
			case 'y':  //同'Y'
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				if (n.cnt2 == 0)
				{
					n.Execute_NeighborRoom(t, 1);
					n.cnt2++;
				}
				else
					n.Execute_NeighborRoom(t, 0);
				break;
			case 'N':  //什么都不做
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				/*t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);*/
				t.gotoXY(44, 5);
				cout << " ";
				Execute_WhiteSpace(t, 0);
				break;
			case 'n':  //同'N'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				/*t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);*/
				t.gotoXY(44, 5);
				cout << " ";
				Execute_WhiteSpace(t, 0);
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
			Door_Choose(t);
		}
	}
}

//显示人物图标
void WhiteSpace::Position(int x0, int y0, int x1, int y1, Tool& t)
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
int WhiteSpace::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//行动所处位置判断
void WhiteSpace::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t)
{
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
	case 2:  //电脑
		Computer(t, 1);
		break;
	case 3:  //画本
		ArtBook(t);
		break;
	case 4:  //纸巾盒
		TissueBox(t);
		break;
	case 5:  //喵呜
		Cat(t);
		break;
	case 6:  //灯泡
		Bulb(t);
		break;
	case 7:  //门
		Door(t);
		break;
	default:
		break;
	}
}

//执行函数
void WhiteSpace::Execute_WhiteSpace(Tool& t, int judge)
{
	//judge==1时为最初页面，其余为选项返回，重新进入地图情况
	if (judge == 1)
	{
		Begin_Print(t);
		t.wait(1000);
	}

	//设置白底黑字
	t.setPrintColor_FrontBack(30, 47);
	//白屏显示
	t.FullScreen_Quick();

	map_Print(t);

	t.gotoXY(51, 11);
	int x0 = 5, y0 = 6, x1 = 5, y1 = 6;
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

