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

//������Ϸ�׽������
void WhiteSpace::Begin_Print(Tool& t)
{
	const char* str1 = "�� ӭ �� �� �� ɫ �� ��";
	const char* str2 = "�����м���ʱ��ʼ";
	const char* str3 = "���һֱ��������";
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

	//���ð׵׺���
	t.setPrintColor_FrontBack(30, 47);
	//������ʾ
	t.FullScreen();

}

//�����ͼ
void WhiteSpace::map_Print(Tool& t)
{
	t.setPrintColor_FrontBack(30, 47);
	t.gotoXY(44, 5);
	cout << "�� ";
	t.gotoXY(58, 6);
	cout << "����";
	t.gotoXY(44, 9);
	cout << "      ����            ����";
	t.gotoXY(50, 11);
	cout << "��";
	t.gotoXY(64, 14);
	cout << "ֽ���";
	t.gotoXY(50, 16);
	cout << "����";

	for (int i = 0; i <= 5; i++)
	{
		t.gotoXY(60, i);
		cout << "��";
	}
}

//����
void WhiteSpace::Computer(Tool& t, int judge)
{
	//judge=1,Ϊ���ȴ򿪵���ҳ��  judge=2��Ϊѡ�񷵻ص���ҳ��
	if (judge == 1)
	{
		t.gotoXY(40, 20);
		const char* str1 = "����������ıʼǱ����ԡ�";
		t.printMessage_Quick(str1);
		t.wait(1000);
		system("cls");

		Computer_Print(t);
		//�������
		t.gotoXY(26, 23);
		const char* str2 = "����Ҫ��Щʲô?";
		t.printMessage_Quick(str2);
	}
	
	if (judge == 0)
	{
		//���������Ļ
		Computer_Print(t);
		t.gotoXY(26, 23);
		cout << "����Ҫ��Щʲô?";
	}
	
	//�״δ����ӳ�
	if(judge==1)
		t.wait(200);
	Computer_Choose(t);
}

void WhiteSpace::Computer_Choose(Tool& t)
{
	t.gotoXY(26, 25);
	cout << "(1)������Ļ";
	t.gotoXY(26, 26);
	cout << "(2)������ռ�";
	t.gotoXY(26, 27);
	cout << "(3)�ǳ�";

	int choose;
	while (true)
	{
		t.gotoXY(35, 27);
		try {
			if (!(cin >> choose)) //�ж��Ƿ�Ϊint
			{
				throw std::runtime_error("��������,���������룡");
			}

			//�ж����������Ƿ��ڷ�Χ��
			if (choose < 1 || choose > 3)
			{
				throw std::runtime_error("��������,���������룡");
			}

			//����ѡ������
			for (int i = 23; i <= 27; i++)
			{
				t.clearLine(26, i);
			}
			
			const char* str1 = "�㶢����Ļ";
			switch (choose)
			{
			case 1: 
				t.wait(100);
				t.gotoXY(26, 23);
				t.printMessage_Quick(str1);
				t.wait(1500);
				//�������ֺ󷵻ص�����ҳ��
				t.clearLine(26, 23);
				Computer(t,0);
				break;
			case 2:
				t.wait(200);
				Computer_Print_Diary(t);
				t.wait(3000);
				//�����ռ�����
				t.clear(25, 2, 75, 20);
				Computer(t, 0);
				break;
			case 3: 
				//�������ֺ󷵻ذ�ɫ�ռ�
				system("cls");
				Execute_WhiteSpace(t, 0);
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

			//����ѡ������
			for (int i = 23; i <= 27; i++)
			{
				t.clearLine(26, i);
			}
			t.gotoXY(26, 23);
			cout << e.what() << endl;
			t.wait(500);
			//���Ǵ�����ʾ�����ص���������
			t.clearLine(26, 23);
			Computer(t, 0);
		}
	}

}

//���������Ļ
void WhiteSpace::Computer_Print(Tool& t)
{
	//���������Ļ��
	t.gotoXY(24, 1);
	cout << "��";
	for (int i = 0; i < 70; ++i)
		cout << "��";
	cout << "��";

	t.gotoXY(24, 21);
	cout << "��";
	for (int i = 0; i < 70; ++i)
		cout << "��";
	cout << "��";

	for (int i = 2; i <= 20; ++i)
	{
		t.gotoXY(24, i);
		cout << "��";
		t.gotoXY(95, i);
		cout << "��";
	}

	// "Start"����
	t.gotoXY(26, 18);
	cout << "��������������";
	t.gotoXY(26, 19);
	cout << "��Start��";
	t.gotoXY(26, 20);
	cout << "��������������";

	// "0:00AM"����
	t.gotoXY(86, 18);
	cout << "����������������";
	t.gotoXY(86, 19);
	cout << "��0:00AM��";
	t.gotoXY(86, 20);
	cout << "����������������";

	t.gotoXY(26, 23);
	const char* str1 = "����Ҫ��Щʲô?";
	t.printMessage_Quick(str1);
}

//��������ռ�
void WhiteSpace::Computer_Print_Diary(Tool& t)
{
	t.gotoXY(26, 2);
	cout << "OMORI���ռ�";

	int startX = 25;
	int startY = 3;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			int x = startX + col * 35;
			int y = startY + row * 5;
			t.gotoXY(x, y);
			cout << "��������������������������������������������������������������������";
			t.gotoXY(x, y + 1);
			cout << "����???��                         ��";
			t.gotoXY(x, y + 2);
			cout << "������,�Ҵ��ڰ�ɫ�ռ���,һ�ж��ܺé�";
			t.gotoXY(x, y + 3);
			cout << "������,��ȥ��������,һ�ж��ܺ�    ��";
			t.gotoXY(x, y + 4);
			cout << "��������������������������������������������������������������������";
		}
	}
}

