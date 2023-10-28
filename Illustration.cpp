#include <iostream>
#include "Illustration.h"
#include "Tool.h"
#include "TitleScreen.h"
using namespace std;

//���ͼ������(���ȣ�
void Illustration::Header_Print01(Tool& t)
{
	t.gotoXY(53, 2);
	cout << "�����˵����ҩ�";
	t.gotoXY(45, 4);
	cout << "��";
	t.gotoXY(45, 5);
	cout << "��";
	t.gotoXY(73, 4);
	cout << "��";
	t.gotoXY(73, 5);
	cout << "��";
	t.gotoXY(58, 4);
	cout << "��";

	t.gotoXY(54, 12);
	cout << "1.ɭ������";
	t.gotoXY(54, 13);
	cout << "2.��������";
	t.gotoXY(54, 14);
	cout << "3.������";
	t.gotoXY(54, 15);
	cout << "4.��������";
}

//���ͼ������(�鿴ҳ�棩
void Illustration::Header_Print02(Tool& t, int judge) 
{
	t.gotoXY(53, 2);
	cout << "�����˵����ҩ�";
	t.gotoXY(45, 4);
	cout << "��";
	t.gotoXY(45, 5);
	cout << "��";
	t.gotoXY(58, 4);
	cout << "��";

	//�ж�����ĸ�������Ϣ
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

//ѡ��鿴����
void Illustration::Select(Tool& t)
{
	t.gotoXY(48, 8);
	cout << "�����˽��ĸ����˵���Ϣ�أ�";
	t.gotoXY(48, 9);
	cout << "������ţ�";

	int choose;
	while (true)
	{
		try {
			if (!(cin >> choose)) //�ж��Ƿ�Ϊint��
			{
				throw std::runtime_error("��������,���������룡");
			}

			if (choose < 1 || choose > 4)  //�ж����������Ƿ��ڷ�Χ��
			{
				throw std::runtime_error("��������,���������룡");
			}

			switch (choose)
			{
			case 1: //ɭ������
				system("cls");
				Execute(t, 2, 1);
				break;
			case 2: //��������
				system("cls");
				Execute(t, 2, 2);
				break;
			case 3: //������
				system("cls");
				Execute(t, 2, 3);
				break;
			case 4: //��������
				system("cls");
				Execute(t, 2, 4);
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
			t.clearLine(48, 8);
			t.clearLine(48, 9);
			t.gotoXY(50, 8);
			cout << e.what() << endl;
			t.wait(500);
			Select(t);
		}
	}
}

//��ʾ����ͼ��
void Illustration::Position(int x0, int y0, int x1, int y1, Tool& t)
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

//�ж���һ��������
int Illustration::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//�ж�����λ���ж�
void Illustration::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t, int judge)
{
	TitleScreen x;
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
	case 2:  //�������
		system("cls");
		if (judge == 1)  //��ͼ�����ز˵�ҳ��
			x.Execute_Title(2);
		else             //��ͼ��������ͼ��ҳ��
			Execute(t, 1, 0);
		break;
	case 3:   
		if (judge == 1) //�鿴ͼ��
			Select(t);
		else  //ͼ���ڲ�ҳ���޲鿴ѡ��
			break;
		break;
	default:
		break;
	}
}

//ͼ��ҳ��ִ��
void Illustration::Execute(Tool& t, int judge1, int judge2)
{
	if (judge1 == 1)
		Header_Print01(t);
	else
		Header_Print02(t,judge2);

	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
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

//ɭ������
void Illustration::ForestBunny(Tool& t)
{
	t.gotoXY(54, 8);
	cout << "ɭ������";
	t.gotoXY(51, 10);
	cout << "ë���޵Ŀɰ�����";
	t.gotoXY(51, 11);
	cout << "Ҳ�����ں���Ԥ����";
	t.gotoXY(51, 12);
	cout << "�����Ϯ������....";
	t.gotoXY(51, 14);
	cout << "----OMORI";

	t.gotoXY(51, 17);
	cout << "�Ҿ���Ӧ�û����൱";
	t.gotoXY(51, 18);
	cout << "�ɰ��ĳ����أ�";
	t.gotoXY(51, 20);
	cout << "----�²���";
}

void Illustration::SproutMole(Tool& t)
{
	t.gotoXY(56, 8);
	cout << "��������";
	t.gotoXY(51, 10);
	cout << "Σ�ն��Ҵ��е���ĳ�ª";
	t.gotoXY(51, 11);
	cout << "ֲ������, ����˵�Լ���";
	t.gotoXY(51, 12);
	cout << "����, ����Ҫ������, ��";
	t.gotoXY(51, 13);
	cout << "һ�㶼������, ��������";
	t.gotoXY(51, 14);
	cout << "�����·���ζ����";
	t.gotoXY(51, 16);
	cout << "----OMORI";
}

//������
void Illustration::Mixtape(Tool& t)
{
	t.gotoXY(56, 8);
	cout << "������";
	t.gotoXY(51, 10);
	cout << "����ʱ��������......";
	t.gotoXY(51, 11);
	cout << "��Ȼ���ܿ��Ҫ�˳���ʷ";
	t.gotoXY(51, 12);
	cout << "��̨��, ��������������";
	t.gotoXY(51, 13);
	cout << "�ܿ��ĵ����ӡ�";
	t.gotoXY(51, 15);
	cout << "----OMORI";

	t.gotoXY(51, 18);
	cout << "�ҹ�ȥ����һ����ͦϲ��";
	t.gotoXY(51, 19);
	cout << "�ռ���Щ�����ģ�ԭ����";
	t.gotoXY(51, 20);
	cout << "�Ƕ��ܵ��������˰�....";
	t.gotoXY(51, 22);
	cout << "----Ӣ��";
}

void Illustration::DoomBox(Tool& t)
{
	t.gotoXY(54, 8);
	cout << "��������";
	t.gotoXY(51, 10);
	cout << "���������������󸴻��";
	t.gotoXY(51, 11);
	cout << "Թ��, ������ǰ��һ����";
	t.gotoXY(51, 12);
	cout << "���������������Ĺ��ߡ�";
	t.gotoXY(51, 14);
	cout << "----OMORI";
}

