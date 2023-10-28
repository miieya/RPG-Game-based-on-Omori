//����������
#ifndef PROPERTY
#define PROPERTY
#include "Define.h"

//��������ö��
enum Role_Property
{
    HP, MP, Atk, Def, Spd, Luck, Hit, Hurt, Emochange //�����仯
};

//��������
enum HandleType { Add, Sub };

//�жϵ���orȺ��
enum Part { single = 1, all, enemy_single, enemy_all };

class Property
{
public:

    Property() : HP(0), MP(0.0), Atk(0.0), Def(0.0), Spd(0.0), Luck(0.0), Hit(0.0), Part(single),
        InfightPropertype(Role_Property::HP), Handle(Add), scale(0.0), EmoChange(Normal), times(0) {}

    int HP;     //����ֵ
    double MP;     //����
    double Atk;    //����
    double Def;    //����
    double Spd;    //�ٶ�
    double Luck;   //����(������)
    double Hit;    //������

    //��������
    Part    Part;                           //��Χ
    Role_Property   InfightPropertype;      //���Լӳ�����

    //���Ա仯
    HandleType  Handle;                     //����(+ / -)
    float   scale;

    //�����仯
    Emo_Status  EmoChange;                  //����

    //�����仯
    int times;
};

#endif // !PROPERTY


