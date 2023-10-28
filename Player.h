#ifndef PLAYER
#define PLAYER
#include "Role.h"
#include "Skill.h"
#include "SkillBase.h"
#include "Weapon.h"
#include "Define.h"
#include <string>
#include <map>

enum player_;

class Player :public Role
{
public:

    Player();
    Player(int hp, int MP, int atk, int def, int spd, int luck, int hit);
    virtual ~Player();

    void Set_Describe(const string& object, int damage);

    player_ PlayRole;       //角色名称
    Weapon  WeaponType;     //武器（枚举）
    PlayerSkill Skills[7];   //可选技能
    PlayerSkill  SkillTack; //携带的4个(技能槽)
    skill CurrentSkill;     //当前回合选择的
};

//玩家名字
enum player_ { Player_A, Player_B, Player_C, Player_D };

const std::map<player_, std::string> Map_Player = {
    {Player_A, "Omori"},
    {Player_B, "Aubrey"},
    {Player_C, "Kel"},
    {Player_D, "Hero"},
};
extern const map<player_, string> Map_Player;

#endif // !PLAYER

