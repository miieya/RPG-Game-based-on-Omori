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
	const char* str1 = "Aubrey: ��OMORI! ����������������Ҫ����!";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "        �������һ�������?";
	t.printMessage_Quick(str2);
	t.wait(500);
	t.gotoXY(40, 22);
	const char* str3 = "        �������ÿ�Ҫ������һ������!";
	t.printMessage_Quick(str3);

	t.wait(2000);
	for (int i = 20; i <= 22; i++)
		t.clearLine(40, i);
	t.gotoXY(40, 20);
	const char* str4 = "Aubrey: ��! ��ѽ.....����û˵��.....";
	t.printMessage_Quick(str4);
	
	t.wait(2000);
	t.clearLine(40, 20);
	t.gotoXY(40, 20);
	const char* str5 = "Kel: ��ѽ.....���ʲôѽ, Aubrey?!";
	t.printMessage_Quick(str5);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str6 = "     �����ȫ��Ū������!";
	t.printMessage_Quick(str6);
	t.wait(500);
	t.gotoXY(40, 22);
	const char* str7 = "     �������Ϳ�Ӯ���ء�";
	t.printMessage_Quick(str7);

	t.wait(2000);
	for (int i = 20; i <= 22; i++)
		t.clearLine(40, i);
	t.gotoXY(40, 20);
	const char* str8 = "Hero: ��������, Kel, û�б�Ҫ����ѽ��";
	t.printMessage_Quick(str8);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str9 = "      ��, OMORI, ���ǽ���Ҳһ���ȥ���!";
	t.printMessage_Quick(str9);

	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::map_Print(Tool& t)
{
	t.gotoXY(40, 5);
	cout << "ǽǽǽǽǽǽǽǽǽǽǽǽǽǽǽǽǽǽ";
	t.gotoXY(40, 17);
	cout << "ǽǽǽǽǽǽǽǽ��ǽǽǽǽǽǽǽǽǽ";
	t.gotoXY(44, 6);
	cout << "��Ƭ";
	t.gotoXY(50, 6);
	cout << "��ͷ";
	t.gotoXY(44, 10);
	cout << "����";
	t.gotoXY(44, 11);
	cout << "����";

	t.setPrintColor(0x0E);
	t.gotoXY(58, 10);
	cout << "��";
	t.setPrintColor(0x05);
	t.gotoXY(56, 11);
	cout << "��";
	t.setPrintColor(0x03);
	t.gotoXY(54, 10);
	cout << "��";
	t.setPrintColor(0x07);
	t.gotoXY(56, 16);
	cout << "��";

	t.gotoXY(66, 12);
	cout << "��";
	t.gotoXY(62, 15);
	cout << "����";

	for (int i = 6; i <= 16; i++)
	{
		t.gotoXY(40, i);
		cout << "ǽ";
		t.gotoXY(74, i);
		cout << "ǽ";
	}

	t.gotoXY(70, 6);
	cout << "¥��";
	t.gotoXY(70, 7);
	cout << "¥��";
	t.gotoXY(72, 8);
	cout << "��";
}

void NeighborRoom::Photo(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "һ����Ϥ���˵���Ƭ��";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::Pillow(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "һ���������ͷ,��״��һ��Ů���ӵ�ͷ��";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::Hole(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "һ��è�εĶ���";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::TV(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "�����Ϸ���һ����Ӱ��";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "�ĸ��к�����·��������š�";
	t.printMessage_Quick(str2);

	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::Snack(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "˻˻˻˻˻˻˻.....��";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

void NeighborRoom::Aubrey(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "Aubrey: OMORI! �Ҿ�֪���ҿ���������!";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "        ���������ġ�";
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::Kel(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "Kel: ��~~~~ѽ....";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "     Aubrey������Ҫ��ô��������ô����";
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::Hero(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "Hero: ��OMORI, �ܼ���������̫���ˡ�";
	t.printMessage_Quick(str1);
	t.wait(500);
	t.gotoXY(40, 21);
	const char* str2 = "      ��������ѽ, ���Ǳ˴�֮���ֱ�Ť��";
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 20);
	t.clearLine(40, 21);
}

void NeighborRoom::door_choose(Tool& t)
{
	WhiteSpace s;
	t.gotoXY(40, 20);
	const char* str1 = "һ�Ȱ�ɫ����Ͷ���˵�����Ӱ�ӡ�";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "����Ҫ��Щʲô?";
	t.printMessage_Quick(str2);

	t.wait(200);
	t.gotoXY(40, 23);
	cout << "����     (Y��)";
	t.gotoXY(40, 24);
	cout << "ʲôҲ���� (N��)";

	char choose;
	while (true)
	{
		t.gotoXY(57, 24);
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
				s.Execute_WhiteSpace(t, 0);
				break;
			case 'y':  //ͬ'Y'
				t.wait(1000);
				t.setPrintColor_FrontBack(40, 37);
				system("cls");
				s.Execute_WhiteSpace(t, 0);
				break;
			case 'N':  //ʲô������
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
				break;
			case 'n':  //ͬ'N'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
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

void NeighborRoom::stair_choose(Tool& t, treemap& s)
{
	t.gotoXY(40, 21);
	const char* str2 = "����Ҫ������?";
	t.printMessage_Quick(str2);

	t.wait(200);
	t.gotoXY(40, 23);
	cout << "����     (Y��)";
	t.gotoXY(40, 24);
	cout << "ʲôҲ���� (N��)";

	char choose;
	while (true)
	{
		t.gotoXY(57, 24);
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

			switch (choose)
			{
			case 'Y':  //����
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
			case 'y':  //ͬ'Y'
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
			case 'N':  //ʲô������
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
				break;
			case 'n':  //ͬ'N'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				t.gotoXY(44, 5);
				cout << " ";
				Execute_NeighborRoom(t, 0);
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

void NeighborRoom::Position(int x0, int y0, int x1, int y1, Tool& t)
{
	if (x0 != x1 || y0 != y1)
	{
		t.gotoXY(40 + 2 * x0, 5 + y0);
		cout << "  ";
		t.gotoXY(40 + 2 * x1, 5 + y1);
		cout << "��";
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
	case 2:  //��Ƭ
		Photo(t);
		break;
	case 3:  //��ͷ
		Pillow(t);
		break;
	case 4:  //��
		Hole(t);
		break;
	case 5:  //����
		TV(t);
		break;
	case 6:  //¥��
		stair_choose(t, tree);
		break;
	case 7:  //��
		Snack(t);
		break;
	case 8: //��
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