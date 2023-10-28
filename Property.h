//人物属性类
#ifndef PROPERTY
#define PROPERTY
#include "Define.h"

//属性名称枚举
enum Role_Property
{
    HP, MP, Atk, Def, Spd, Luck, Hit, Hurt, Emochange //情绪变化
};

//处理类型
enum HandleType { Add, Sub };

//判断单体or群体
enum Part { single = 1, all, enemy_single, enemy_all };

class Property
{
public:

    Property() : HP(0), MP(0.0), Atk(0.0), Def(0.0), Spd(0.0), Luck(0.0), Hit(0.0), Part(single),
        InfightPropertype(Role_Property::HP), Handle(Add), scale(0.0), EmoChange(Normal), times(0) {}

    int HP;     //生命值
    double MP;     //活力
    double Atk;    //攻击
    double Def;    //防御
    double Spd;    //速度
    double Luck;   //幸运(暴击率)
    double Hit;    //命中率

    //基础共性
    Part    Part;                           //范围
    Role_Property   InfightPropertype;      //属性加成类型

    //属性变化
    HandleType  Handle;                     //处理(+ / -)
    float   scale;

    //情绪变化
    Emo_Status  EmoChange;                  //情绪

    //次数变化
    int times;
};

#endif // !PROPERTY