//����
void WhiteSpace::ArtBook(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "��Ļ滭��, ���滭�������Ϳѻ��";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

//ֽ���
void WhiteSpace::TissueBox(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "һ��ֽ���, ������ȥ��ı��ˡ�";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

//����
void WhiteSpace::Cat(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "����(���ڵȴ�ĳ������ķ�����?)";
	t.printMessage_Quick(str1);
	t.wait(2000);
	t.clearLine(40, 20);
}

//����
void WhiteSpace::Bulb(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "�Ӳ�֪�δ����컨�������������ĵ���";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "Ҫ�������￴��";
	t.printMessage_Quick(str2);

	t.wait(200);
	Bulb_Choose(t);
}

//����ѡ��
void WhiteSpace::Bulb_Choose(Tool& t)
{
	t.gotoXY(40, 23);
	cout << "�� (Y��)";
	t.gotoXY(40, 24);
	cout << "�� (N��)";

	char choose;
	while (true)
	{
		t.gotoXY(50, 24);
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

			const char* str1 = "�������һƬ����ʲôҲ��������";
			switch (choose)
			{
			case 'Y':  //�������￴
				//��������
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 20 + i);
				}
				//���str1
				t.gotoXY(40, 20);
				t.printMessage_Quick(str1);
				//һ��ʱ���������ʺ�����ͼ�����½����ͼ
				t.wait(2000);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);
				Execute_WhiteSpace(t, 0);
				break;
			case 'y':  //ͬ'Y'
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
			case 'N':  //����
				//����������ʺ�����ͼ�����½����ͼ
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
			case 'n':  //ͬ'N'
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
			Bulb_Choose(t);
		}
	}
}

//��
void WhiteSpace::Door(Tool& t)
{
	t.gotoXY(40, 20);
	const char* str1 = "һ�Ȱ�ɫ����Ͷ���˵�����Ӱ�ӡ�";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 21);
	const char* str2 = "����Ҫ��Щʲô?";
	t.printMessage_Quick(str2);

	t.wait(200);
	Door_Choose(t);
}

//�ŵ�ѡ��
void WhiteSpace::Door_Choose(Tool& t)
{
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
				if (n.cnt2 == 0)
				{
					n.Execute_NeighborRoom(t, 1);
					n.cnt2++;
				}
				else
					n.Execute_NeighborRoom(t, 0);
				break;
			case 'y':  //ͬ'Y'
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
			case 'N':  //ʲô������
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
			case 'n':  //ͬ'N'
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
			Door_Choose(t);
		}
	}
}

//��ʾ����ͼ��
void WhiteSpace::Position(int x0, int y0, int x1, int y1, Tool& t)
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

//�ж���һ��������
int WhiteSpace::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//�ж�����λ���ж�
void WhiteSpace::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t)
{
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
	case 2:  //����
		Computer(t, 1);
		break;
	case 3:  //����
		ArtBook(t);
		break;
	case 4:  //ֽ���
		TissueBox(t);
		break;
	case 5:  //����
		Cat(t);
		break;
	case 6:  //����
		Bulb(t);
		break;
	case 7:  //��
		Door(t);
		break;
	default:
		break;
	}
}

//ִ�к���
void WhiteSpace::Execute_WhiteSpace(Tool& t, int judge)
{
	//judge==1ʱΪ���ҳ�棬����Ϊѡ��أ����½����ͼ���
	if (judge == 1)
	{
		Begin_Print(t);
		t.wait(1000);
	}

	//���ð׵׺���
	t.setPrintColor_FrontBack(30, 47);
	//������ʾ
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

