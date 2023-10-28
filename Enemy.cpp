#include "Enemy.h"
#include "Tool.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

Enemy::Enemy() : Type(Em_1_ForestBunny), CurrentAttack(Em_1_Normal), CurrentSkill(BeCute), AttackObject(0), Skill_useTimes(0), Fight_Num(0) {};

Enemy::~Enemy() {};

Enemy::Enemy(int hp, int MP, int atk, int def, int spd, int luck, int hit, EnemyType type)
{
    //����������ʼ��
    Property_Set(hp, MP, atk, def, spd, luck, hit);

    Property_Inbattle_Set(this->Property_Def);

    this->Type = type;

    //��������
    switch (Type)
    {
    case Em_1_ForestBunny:
        EmoAttackPro[0].probability_1 = 60;
        EmoAttackPro[0].probability_2 = 20;
        EmoAttackPro[0].SkillType = BeCute;

        EmoAttackPro[1].probability_1 = 45;
        EmoAttackPro[1].probability_2 = 20;
        EmoAttackPro[1].SkillType = BeCute;

        EmoAttackPro[2].probability_1 = 20;
        EmoAttackPro[2].probability_2 = 55;
        EmoAttackPro[2].SkillType = SadEyes;

        EmoAttackPro[2].probability_1 = 70;
        EmoAttackPro[2].probability_2 = 10;
        EmoAttackPro[2].SkillType = BeCute;
        break;
    case Em_2_SproutMole:
        EmoAttackPro[0].probability_1 = 60;
        EmoAttackPro[0].probability_2 = 20;
        EmoAttackPro[0].SkillType = RunAround;

        EmoAttackPro[1].probability_1 = 35;
        EmoAttackPro[1].probability_2 = 30;
        EmoAttackPro[1].SkillType = RunAround;

        EmoAttackPro[2].probability_1 = 30;
        EmoAttackPro[2].probability_2 = 65;
        EmoAttackPro[2].SkillType = RunAround;

        EmoAttackPro[2].probability_1 = 50;
        EmoAttackPro[2].probability_2 = 10;
        EmoAttackPro[2].SkillType = RunAround;
        break;
    case Em_3_Mixtape:
        EmoAttackPro[0].probability_1 = 65;
        EmoAttackPro[0].probability_2 = 20;
        EmoAttackPro[0].SkillType = Tangle;

        EmoAttackPro[1].probability_1 = 40;
        EmoAttackPro[1].probability_2 = 20;
        EmoAttackPro[1].SkillType = Tangle;

        EmoAttackPro[2].probability_1 = 35;
        EmoAttackPro[2].probability_2 = 55;
        EmoAttackPro[2].SkillType = Tangle;

        EmoAttackPro[2].probability_1 = 80;
        EmoAttackPro[2].probability_2 = 10;
        EmoAttackPro[2].SkillType = Tangle;
        break;
    case Em_4_Doombox:
        EmoAttackPro[0].probability_1 = 65;
        EmoAttackPro[0].probability_2 = 20;
        EmoAttackPro[0].SkillType = BlastMusic;

        EmoAttackPro[1].probability_1 = 45;
        EmoAttackPro[1].probability_2 = 20;
        EmoAttackPro[1].SkillType = BlastMusic;

        EmoAttackPro[2].probability_1 = 30;
        EmoAttackPro[2].probability_2 = 70;
        EmoAttackPro[2].SkillType = BlastMusic;

        EmoAttackPro[2].probability_1 = 60;
        EmoAttackPro[2].probability_2 = 10;
        EmoAttackPro[2].SkillType = BlastMusic;
        break;
    default:
        break;
    }
}

