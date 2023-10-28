#include <iostream>
#include <windows.h> 
#include <conio.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Tool.h"
using namespace std;

//�ƶ���굽ָ��λ��
void Tool::gotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//��һ���ÿո񸲸�
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

//��ʱ����
void Tool::wait(int seconds)
{
    clock_t endwait;
    endwait = clock() + seconds / 1000.0 * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

//�������� x-x+w,y-y+h
void Tool::clear(int x, int y, int w, int h)
{
    for (int i = 0; i < h; i++) {
        gotoXY(x, y + i);
        for (int j = 0; j < w; j++) 
            putchar(' ');
    }
}

//�������
void Tool::printMessage(const char* str)
{
    for (int i = 0; i < strlen(str); ++i)
    {
        cout << *(str + i);
        Sleep(100);
    }
    cout << endl;
}

//�������(���٣�
void Tool::printMessage_Quick(const char* str)
{
    for (int i = 0; i < strlen(str); ++i)
    {
        cout << *(str + i);
        Sleep(10);
    }
    cout << endl;
}

//����������ɫ
void Tool::setPrintColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

    //0x01:��ɫ  0x02:��ɫ  0x03:����ɫ  0x04����ɫ
    //0x05:��ɫ  0x06:��ɫ  0x07:��ɫ    0x08����ɫ
}

//���ñ���+������ɫ
void Tool::setPrintColor_FrontBack(int foreground, int background)
{
    std::cout << "\033[" << foreground << ";" << background << "m";
}

//���ڸ���ȫ��Ļ(��Ч����
void Tool::FullScreen()
{
    srand(time(0));
    struct Position
    {
        int x;
        int y;
    };

    // ����һ���������п���λ�õ��б�
    vector<Position> positions;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 120; ++j) {
            for (int k = 0; k < 3; k++)
                positions.push_back({ j, i });
        }
    }

    // ��������б�
    random_shuffle(positions.begin(), positions.end());

    // �����б����ÿ��λ��
    for (const auto& position : positions) {
        gotoXY(position.x, position.y);
        std::cout << " ";
    }
}

//���ڸ���ȫ��Ļ(����Ч����
void Tool::FullScreen_Quick()
{
    for (int i = 0; i < 30; i++)
    {
        clearLine(0, i);
    }
}

//�ƶ�����
void Tool::sidejudge(int& x1, int& y1)
{
    if (_kbhit())
    {
        char input = _getch(); //�Ӽ����ϻ�ȡ����
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
        cout << "��";
    }
}

int Tool::generateRandomNumber(int num)
{
    //srand(time(0));
    int Rand = rand() % num;
    return Rand;
}