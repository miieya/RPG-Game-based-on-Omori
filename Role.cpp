#include "Role.h"
#include <string>
#include <random>
using namespace std;

Role::Role() : Property_Def(), Property_Inbattle(), InfightChoose(Nothing), emo(Normal),
level(0), buff(0), debuff(0), FinalStatus(0) {};

Role::~Role() {};

//基础参数初始化
void Role::Property_Set(int hp, int MP, int atk, int def, int spd, int luck, int hit)
{
    this->Property_Def.HP = hp;
    this->Property_Def.MP = MP;
    this->Property_Def.Atk = atk;
    this->Property_Def.Def = def;
    this->Property_Def.Spd = spd;
    this->Property_Def.Luck = luck;
    this->Property_Def.Hit = hit;
}

//战斗中参数设置
void Role::Property_Inbattle_Set(Property Proper)
{
    this->Property_Inbattle.HP = Proper.HP;
    this->Property_Inbattle.MP = Proper.MP;
    this->Property_Inbattle.Atk = Proper.Atk;
    this->Property_Inbattle.Def = Proper.Def;
    this->Property_Inbattle.Spd = Proper.Spd;
    this->Property_Inbattle.Luck = Proper.Luck;
    this->Property_Inbattle.Hit = Proper.Hit;
}

//属性处理(直接增加数值形式)
void Role::Property_Handle(Property ProperType, HandleType handle, double ratio)
{
    //根据属性中的枚举名称处理
    switch (ProperType.InfightPropertype)
    {
    case HP:
        if (handle == Add)
        {
            if (this->Property_Inbattle.HP += this->Property_Def.HP * ratio > this->Property_Def.HP)
                this->Property_Inbattle.HP = this->Property_Def.HP;
            else
                this->Property_Inbattle.HP += this->Property_Def.HP * ratio;
        }
        else if (handle == Sub)
        {
            this->Property_Inbattle.HP -= this->Property_Def.HP * ratio;
            if (this->Property_Inbattle.HP < 0)
                this->Property_Inbattle.HP = 0;
        }
        break;
    case MP:
        if (handle == Add)
        {
            if (this->Property_Inbattle.MP += this->Property_Def.MP * ratio > this->Property_Def.MP)
                this->Property_Inbattle.MP = this->Property_Def.MP;
            else
                this->Property_Inbattle.MP += this->Property_Def.MP * ratio;
        }
        else if (handle == Sub)
        {
            this->Property_Inbattle.MP -= this->Property_Def.MP * ratio;
            if (this->Property_Inbattle.MP < 0)
                this->Property_Inbattle.MP = 0;
        }
        break;
    case Atk:
        if (handle == Add)
        {
            this->Property_Inbattle.Atk += this->Property_Def.Atk * ratio;
        }
        else if (handle == Sub)
        {
            this->Property_Inbattle.Atk -= this->Property_Def.Atk * ratio;
            if (this->Property_Inbattle.Atk < 0)
                this->Property_Inbattle.Atk = 0;
        }
        break;
    case Def:
        if (handle == Add)
        {
            this->Property_Inbattle.Def += this->Property_Def.Def * ratio;
        }
        else if (handle == Sub)
        {
            this->Property_Inbattle.Def -= this->Property_Def.Def * ratio;
            if (this->Property_Inbattle.Def < 0)
                this->Property_Inbattle.Def = 0;
        }
        break;
    case Spd:
        if (handle == Add)
        {
            this->Property_Inbattle.Spd += this->Property_Def.Spd * ratio;
        }
        else if (handle == Sub)
        {
            this->Property_Inbattle.Spd -= this->Property_Def.Spd * ratio;
            if (this->Property_Inbattle.Spd < 0)
                this->Property_Inbattle.Spd = 0;
        }
        break;
    case Luck:
        if (handle == Add)
        {
            this->Property_Inbattle.Luck += this->Property_Def.Luck * ratio;
        }
        else if (handle == Sub)
        {
            this->Property_Inbattle.Luck -= this->Property_Def.Luck * ratio;
            if (this->Property_Inbattle.Luck < 0)
                this->Property_Inbattle.Luck = 0;
        }
        break;
    case Hit:
        if (handle == Add)
        {
            this->Property_Inbattle.Hit += this->Property_Def.Hit * ratio;
        }
        else if (handle == Sub)
        {
            this->Property_Inbattle.Hit -= this->Property_Def.Hit * ratio;
            if (this->Property_Inbattle.Hit < 0)
                this->Property_Inbattle.Hit = 0;
        }
        break;
    default:
        break;
    }
}

//属性处理(百分数处理形式)
void Role::Property_FightPropertyHandle(Property fightProperty)
{
    //根据属性中的枚举名称处理
    switch (fightProperty.InfightPropertype)
    {
    case HP:
        this->Property_Inbattle.HP *= (fightProperty.scale + 1);
        break;
    case MP:
        this->Property_Inbattle.MP *= (fightProperty.scale + 1);
        break;
    case Atk:
        this->Property_Inbattle.Atk *= (fightProperty.scale + 1);
        break;
    case Def:
        this->Property_Inbattle.Def *= (fightProperty.scale + 1);
        break;
    case Spd:
        this->Property_Inbattle.Spd *= (fightProperty.scale + 1);
        break;
    case Luck:
        this->Property_Inbattle.Luck *= (fightProperty.scale + 1);
        break;
    case Hit:
        this->Property_Inbattle.Hit *= (fightProperty.scale + 1);
        break;
    case Emochange:
        this->emo = fightProperty.EmoChange;
        break;
    }
}

