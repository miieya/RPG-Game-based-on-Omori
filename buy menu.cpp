#include<windows.h>
#include"buy menu.h"
#include"treemap.h"
#include<iostream>
using namespace std;

//Pack BuyMenu::MyPack;

void BuyMenu::map_Print(Tool& t, Fight& fight)
{
	t.gotoXY(40, 5);
	cout << "��ӭ�㣬���Ĺ˿ͣ�";
	t.gotoXY(42, 7);
	cout << "����Ҫ����ʲô��               ���: " << fight.MyPack.GoldCoin;
	t.gotoXY(46, 9);
	cout << "��ʳ";
	t.gotoXY(46, 10);
	cout << "����       2���";
	t.gotoXY(46, 11);
	cout << "�ǹ�      20���";
	t.gotoXY(46, 12);
	cout << "÷��֭     5���";
	t.gotoXY(46, 13);
	cout << "�����֭  20���";
	t.gotoXY(46, 15);
	cout << "���";
	t.gotoXY(46, 16);
	cout << "���ֽƬ  50���";
	t.gotoXY(46, 17);
	cout << "����      50���";
	t.gotoXY(46, 18);
	cout << "��������  50���";

	for (int i = 0; i < 4; ++i)
	{
		t.gotoXY(68, 10 + i);
		cout << "�鿴";
		t.gotoXY(76, 10 + i);
		cout << "����";
	}

	for (int i = 0; i < 3; i++)
	{
		t.gotoXY(68, 16 + i);
		cout << "�鿴";
		t.gotoXY(76, 16 + i);
		cout << "����";
	}
}

void BuyMenu::tofu(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "����";
	const char* str2 = "������ûʲôζ������";
	const char* str3 = "�ָ�5��HP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::candy(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "�ǹ�";
	const char* str2 = "С������ϲ������ʳ������ģ�";
	const char* str3 = "�ָ�30��HP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::pulm_juice(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "÷��֭";
	const char* str2 = "��������ģ���úȣ�";
	const char* str3 = "�ָ�15��MP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::breadfruit_juice(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "�����֭";
	const char* str2 = "����ħ��ֵ�Ļָ�����Ч���������԰ɣ�";
	const char* str3 = "�ָ�50��MP";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.gotoXY(40, 23);
	t.printMessage_Quick(str3);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
	t.clearLine(40, 23);
}

void BuyMenu::confetti(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "�������";
	const char* str2 = "�����ж��ѱ�ÿ���";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
}

void BuyMenu::rain_cloud(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "����";
	const char* str2 = "�����ж��ѱ�ñ���";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
}

void BuyMenu::air_horn(Tool& t)
{
	t.gotoXY(40, 21);
	const char* str1 = "��������";
	const char* str2 = "�����ж��ѱ������";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 22);
	t.printMessage_Quick(str2);
	t.wait(2000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);
}

