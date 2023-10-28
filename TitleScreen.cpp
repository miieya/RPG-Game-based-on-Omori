#include <iostream>
#include <conio.h>
#include "TitleScreen.h"
#include "WhiteSpace.h"
#include "Illustration.h"
#include "Tool.h"
using namespace std;

//������⡢�˵�ѡ��(�����ʾ��
void TitleScreen::Menu_Print_First(Tool& t)
{
	//�������
	t.gotoXY(54, 3);
	const char* str1 = "O M O R I";
	t.printMessage(str1);

	//�����ɫ����
	t.wait(500);
	t.setPrintColor(0x04);
	t.gotoXY(54, 3);
	t.printMessage(str1);

	//��ذ�ɫ����
	t.setPrintColor(0x07);
	t.wait(200);
	t.gotoXY(54, 3);
	t.printMessage(str1);

	//�����ɫ��ʼλ��
	t.wait(300);
	t.gotoXY(58, 3);
	cout << "��";

	//����˵�
	t.wait(500);
	t.gotoXY(54, 6);
	const char* str2 = "��Ϸ���";
	const char* str3 = "�������";
	const char* str4 = "ͼ�����";
	const char* str5 = "�˳����";
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

//������⡢�˵�ѡ��(������ʾ��
void TitleScreen::Menu_Print_After(Tool& t)
{
	t.gotoXY(54, 3);
	cout << "O M O R I" << endl;

	t.wait(300);
	t.gotoXY(58, 3);
	cout << "��";

	t.gotoXY(54, 6);
	cout << "��Ϸ���" << endl;
	t.gotoXY(54, 9);
	cout << "�������" << endl;
	t.gotoXY(54, 12);
	cout << "ͼ�����" << endl;
	t.gotoXY(54, 15);
	cout << "�˳����" << endl;
}

//���ȷ��ҳ��
void TitleScreen::Confirm_Print_Exit(Tool& t, int judge)
{
	//���ѡ��
	t.gotoXY(52, 3);
	if (judge == 1)
		cout << "ȷ�Ͻ�����Ϸ��" << endl;
	else if (judge == 2)
		cout << "ȷ�Ͻ������ã�" << endl;
	else if (judge == 3)
		cout << "ȷ�Ͻ���ͼ����" << endl;
	else if (judge == 4)
		cout << "ȷ���˳���Ϸ��" << endl;

	t.gotoXY(56, 6);
	cout << "ȷ��" << endl;
	t.gotoXY(56, 9);
	cout << "ȡ��" << endl;

	//�����ɫ��ʼλ��
	t.wait(300);
	t.gotoXY(58, 4);
	cout << "��";
}

//��ʾ����ͼ��(�˵�ҳ�棩
void TitleScreen::Position_Title(int x0, int y0, int x1, int y1, Tool& t)
{
	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
	if (x0 != x1 || y0 != y1)
	{
		t.gotoXY(44 + 2 * x0, 2 + y0);  //�����ƶ���ԭ��λ�ñ��ո񸲸�
		cout << "  ";
		t.gotoXY(44 + 2 * x1, 2 + y1);  //��λ����ʾ����ͼ��
		cout << "��";
	}
}

//�ж���һ��������(�˵���ͼ��
int TitleScreen::ClueJudge_Title(int x1, int y1)
{
	int number = map_Title[y1][x1];
	return number;
}

//�ж���һ��������(ȷ�ϵ�ͼ��
int TitleScreen::ClueJudge_Confirm(int x1, int y1)
{
	int number = map_Confirm[y1][x1];
	return number;
}

//�ж�����λ���ж�(�˵���ͼ��
void TitleScreen::Movement_Title(int number, int& x0, int& y0, int x1, int y1, Tool& t)
{
	Illustration i;
	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
	switch (number)
	{
	case 0:  //���ƶ� -- ����ͼ��䶯��������λ��
		Position_Title(x0, y0, x1, y1, t);
		x0 = x1; 
		y0 = y1;
		break;
	case 1:  //����ǽ������ǰ��
		break;
	case 2:  //��ʼ��Ϸ���
		system("cls");
		Execute_Confirm(t, 1, 1);
		break;
	case 3:   //�������
		system("cls");
		Execute_Confirm(t, 2, 2);
		break;
	case 4:   //ͼ�����
		system("cls");
		i.Execute(t, 1, 0);
		Execute_Confirm(t, 3, 3);
		break;
	case 5:   //�˳����
		system("cls");
		Execute_Confirm(t, 4, 4);
		break;
	default:
		break;
	}
}

//�ж�����λ���ж�(ȷ�ϵ�ͼ��
void TitleScreen::Movement_Confirm(int number, int& x0, int& y0, int x1, int y1, Tool& t, int judge)
{
	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
	switch (number)
	{
	case 0:  //���ƶ� -- ����ͼ��䶯��������λ��
		Position_Title(x0, y0, x1, y1, t);
		x0 = x1;
		y0 = y1;
		break;
	case 1:  //����ǽ������ǰ��
		break;
	case 2:  //ȷ�����
	{ 
		system("cls");
		if (judge == 1) //������Ϸ
		{
			t.wait(200);
			WhiteSpace w;
			w.Execute_WhiteSpace(t, 1);
		}
		else if (judge == 2)  //��������
		{

		}
		else if (judge == 3)  //����ͼ��
		{

		}
		else if (judge == 4) //�˳���Ϸ
		{
			t.gotoXY(47, 3);
			cout << "���˳���Ϸ����ӭ�ٴ�����." << endl;

			//���·�������
			t.gotoXY(47, 20);
			system("pause");
			exit(0);
		}
		break;
	}
	case 3:   //�������
		//��������������ҳ
		system("cls");
		Execute_Title(2);
		break;
	default:
		break;
	}
}

//�˵�ҳ��ִ��
void TitleScreen::Execute_Title(int judge)
{
	Tool t;
	if (judge == 1)
		Menu_Print_First(t);
	else
		Menu_Print_After(t);

	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
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

//ȷ��ҳ��ִ��
void TitleScreen::Execute_Confirm(Tool& t, int judge1, int judge2)
{
	//judeg1 -- �ж����������Ϸ/��������/����ͼ��/�˳���Ϸ
	//judge2 -- �жϽ�����Ϸ/��������/����ͼ��/�˳���Ϸ��ͼ

	Confirm_Print_Exit(t, judge1);

	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
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