//�������ʴ���
int Enemy::Attack(int probability_1, int probability_2, Skill_Enemy SkillType, vector<Player*>list_Player, int RandPlayer)
{
    srand(time(0));
    int Rand = rand() % 101;

    if ((Rand > 0) && ((Rand < probability_1))) // �չ�
    {
        this->CurrentAttack = Em_1_Normal;
        int damage = calc_Damage(list_Player.at(RandPlayer), 2, 1);
        list_Player.at(RandPlayer)->Property_Inbattle.HP -= damage;
        return damage;
    }
    else if (Rand < (probability_1 + probability_2))   // ʲôҲ����
    {
        this->CurrentAttack = Em_2_Rest;
    }
    else    //����
    {
        this->CurrentAttack = Em_3_Skill;
        this->CurrentSkill = SkillType;
        int damage = useSkill(list_Player, RandPlayer);
        return damage;
    }
}

int Enemy::useSkill(vector<Player*>list_Player, int RandPlayer)
{
    Tool t;
    int damage1, damage2 = 0;

    switch (this->Type)
    {
    case Em_1_ForestBunny:
        switch (this->CurrentSkill)
        {
        case BeCute: //����һ�˹���
            if (Skill_useTimes != 3) //�ü������������Ч��
            {
                Property p1;
                p1.InfightPropertype = Atk;
                list_Player.at(RandPlayer)->Property_Handle(p1, Sub, 0.1);
                Skill_useTimes++;
                break;
            }
        case SadEyes: //ʹһ�˱�ñ���
            list_Player.at(RandPlayer)->emo = SAD;
            break;
        default:
            break;
        }
        break;
    case Em_2_SproutMole: //�����һ����������˺� ÿ��1.5 x ATK - DEF

        damage1 = calc_Damage(list_Player.at(RandPlayer), 2, 1) + calc_Damage(list_Player.at(RandPlayer), 2, 1);

        if (list_Player.at(RandPlayer)->Property_Inbattle.HP > 0 && damage1 <= list_Player.at(RandPlayer)->Property_Inbattle.HP)
        {
            list_Player.at(RandPlayer)->Property_Inbattle.HP -= damage1;
        }
        else
        {
            damage1 = list_Player.at(RandPlayer)->Property_Inbattle.HP;
            list_Player.at(RandPlayer)->Property_Inbattle.HP = 0;
            if (list_Player.at(RandPlayer)->PlayRole == 'A')
            {
                t.clear(29, 19, 10, 1);
                t.gotoXY(24, 19);
                cout << "����: 0";
            }
            else if (list_Player.at(RandPlayer)->PlayRole == 'B')
            {
                t.clear(29, 4, 10, 1);
                t.gotoXY(24, 4);
                cout << "����: 0";
            }
            else if (list_Player.at(RandPlayer)->PlayRole == 'C')
            {
                t.clear(87, 19, 10, 1);
                t.gotoXY(82, 19);
                cout << "����: 0";
            }
            else if (list_Player.at(RandPlayer)->PlayRole == 'D')
            {
                t.clear(87, 4, 5, 1);
                t.gotoXY(82, 4);
                cout << "����: 0";
            }
        }
        return damage1;
        break;

    case Em_3_Mixtape: //����һ���ٶ�
        if (Skill_useTimes != 3) //���������Ч
        {
            Property p1;
            p1.InfightPropertype = Spd;
            list_Player.at(RandPlayer)->Property_Handle(p1, Sub, list_Player.at(RandPlayer)->Property_Def.Spd * 0.1);
            break;
        }
        break;
    case Em_4_Doombox: //��ȫ���˺� 2 x ATK - DEF ���ᱩ��
        for (int i = 0; i < list_Player.size(); i++)
        {
            damage2 = calc_Damage(list_Player.at(i), 2, 0);
            list_Player.at(i)->Property_Inbattle.HP -= damage2;
        }
        return damage2;
        break;
    default:
        break;
    }
}

