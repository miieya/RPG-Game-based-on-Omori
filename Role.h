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

    //״̬���
    void EmoStatus();
    //buff���
    int BuffState(int bufftype, int ProperType);
    //����
    int Provision(int ProvisionType, int ProperType);


    Property Property_Def;  //��������
    Property Property_Inbattle; //ս��������
    FightChoose InfightChoose;  //���غϣ���ѡ���չ�/����/��ʳ/��ߣ�

    //����
    Emo_Status emo;     // ��ǰ����״̬
    // �ȼ�
    int level;
    //ս��buff
    int buff;
    int debuff;

    int FinalStatus;    // ����״̬
};

#endif // !ROLE


