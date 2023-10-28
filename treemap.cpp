#include"treemap.h"
#include"buy menu.h"
#include "NeighborRoom.h"
#include "Fight.h"
#include<iostream>
using namespace std;

int treemap::ifSuccess = -1;

void treemap::Begin_Print(Tool& t)
{
	const char* str1 = "��    һ    ��";
	const char* str2 = "��  ��  ɭ  ��";

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
		cout << "��";
	cout << endl;

	for (int i = 9, m = 11, s = 1; i > 0; i--)
	{
		t.gotoXY(40, 5 + s);
		for (int j = 0; j < i; j++)
			cout << "��";
		for (int k = 0; k < m - i; k++)
			cout << " ";
		for (int t = 0; t < i; t++)
			cout << "��";
		cout << endl;
		m += 3;
		s++;
	}

	for (int i = 2, m = 34, s = 1; i < 10; i++)
	{
		t.gotoXY(40, 14 + s);
		for (int j = 0; j < i; j++)
			cout << "��";
		for (int k = 0; k < m - i - 2; k++)
			cout << " ";
		for (int t = 0; t < i; t++)
			cout << "��";
		cout << endl;
		m -= 3;
		s++;
	}
	t.gotoXY(40, 23);
	for (int i = 0; i < 19; i++)
		cout << "��";
	cout << endl;


	t.gotoXY(50, 15);
	cout << "����";

	t.gotoXY(66, 13);
	cout << "ƴͼ";

	if (judge == 1)
	{
		t.gotoXY(52, 11);
		t.setPrintColor(0x04);
		cout << "��";
		t.setPrintColor(0x07);
	}

	/*t.gotoXY(57, 22);
	cout << "��";*/
}

void treemap::mailbox(Tool& t)
{
	t.gotoXY(40, 25);
	const char* str1 = "û��û�����Ŀ��ˡ���";
	t.printMessage_Quick(str1);
	t.wait(500);
	//t.clearLine(40, 25);

	t.gotoXY(40, 26);
	const char* str2 = "��ӭ�����ҵ�С�꣡����㿴��������������";
	t.printMessage_Quick(str2);
	t.wait(1000);
	//t.clearLine(40, 25);

	mailbox_choose(t);
}

void treemap::mailbox_choose(Tool& t)
{
	t.gotoXY(40, 27);
	cout << "���� (Y��)";
	t.gotoXY(40, 28);
	cout << "�뿪 (N��)";

	char choose;
	while (true)
	{
		t.gotoXY(50, 27);
		try {
			if (!(cin >> choose)) //�ж��Ƿ�Ϊchar��
			{
				throw std::runtime_error("��������,���������룡");
			}

			//�ж�������ĸ�Ƿ��ڷ�Χ��
			if (!(choose == 'Y' || choose == 'y' || choose == 'N' || choose == 'n'))
			{
				throw std::runtime_error("��������,���������룡");
			}
			BuyMenu v;
			switch (choose)
			{
			case 'Y':  //������ʳor���
				//��������
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 25 + i);
				}
				system("cls");
				v.Execute_buymenu(t, 0, fight);
				t.gotoXY(40, 25);

				//һ��ʱ���������ʺ�����ͼ�����½����ͼ
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
			case 'y':  //ͬ'Y'
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
			case 'N':  //�뿪
				//����������ʺ�����ͼ�����½����ͼ
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
			case 'n':  //ͬ'N'
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
				throw std::runtime_error("��������,���������룡");
			}
		}

		catch (const std::exception& e)
		{
			cin.clear(); // �������״̬
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Դ��������

			//����
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
	const char* str1 = "һЩ�����ƴͼ����";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 25);
}

void treemap::ForestRabbit(Tool& t)
{
	t.gotoXY(40, 25);
	const char* str1 = "ɭ�����ã�����ս��ģʽ";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 25);
}

void treemap::Position(int x0, int y0, int x1, int y1, Tool& t)
{
	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
	if (x0 != x1 || y0 != y1)
	{
		t.gotoXY(40 + 2 * x0, 5 + y0);  //�����ƶ���ԭ��λ�ñ��ո񸲸�
		cout << "  ";
		t.gotoXY(40 + 2 * x1, 5 + y1);  //��λ����ʾ����ͼ��
		cout << "��";
	}
}

void treemap::door_choose(Tool& t)
{
	NeighborRoom s;
	/*t.gotoXY(40, 20);
	const char* str1 = "��";
	t.printMessage_Quick(str1);*/
	t.gotoXY(40, 25);
	const char* str2 = "����Ҫ��ȥ��?";
	t.printMessage_Quick(str2);

	t.wait(200);
	t.gotoXY(40, 26);
	cout << "����     (Y��)";
	t.gotoXY(40, 27);
	cout << "ʲôҲ���� (N��)";

	char choose;
	while (true)
	{
		t.gotoXY(57, 27);
		try {
			if (!(cin >> choose)) //�ж��Ƿ�Ϊchar��
			{
				throw std::runtime_error("��������,���������룡");
			}

			//�ж�������ĸ�Ƿ��ڷ�Χ��
			if (!(choose == 'Y' || choose == 'y' || choose == 'N' || choose == 'n'))
			{
				throw std::runtime_error("��������,���������룡");
			}

			NeighborRoom n;
			switch (choose)
			{
			case 'Y':  //����
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				s.Execute_NeighborRoom(t, 0);
				break;
			case 'y':  //ͬ'Y'
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				s.Execute_NeighborRoom(t, 0);
				break;
			case 'N':  //ʲô������
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
			case 'n':  //ͬ'N'
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
				throw std::runtime_error("��������,���������룡");
			}
		}

		catch (const std::exception& e)
		{
			cin.clear(); // �������״̬
			cin.ignore((numeric_limits<std::streamsize>::max)(), '\n');
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Դ��������

			//����
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

//�ж���һ��������
int treemap::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//�ж�����λ���ж�
void treemap::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t)
{
	NeighborRoom n;
	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
	switch (number)
	{
	case 0:  //���ƶ� -- ����ͼ��䶯��������λ��
		Position(x0, y0, x1, y1, t);
		x0 = x1;
		y0 = y1;
		break;
	case 1:  //����ǽ������ǰ��
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
		if (ifSuccess == -1) //ʧ��
			Execute_treemap(t, 0, 1);
		else //�ɹ�,ɾ������
		{
			map[6][6] = 0;
			Execute_treemap(t, 0, 2);
		}
		break;
	case 5: //��
		door_choose(t);
		break;
	default:
		break;
	}
}

//ִ�к���
void treemap::Execute_treemap(Tool& t, int judge1, int judge2)
{
	//judge==1ʱΪ���ҳ�棬����Ϊѡ��أ����½����ͼ���
	if (judge1 == 1)
	{
		Begin_Print(t);
	}

	//judge==1Ϊս��ǰ,judge==2Ϊս��ʤ����
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