//用于角色的全属性提高
void Role::Property_AddHandle(Property Property)
{
    this->Property_Inbattle.HP += Property.HP;
    this->Property_Inbattle.MP += Property.MP;
    this->Property_Inbattle.Atk += Property.Atk;
    this->Property_Inbattle.Def += Property.Def;
    this->Property_Inbattle.Spd += Property.Spd;
    this->Property_Inbattle.Luck += Property.Luck;
    this->Property_Inbattle.Hit += Property.Hit;
}

//情绪状态
void Role::EmoStatus()
{
    string str = "";

    // 战斗参数
    Property Proper = this->Property_Def; //基础初始属性
    Emo_Status emostate = this->emo;

    switch (emostate)
    {
    case Normal:
        str = str + "正常";
        break;
    case HAPPY:
    {
        str = str + "开心";
        //提升幸运
        Proper.Luck = this->Property_Def.Luck * 2;
        //提升速度
        Proper.Spd = this->Property_Def.Spd * 1.25;
        //降低命中率
        Proper.Hit = this->Property_Def.Hit * (1 - 0.1);
        break;
    }
    case ECSTATIC:
    {
        str = str + "狂喜";
        //提升幸运
        Proper.Luck = this->Property_Def.Luck * 3;
        //提升速度
        Proper.Spd = this->Property_Def.Spd * 1.50;
        //降低命中率
        Proper.Hit = this->Property_Def.Hit * (1 - 0.2);
        break;
    }
    case MANIC:
    {
        str = str + "癫狂";
        //提升幸运
        Proper.Luck = this->Property_Def.Luck * 4;
        //提升速度
        Proper.Spd = this->Property_Def.Spd * 2;
        //降低命中率
        Proper.Hit = this->Property_Def.Hit * (1 - 0.3);
        break;
    }
    case ANGRY:
    {
        str = str + "生气";
        //提升攻击
        Proper.Atk = this->Property_Def.Atk * 1.30;
        //降低防御
        Proper.Def = this->Property_Def.Def * (1 - 0.5);
        break; }
    case ENRAGED: {
        str = str + "愤怒";
        //提升攻击
        Proper.Atk = this->Property_Def.Atk * 1.50;
        //降低防御
        Proper.Def = this->Property_Def.Def * (1 - 0.7);
        break; }
    case FURIOUS: {
        str = str + "狂怒";
        //提升攻击
        Proper.Atk = this->Property_Def.Atk * 2.0;
        //降低防御
        Proper.Def = this->Property_Def.Def * (1 - 0.85);
        break; }
    case SAD: {
        str = str + "悲伤";
        //提升防御
        Proper.Def = this->Property_Def.Def * 1.25;
        //降低速度
        Proper.Spd = this->Property_Def.Spd * (1 - 0.2);
        //消耗活力
        Proper.MP = this->Property_Def.MP * (1 - 0.3);
        break; }
    case DEPRESSED: {
        str = str + "抑郁";
        //提升防御
        Proper.Def = this->Property_Def.Def * 1.35;
        //降低速度
        Proper.Spd = this->Property_Def.Spd * (1 - 0.35);
        //消耗活力
        Proper.MP = this->Property_Def.MP * (1 - 0.50);
        break; }
    case MISERABLE: {
        str = str + "痛苦";
        //提升防御
        Proper.Def = this->Property_Def.Def * 1.50;
        //降低速度
        Proper.Spd = this->Property_Def.Spd * (1 - 0.50);
        //消耗活力
        Proper.MP = this->Property_Def.MP * 0;
        break; }
    default:
        break;
    }
    //战斗参数处理
//    Property_Handle(Proper);

    str = str + "起来了！\n";
    //    printf("%s",str);
}

//计算普攻  damage_multiplier为普攻系数
double Role::calc_baseDamage(Role* defender, int damage_multiplier)
{
    double base_damage = this->Property_Inbattle.Atk * damage_multiplier - defender->Property_Inbattle.Def;
    if (base_damage < 0)
        base_damage = 0;

    return base_damage;
}

std::default_random_engine generator; //产生随机数
//计算最终伤害
int Role::calc_Damage(Role* defender, int damage_multiplier, int if_crit) //if_crit判断能否暴击
{
    // 计算普攻伤害
    double base_damage = calc_baseDamage(defender, damage_multiplier);

    // 情绪系数
    double emo_multiplier = 1.0;
    if ((this->emo == HAPPY && defender->emo == ANGRY) ||
        (this->emo == ANGRY && defender->emo == SAD) ||
        (this->emo == SAD && defender->emo == HAPPY)) {
        emo_multiplier = 1.5;
    }
    else if ((this->emo == HAPPY && defender->emo == SAD) ||
        (this->emo == ANGRY && defender->emo == HAPPY) ||
        (this->emo == SAD && defender->emo == ANGRY)) {
        emo_multiplier = 0.8;
    }

    // 暴击系数 随机系数小于luck并且可以暴击(if_crit=1)  if_crit=2必定暴击
    double crit_multiplier = 1;
    if (if_crit != 2)
    {
        std::uniform_real_distribution<double> distribution(0.0, 100);
        crit_multiplier = (distribution(generator) < this->Property_Inbattle.Luck) && (if_crit == 1) ? 1.5 : 1.0;
    }
    else
        crit_multiplier = 1.5;

    // 浮动系数
    std::uniform_real_distribution<double> float_distribution(0.8, 1.2);
    double float_multiplier = float_distribution(generator);

    // 计算总伤害
    int total_damage = static_cast<int>(base_damage * emo_multiplier * crit_multiplier * float_multiplier);

    // 如果被攻击者的情绪为SAD，他将受到的伤害减少30%，并将这部分伤害转换为MP
    if (defender->emo == SAD) {
        double reduced_damage = total_damage * 0.3;
        total_damage -= reduced_damage;
        defender->Property_Inbattle.MP += reduced_damage;
    }

    return total_damage;
}