//����״̬
void Enemy::EmoStatus(const string& object, vector<Player*>list_Player, int RandPlayer)
{
    Property proper = this->Property_Def;
    Emo_Status emostate = this->emo; //���˵���������
    int damage;

    //���ݵ��˵���������,���ж��������
    switch (emostate)
    {
    case Normal:
        damage = Attack(EmoAttackPro[0].probability_1, EmoAttackPro[0].probability_2, EmoAttackPro[0].SkillType, list_Player, RandPlayer);
        break;
    case HAPPY:
        damage = Attack(EmoAttackPro[1].probability_1, EmoAttackPro[1].probability_2, EmoAttackPro[1].SkillType, list_Player, RandPlayer);
        break;
    case ANGRY:
        damage = Attack(EmoAttackPro[2].probability_1, EmoAttackPro[2].probability_2, EmoAttackPro[2].SkillType, list_Player, RandPlayer);
        break;
    case SAD:
        damage = Attack(EmoAttackPro[3].probability_1, EmoAttackPro[3].probability_2, EmoAttackPro[3].SkillType, list_Player, RandPlayer);
        break;
    default:
        break;
    }
    Set_Describe(object, damage);
}

//�����ͷż��ܵ�����
int Enemy::Set_Describe(const string& object, int damage)
{
    EnemyType type = this->Type;  //��������
    AttackType attack = this->CurrentAttack;  //�����ж�
    Tool t;

    switch (type)
    {
    case Em_1_ForestBunny:
        switch (attack)
        {
        case Em_1_Normal:
            t.gotoXY(47, 3);
            cout << "ɭ������С��ҧ��һ��" << object;
            t.gotoXY(47, 4);
            cout << object << "�ܵ� " << damage << " �˺�!";
            break;
        case Em_2_Rest:
            t.gotoXY(47, 3);
            cout << "ɭ������һ������.";
            break;
        case Em_3_Skill:
            if (CurrentSkill == BeCute)
            {
                t.gotoXY(47, 3);
                cout << "ɭ�����ó�" << object << " wink��һ��! ";
                t.gotoXY(47, 4);
                if (Skill_useTimes <= 3)
                    cout << object << "�Ĺ�����������!";
                else
                    cout << object << "�Ĺ������޷��ٽ�����!";
            }
            else if (CurrentSkill == SadEyes)
            {
                t.gotoXY(47, 3);
                cout << "ɭ���������ĵؿ��� " << object;
                t.gotoXY(47, 3);
                cout << object << "��ñ�����";
            }
            break;
        default:
            break;
        }
        break;
    case Em_2_SproutMole:
        switch (attack)
        {
        case Em_1_Normal:
            t.gotoXY(47, 3);
            cout << "��������ײ����" << object;
            t.gotoXY(47, 4);
            cout << object << "�ܵ� " << damage << " �˺�!";
            break;
        case Em_2_Rest:
            t.gotoXY(47, 3);
            cout << "����������ԭ�ط��˸���.";
            break;
        case Em_3_Skill:
            t.gotoXY(47, 3);
            cout << "�������������ȥ, ײ������" << object;
            t.gotoXY(47, 4);
            cout << object << "�ܵ� " << damage << " �˺�!";
            break;
        default:
            break;
        }
        break;
    case Em_3_Mixtape:
        switch (attack)
        {
        case Em_1_Normal:
            t.gotoXY(47, 3);
            cout << "�����������Ĵ��� " << object;
            t.gotoXY(47, 4);
            cout << object << "�ܵ� " << damage << " �˺�!";
            break;
        case Em_2_Rest:
            t.gotoXY(47, 3);
            cout << "���������Լ�����ס��!";
            break;
        case Em_3_Skill:
            t.gotoXY(47, 3);
            cout << "�������������� " << object;
            t.gotoXY(47, 4);
            cout << object << "���ٶȽ����ˣ�";
            break;
        default:
            break;
        }
        break;
    case Em_4_Doombox:
        switch (attack)
        {
        case Em_1_Normal:
            t.gotoXY(47, 3);
            cout << "������������ײ���� " << object;
            t.gotoXY(47, 4);
            cout << object << "�ܵ� " << damage << " �˺�!";
            break;
        case Em_2_Rest:
            t.gotoXY(47, 3);
            cout << "�����������ڵ���¼����." << endl;
            break;
        case Em_3_Skill:
            t.gotoXY(47, 3);
            cout << "���������ͷų����ֵĽ���.";
            t.gotoXY(47, 4);
            cout << "ȫ���ܵ� " << damage << " �˺�!";
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return 0;
}
