#include "Role.h"
#include <string>
#include <random>
using namespace std;

Role::Role() : Property_Def(), Property_Inbattle(), InfightChoose(Nothing), emo(Normal),
level(0), buff(0), debuff(0), FinalStatus(0) {};

Role::~Role() {};

//����������ʼ��
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

//ս���в�������
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

//���Դ���(ֱ��������ֵ��ʽ)
void Role::Property_Handle(Property ProperType, HandleType handle, double ratio)
{
    //���������е�ö�����ƴ���
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

//���Դ���(�ٷ���������ʽ)
void Role::Property_FightPropertyHandle(Property fightProperty)
{
    //���������е�ö�����ƴ���
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

//���ڽ�ɫ��ȫ�������
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

//����״̬
void Role::EmoStatus()
{
    string str = "";

    // ս������
    Property Proper = this->Property_Def; //������ʼ����
    Emo_Status emostate = this->emo;

    switch (emostate)
    {
    case Normal:
        str = str + "����";
        break;
    case HAPPY:
    {
        str = str + "����";
        //��������
        Proper.Luck = this->Property_Def.Luck * 2;
        //�����ٶ�
        Proper.Spd = this->Property_Def.Spd * 1.25;
        //����������
        Proper.Hit = this->Property_Def.Hit * (1 - 0.1);
        break;
    }
    case ECSTATIC:
    {
        str = str + "��ϲ";
        //��������
        Proper.Luck = this->Property_Def.Luck * 3;
        //�����ٶ�
        Proper.Spd = this->Property_Def.Spd * 1.50;
        //����������
        Proper.Hit = this->Property_Def.Hit * (1 - 0.2);
        break;
    }
    case MANIC:
    {
        str = str + "��";
        //��������
        Proper.Luck = this->Property_Def.Luck * 4;
        //�����ٶ�
        Proper.Spd = this->Property_Def.Spd * 2;
        //����������
        Proper.Hit = this->Property_Def.Hit * (1 - 0.3);
        break;
    }
    case ANGRY:
    {
        str = str + "����";
        //��������
        Proper.Atk = this->Property_Def.Atk * 1.30;
        //���ͷ���
        Proper.Def = this->Property_Def.Def * (1 - 0.5);
        break; }
    case ENRAGED: {
        str = str + "��ŭ";
        //��������
        Proper.Atk = this->Property_Def.Atk * 1.50;
        //���ͷ���
        Proper.Def = this->Property_Def.Def * (1 - 0.7);
        break; }
    case FURIOUS: {
        str = str + "��ŭ";
        //��������
        Proper.Atk = this->Property_Def.Atk * 2.0;
        //���ͷ���
        Proper.Def = this->Property_Def.Def * (1 - 0.85);
        break; }
    case SAD: {
        str = str + "����";
        //��������
        Proper.Def = this->Property_Def.Def * 1.25;
        //�����ٶ�
        Proper.Spd = this->Property_Def.Spd * (1 - 0.2);
        //���Ļ���
        Proper.MP = this->Property_Def.MP * (1 - 0.3);
        break; }
    case DEPRESSED: {
        str = str + "����";
        //��������
        Proper.Def = this->Property_Def.Def * 1.35;
        //�����ٶ�
        Proper.Spd = this->Property_Def.Spd * (1 - 0.35);
        //���Ļ���
        Proper.MP = this->Property_Def.MP * (1 - 0.50);
        break; }
    case MISERABLE: {
        str = str + "ʹ��";
        //��������
        Proper.Def = this->Property_Def.Def * 1.50;
        //�����ٶ�
        Proper.Spd = this->Property_Def.Spd * (1 - 0.50);
        //���Ļ���
        Proper.MP = this->Property_Def.MP * 0;
        break; }
    default:
        break;
    }
    //ս����������
//    Property_Handle(Proper);

    str = str + "�����ˣ�\n";
    //    printf("%s",str);
}

//�����չ�  damage_multiplierΪ�չ�ϵ��
double Role::calc_baseDamage(Role* defender, int damage_multiplier)
{
    double base_damage = this->Property_Inbattle.Atk * damage_multiplier - defender->Property_Inbattle.Def;
    if (base_damage < 0)
        base_damage = 0;

    return base_damage;
}

std::default_random_engine generator; //���������
//���������˺�
int Role::calc_Damage(Role* defender, int damage_multiplier, int if_crit) //if_crit�ж��ܷ񱩻�
{
    // �����չ��˺�
    double base_damage = calc_baseDamage(defender, damage_multiplier);

    // ����ϵ��
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

    // ����ϵ�� ���ϵ��С��luck���ҿ��Ա���(if_crit=1)  if_crit=2�ض�����
    double crit_multiplier = 1;
    if (if_crit != 2)
    {
        std::uniform_real_distribution<double> distribution(0.0, 100);
        crit_multiplier = (distribution(generator) < this->Property_Inbattle.Luck) && (if_crit == 1) ? 1.5 : 1.0;
    }
    else
        crit_multiplier = 1.5;

    // ����ϵ��
    std::uniform_real_distribution<double> float_distribution(0.8, 1.2);
    double float_multiplier = float_distribution(generator);

    // �������˺�
    int total_damage = static_cast<int>(base_damage * emo_multiplier * crit_multiplier * float_multiplier);

    // ����������ߵ�����ΪSAD�������ܵ����˺�����30%�������ⲿ���˺�ת��ΪMP
    if (defender->emo == SAD) {
        double reduced_damage = total_damage * 0.3;
        total_damage -= reduced_damage;
        defender->Property_Inbattle.MP += reduced_damage;
    }

    return total_damage;
}