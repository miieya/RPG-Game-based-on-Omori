#ifndef ITEM
#define ITEM
#include "Property.h"
#include <map>
#include <string>

enum Snacks;
enum Toys;

class Item
{
public:

    Item();
    Item(int type, int cost);
    virtual ~Item();

    Property Property;  //����
    int type; //��Ӧö��
    int pay;  //�۸�
};

class snack :public Item
{
public:

    snack();
    snack(int type, int cost);
    virtual ~snack();

    Snacks SackPack;  //��ʳ
};

class Toy :public Item
{
public:

    Toy();
    Toy(int type, int cost);
    virtual ~Toy();

    Toys ToysType;    //���
};

// ��Ʒ
enum Snacks
{
    Tofu = 1,          //1.����
    Candy,             //2.�ǹ�
    Donut,             //3.����Ȧ
    Popcorn,           //4.���׻�
    PlumJuice,         //5.÷��֭
    BreadfruitJuice,   //6.�����֭
    MangoSmoothie,     //7.â����ɳ
    PeachSoda,         //8.������ˮ
    coffee,            //9.����
    LifeJam            //10.��������
};

//���
enum Toys
{
    Sparkler = 1,  //1.�̻���  ��һ�����ѻ���˱�ÿ���
    Confetti,      //2.���ֽƬ �����ж��ѱ�ÿ���
    PoetryBook,    //3.ʫ��  ��һ�����ѻ���˱�ñ���
    RainCloud,     //4.����
    Present,       //5.����
    AirHorn,       //6.�������� �����ж��ѱ������
    Dandelion      //7.�ѹ�Ӣ   ����һ�����ѻ���˵�����
};

const std::map<Snacks, std::string> Map_Snacks = {
    {Snacks::Tofu, "����"},
    {Snacks::Candy, "�ǹ�"},
    {Snacks::Donut, "����Ȧ"},
    {Snacks::Popcorn, "���׻�"},
    {Snacks::PlumJuice, "÷��֭"},
    {Snacks::BreadfruitJuice, "�����֭"},
    {Snacks::MangoSmoothie, "â����ɳ ȫ��ظ�40MP"},
    {Snacks::PeachSoda, "������ˮ"},
    {Snacks::coffee, "����"},
    {Snacks::LifeJam, "��������"},
};

const std::map<Toys, std::string> Map_Toys = {
    {Toys::Sparkler, "�̻��� "},
    {Toys::Confetti, "���ֽƬ"},
    {Toys::PoetryBook, "ʫ�� "},
    {Toys::RainCloud, "����"},
    {Toys::Present, "����"},
    {Toys::AirHorn, "��������"},
    {Toys::Dandelion, "�ѹ�Ӣ  ����һ�����ѻ���˵�����"},
};

#endif // !ITEM


