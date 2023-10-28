#include "Player.h"
#include "Tool.h"
#include <iostream>
using namespace std;

Player::Player() :PlayRole(Player_A), WeaponType(ShinyKnife) {};

Player::~Player() {};

Player::Player(int hp, int MP, int atk, int def, int spd, int luck, int hit)
{
    //基础参数初始化
    Property_Set(hp, MP, atk, def, spd, luck, hit);

    Property_Inbattle_Set(this->Property_Def);
}

void Player::Set_Describe(const string& object, int damage)
{
    Tool t;
    switch (this->InfightChoose)
    {
    case NormalAttack:
        t.gotoXY(47, 3);
        cout << Map_Player.at(this->PlayRole) << "攻击了 " << object;
        t.gotoXY(47, 4);
        cout << object << "受到 " << damage << " 伤害!";
        break;
    case Skill:
        break;
    case Snack:
        break;
    case tOy:
        break;
    default:
        break;
    }

}



