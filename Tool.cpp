#include <iostream>
#include <windows.h> 
#include <conio.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Tool.h"
using namespace std;

//移动光标到指定位置
void Tool::gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//将一行用空格覆盖
void Tool::clearLine(int x, int y)
{
    //Sleep(500);
    setXY(x, y);
    for (int i = 0; i < 120; i++)
    {
        cout << " ";
    }
}

void Tool::setXY(int x, int y)
{
    COORD pos;
    HANDLE obj;
    pos.X = x;
    pos.Y = y;
    obj = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(obj, pos);
}

//延时函数
void Tool::wait(int seconds)
{
    clock_t endwait;
    endwait = clock() + seconds / 1000.0 * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

//覆盖区域 x-x+w,y-y+h
void Tool::clear(int x, int y, int w, int h)
{
    for (int i = 0; i < h; i++) {
        gotoXY(x, y + i);
        for (int j = 0; j < w; j++) 
            putchar(' ');
    }
}

//逐字输出
void Tool::printMessage(const char* str)
{
    for (int i = 0; i < strlen(str); ++i)
    {
        cout << *(str + i);
        Sleep(100);
    }
    cout << endl;
}

//逐字输出(快速）
void Tool::printMessage_Quick(const char* str)
{
    for (int i = 0; i < strlen(str); ++i)
    {
        cout << *(str + i);
        Sleep(10);
    }
    cout << endl;
}

//设置字体颜色
void Tool::setPrintColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

    //0x01:蓝色  0x02:绿色  0x03:淡蓝色  0x04：红色
    //0x05:紫色  0x06:黄色  0x07:白色    0x08：灰色
}

//设置背景+文字颜色
void Tool::setPrintColor_FrontBack(int foreground, int background)
{
    std::cout << "\033[" << foreground << ";" << background << "m";
}

//用于覆盖全屏幕(逐渐效果）
void Tool::FullScreen()
{
    srand(time(0));
    struct Position
    {
        int x;
        int y;
    };

    // 创建一个包含所有可能位置的列表
    vector<Position> positions;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 120; ++j) {
            for (int k = 0; k < 3; k++)
                positions.push_back({ j, i });
        }
    }

    // 随机排序列表
    random_shuffle(positions.begin(), positions.end());

    // 遍历列表并输出每个位置
    for (const auto& position : positions) {
        gotoXY(position.x, position.y);
        std::cout << " ";
    }
}

//用于覆盖全屏幕(快速效果）
void Tool::FullScreen_Quick()
{
    for (int i = 0; i < 30; i++)
    {
        clearLine(0, i);
    }
}

//移动函数
void Tool::sidejudge(int& x1, int& y1)
{
    if (_kbhit())
    {
        char input = _getch(); //从键盘上获取输入
        switch (input)
        {
        case 'w':
            y1 -= 1;
            break;
        case's':
            y1 += 1;
            break;
        case'a':
            x1 -= 1;
            break;
        case'd':
            x1 += 1;
            break;
        }
    }
}

void Tool::viewme(int x0, int y0, int x1, int y1)
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(40 + 2 * x0, 5 + y0);
        cout << "  ";
        gotoXY(40 + 2 * x1, 5 + y1);
        cout << "●";
    }
}

int Tool::generateRandomNumber(int num)
{
    //srand(time(0));
    int Rand = rand() % num;
    return Rand;
}