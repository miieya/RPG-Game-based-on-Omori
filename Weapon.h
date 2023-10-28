#ifndef WEAPON
#define WEAPON
#include <map>
#include <string>
using namespace std;
#include "Property.h"

enum Weapon;

class weapon
{
public:

    weapon();

    Weapon WeaponType;        //���͡�����(ö��)
    Property WeaponProperty;  //��������

};

//ö������
enum Weapon
{
    ShinyKnife = 1, //1.�����ĵ���(Shiny Knife)�� ATK+5 HIT+100%
    RustyKnife,     //2.����ĵ���(Rusty Knife)�� ATK+11�� DEF+2 �� SPD+6��LUCK+4�� HIT+100%
    RedKnife,       //3.��ɫС��(Red Knife)�� ATK+13, DEF+6, SPD+6, LUCK+6, HIT+100%

    StuffedToy,     //1.�����ż(Stuffed Toy)��ATK+4, HIT+100%
    Pillow,         //2.����(Pillow)��HP+10��ATK+8��HIT+100%
    BaseballBat,    //3�����(Baseball Bat)��HP+10, ATK+20�� SPD+10, LUCK+10, HIT+100

    RubberBall,     //1.����(Rubber Ball)��ATK+3,HIT+100%
    Coconut,        //2.Ҭ��(Coconut)������+50��ATK+8�� HIT+100%
    Basketball,     //3.����(Basketball)������+50��ATK+15,SPD+100, LUCK+15,HIT+100

    GC,         //1.������ATK+4,HIT+100%
    JBQ,        //2.������������+30��ATK+7��HIT+100%
    Friend,     //3.�ɿ����ϻ�ƣ� HP+20������+20�� ATK+20��HIT+100%
};

//�洢������ϸ��Ϣ
const std::map<Weapon, std::string> Map_Weapon = {
{Weapon::ShinyKnife ,"�����ĵ���: ATK+5, HIT+100%"},
{Weapon::RustyKnife, "����ĵ���: Atk+11, DEF+2, SPD+6, LUCK+4, HIT+100%"},
{Weapon::RedKnife, "��ɫС��: ATK+13, DEF+6, SPD+6, LUCK+6, HIT+100%"},
{Weapon::StuffedToy, "�����ż: ATK+4, HIT+100%"},
{Weapon::Pillow,     "����: HP+10, ATK+8, HIT+100%"},
{Weapon::BaseballBat,"�����: HP+10, ATK+20, SPD+10, LUCK+10, HIT+100"},

{Weapon::RubberBall, "����: ATK+3, HIT+100%"},
{Weapon::Coconut,    "Ҭ��: ����+50, ATK+8, HIT+100%"},
{Weapon::Basketball, "����: ����+50, ATK+15, SPD+100, LUCK+15, HIT+100"},

{Weapon::GC,        "����: ATK+4, HIT+100%"},
{Weapon::JBQ,       "������: ����+30, ATK+7, HIT+100%"},
{Weapon::Friend,    "�ɿ����ϻ��: HP+20, ����+20, ATK+20, HIT+100%"},
};
extern const map<Weapon, string> Map_Weapon;

#endif // !WEAPON