void BuyMenu::buytofu(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 0, fight.MyPack);
	//shop.InShopping(1, 1, MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "��������ٸ���";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "��Щ����һ����";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 2 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "���";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buycandy(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 1, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "��������ٸ���";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "��Щ����һ����";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 20 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "���";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buypulm_juice(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 4, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "��������ٸ���";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "��Щ����һ����";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 5 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "���";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buybreadfruit_juice(Tool& t, Fight& fight)
{
	fight.goods->InShopping(1, 5, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "��������ٸ���";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "��Щ����һ����";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 20 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "���";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buyconfetti(Tool& t, Fight& fight)
{
	fight.goods->InShopping(2, 1, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "��������ٸ���";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "��Щ����һ����";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 50 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "���";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buyrain_cloud(Tool& t, Fight& fight)
{
	fight.goods->InShopping(2, 3, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "��������ٸ���";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "��Щ����һ����";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 50 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "���";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buyair_horn(Tool& t, Fight& fight)
{
	fight.goods->InShopping(2, 5, fight.MyPack);
	/*int quantity = 0;
	t.gotoXY(40, 21);
	const char* str1 = "��������ٸ���";
	t.printMessage_Quick(str1);
	t.gotoXY(54, 21);
	cin >> quantity;
	t.gotoXY(40, 22);
	const char* str2 = "��Щ����һ����";
	t.printMessage_Quick(str2);
	t.gotoXY(54, 22);
	const int str3 = 50 * quantity;
	Sleep(500);
	cout << str3;
	t.gotoXY(58, 22);
	const char* str4 = "���";
	t.printMessage_Quick(str4);
	t.wait(3000);
	t.clearLine(40, 21);
	t.clearLine(40, 22);*/
	buy_choose(t, fight);
}

void BuyMenu::buy_choose(Tool& t, Fight& fight)
{
	t.gotoXY(40, 22);
	const char* str1 = "��Ҫ��������";
	t.printMessage_Quick(str1);
	t.gotoXY(40, 23);
	cout << "����� (Y��)";
	t.gotoXY(40, 24);
	cout << "������ (N��)";

	char choose;
	while (true)
	{
		t.gotoXY(50, 25);
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
			treemap v;
			switch (choose)
			{
			case 'Y':  //��������
				//��������
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 22 + i);
				}
				t.gotoXY(40, 25);

				//һ��ʱ���������ʺ�����ͼ�����½����ͼ
				t.wait(200);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);
				system("cls");
				Execute_buymenu(t, 0, fight);
				break;
			case 'y':  //ͬ'Y'
				for (int i = 0; i <= 4; i++)
				{
					t.clearLine(40, 21 + i);
				}
				t.gotoXY(40, 25);
				t.wait(200);
				t.clearLine(40, 20);
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				cout << " ";
				t.clearLine(58, 7);
				system("cls");
				Execute_buymenu(t, 0, fight);
				break;
			case 'N':  //�뿪
				//����������ʺ�����ͼ�����½����ͼ
				for (int i = 0; i <= 3; i++)
				{
					t.clearLine(40, 22 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				system("cls");
				if (v.ifSuccess == -1)
					v.Execute_treemap(t, 0, 1);
				else
					v.Execute_treemap(t, 0, 2);
				break;
			case 'n':  //ͬ'N'
				for (int i = 0; i <= 3; i++)
				{
					t.clearLine(40, 21 + i);
				}
				t.gotoXY(57, 6);
				cout << " ";
				t.gotoXY(60, 6);
				t.clearLine(58, 7);
				system("cls");
				if (v.ifSuccess == -1)
					v.Execute_treemap(t, 0, 1);
				else
					v.Execute_treemap(t, 0, 2);
				break;
			default:
				throw std::runtime_error("��������,���������룡");
			}
		}

		catch (const std::exception& e)
		{
			cin.clear(); // �������״̬
			//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���Դ��������

			//����
			t.clearLine(40, 25);
			t.clearLine(40, 26);
			t.gotoXY(40, 25);
			cout << e.what() << endl;
			t.wait(500);
			t.clearLine(40, 25);
			buy_choose(t,fight);
		}
	}
}

void BuyMenu::Position(int x0, int y0, int x1, int y1, Tool& t)
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
int BuyMenu::ClueJudge(int x1, int y1)
{
	int number = map[y1][x1];
	return number;
}

//�ж�����λ���ж�
void BuyMenu::Movement(int number, int& x0, int& y0, int x1, int y1, Tool& t, Fight& fight)
{
	//x0,y0Ϊ��ǰλ�ã�x1,y1Ϊ����Ҫ�ƶ�����λ��
	switch (number)
	{
	case 0:  //���ƶ� -- ����ͼ��䶯��������λ��
		Position(x0, y0, x1, y1, t);
		x0 = x1;
		y0 = y1;
		break;
	case 1:
		break;
	case 2:
		tofu(t);
		break;
	case 3:
		candy(t);
		break;
	case 4:
		pulm_juice(t);
		break;
	case 5:
		breadfruit_juice(t);
		break;
	case 6:
		confetti(t);
		break;
	case 7:
		rain_cloud(t);
		break;
	case 8:
		air_horn(t);
		break;
	case 12:
		buytofu(t, fight);
		break;
	case 13:
		buycandy(t, fight);
		break;
	case 14:
		buypulm_juice(t, fight);
		break;
	case 15:
		buybreadfruit_juice(t, fight);
		break;
	case 16:
		buyconfetti(t, fight);
		break;
	case 17:
		buyrain_cloud(t, fight);
		break;
	case 18:
		buyair_horn(t, fight);
		break;
	default:
		break;
	}
}

//ִ�к���
void BuyMenu::Execute_buymenu(Tool& t, int judge, Fight& fight)
{
	//judge==1ʱΪ���ҳ�棬����Ϊѡ��أ����½����ͼ���
	if (judge == 1)
	{
		t.wait(1000);
	}

	map_Print(t, fight);

	t.gotoXY(28, 11);
	int x0 = 5, y0 = 6, x1 = 9, y1 = 17;
	int clue;

	while (1)
	{
		t.sidejudge(x1, y1);
		clue = ClueJudge(x1, y1);
		Movement(clue, x0, y0, x1, y1, t, fight);
		x1 = x0;
		y1 = y0;
	}
}