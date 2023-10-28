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

    Weapon WeaponType;        //类型、名称(枚举)
    Property WeaponProperty;  //武器属性

};

//枚举名字
enum Weapon
{
    ShinyKnife = 1, //1.闪亮的刀子(Shiny Knife)： ATK+5 HIT+100%
    RustyKnife,     //2.生锈的刀子(Rusty Knife)： ATK+11， DEF+2 ， SPD+6，LUCK+4， HIT+100%
    RedKnife,       //3.红色小刀(Red Knife)： ATK+13, DEF+6, SPD+6, LUCK+6, HIT+100%

    StuffedToy,     //1.填充玩偶(Stuffed Toy)：ATK+4, HIT+100%
    Pillow,         //2.抱枕(Pillow)：HP+10，ATK+8，HIT+100%
    BaseballBat,    //3棒球棍(Baseball Bat)：HP+10, ATK+20， SPD+10, LUCK+10, HIT+100

    RubberBall,     //1.橡胶球(Rubber Ball)：ATK+3,HIT+100%
    Coconut,        //2.椰子(Coconut)：活力+50，ATK+8， HIT+100%
    Basketball,     //3.篮球(Basketball)：活力+50，ATK+15,SPD+100, LUCK+15,HIT+100

    GC,         //1.锅铲：ATK+4,HIT+100%
    JBQ,        //2.搅拌器：活力+30，ATK+7，HIT+100%
    Friend,     //3.可靠的老伙计： HP+20，活力+20， ATK+20，HIT+100%
};

//存储武器详细信息
const std::map<Weapon, std::string> Map_Weapon = {
{Weapon::ShinyKnife ,"闪亮的刀子: ATK+5, HIT+100%"},
{Weapon::RustyKnife, "生锈的刀子: Atk+11, DEF+2, SPD+6, LUCK+4, HIT+100%"},
{Weapon::RedKnife, "红色小刀: ATK+13, DEF+6, SPD+6, LUCK+6, HIT+100%"},
{Weapon::StuffedToy, "填充玩偶: ATK+4, HIT+100%"},
{Weapon::Pillow,     "抱枕: HP+10, ATK+8, HIT+100%"},
{Weapon::BaseballBat,"棒球棍: HP+10, ATK+20, SPD+10, LUCK+10, HIT+100"},

{Weapon::RubberBall, "橡胶球: ATK+3, HIT+100%"},
{Weapon::Coconut,    "椰子: 活力+50, ATK+8, HIT+100%"},
{Weapon::Basketball, "篮球: 活力+50, ATK+15, SPD+100, LUCK+15, HIT+100"},

{Weapon::GC,        "锅铲: ATK+4, HIT+100%"},
{Weapon::JBQ,       "搅拌器: 活力+30, ATK+7, HIT+100%"},
{Weapon::Friend,    "可靠的老伙计: HP+20, 活力+20, ATK+20, HIT+100%"},
};
extern const map<Weapon, string> Map_Weapon;

#endif // !WEAPON


