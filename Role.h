#ifndef ROLE
#define ROLE
#include"Property.h"

class Role
{
public:

    Role();
    virtual ~Role();

    void Property_Set(int hp, int MP, int atk, int def, int spd, int luck, int hit);
    void Property_Inbattle_Set(Property Proper);

    void Property_Handle(Property ProperType, HandleType handle, double ratio);
    void Property_AddHandle(Property Property);
    void Property_FightPropertyHandle(Property fightProperty);

    double calc_baseDamage(Role* defender, int damage_multiplier);
    int calc_Damage(Role* defender, int damage_multiplier, int if_crit);

    //状态检测
    void EmoStatus();
    //buff检测
    int BuffState(int bufftype, int ProperType);
    //补给
    int Provision(int ProvisionType, int ProperType);


    Property Property_Def;  //基础属性
    Property Property_Inbattle; //战斗中属性
    FightChoose InfightChoose;  //单回合：打斗选择（普攻/技能/零食/玩具）

    //情绪
    Emo_Status emo;     // 当前情绪状态
    // 等级
    int level;
    //战中buff
    int buff;
    int debuff;

    int FinalStatus;    // 最终状态
};

#endif // !ROLE


