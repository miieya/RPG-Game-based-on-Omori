//ö�ٻ����ļ�
#ifndef DEFINE
#define DEFINE
#include <map>
#include <string>
using namespace std;

typedef enum Cue_Info
{
    vill_01 = 1, 		//��ׯ
    Risk_02, 			//ð��

    Shop_03,            //�̵�
    Shop_Snacks_04,		//
    Shop_Tools_05,		//

    Risk_05,			//
    Fight_06,			//����
    NormalAttack_06,
    Skill_06,
    Snack_06,
    Tool_06,
    //UserInfo_03, 		//�û���Ϣ
    Read_Write_07,		//�浵
}CueInfo;
extern CueInfo CueInfo_;

//��������
enum Emo_Status
{
    Normal = 0,    //����

    HAPPY,         //����
    ECSTATIC,      //��ϲ
    MANIC,         //��

    ANGRY,         //����
    ENRAGED,       //��ŭ
    FURIOUS,       //��ŭ

    SAD,           //����
    DEPRESSED,     //����
    MISERABLE      //ʹ��
};
const std::map<Emo_Status, std::string> map_EmoStatusNames = {
    {Emo_Status::Normal, "Normal"},

    {Emo_Status::HAPPY, "Happy"},
    {Emo_Status::ECSTATIC, "Ecstatic"},
    {Emo_Status::MANIC, "Manic"},

    {Emo_Status::ANGRY, "Angry"},
    {Emo_Status::ENRAGED, "Enraged"},
    {Emo_Status::FURIOUS, "Furious"},

    {Emo_Status::SAD, "Sad"},
    {Emo_Status::DEPRESSED, "Depressed"},
    {Emo_Status::MISERABLE, "Miserable"}
};
extern const map<Emo_Status, string> map_EmoStatusNames;

// �غ�ѡ��
//���չ�/����/��ʳ/��ߣ�
enum FightChoose { Nothing = 0, NormalAttack = 1, Skill, Snack, tOy, };


//Omori������
enum Skill_A
{
    Guard_A = 1,//1.����(Guard)��
    SadPoem,//2.���˵�ʫ(Sad Poem)��
    Stab,//3.����(Stab)��
    HackAway,//4.�ҿ�(Hack Away)��
    Trick,//5.������(Trick)��
    Stare,//6.����(Stare)��
    FinalStrike//7.���չ���(Final Strike)��
};

//Aubrey������
enum Skill_B
{
    Guard_B = 1,//1.����(Guard)��
    PepTal,//2.����(Pep Talk)��
    Twirl,//3.תȦ(Twirl)��
    PowerHit,//4.ǿ��һ��(Power Hit)��
    Beatdown,//5.����(Beatdown)��
    WindupThrow,//6.�ӱ�һͶ(Wind-up Throw)��
    LastResort//7.���һ��(Last Resort)��
};

//Kel������
enum Skill_C
{
    Guard_C = 1,//1.����(Guard)��
    Annoy,//2.ɧ��(Annoy)��
    Rebound,//3.�ص�(Rebound)��
    RunGun,//4.�ں�ս��()��
    Megaphone,//5.����Ͳ(Megaphone)��
    CantCatchMe,//6.׽������(Can't Catch Me)��
    Tickle//7.����(Tickle)��
};

//Hero������
enum Skill_D
{
    Guard_D = 1,//1.����(Guard)��
    Cook,//2.���(Cook)��
    Massage,//3.��Ħ(Massage)��
    Smile,//4.Ц��(Smile)��
    TeaTime,//5.�Ȳ�ʱ��(Tea Time)��
    HomemadeJam,//6.���ƹ���(Homemade Jam)��
    Dazzle//7.��Ŀ(Dazzle)��
};

const std::map<Skill_A, std::string> Map_Skill_A = {
    {Guard_A,          "����: ʹ�ûغ��ܵ��˺����١�(cost:0)"},
    {SadPoem,          "���˵�ʫ: ��һ�����ѻ����ʩ�ӱ��ˡ�(cost:5)"},
    {Stab,             "����: �ض�����,��һ����������˺�,���Omori���ڱ���״̬������ɸ����˺���(cost:13)"},
    {HackAway,         "�ҿ�: ��������, ������е���, ���Omori���ڷ�ŭ״̬,����ɸ����˺���(cost:30)"},
    {Trick,            "������:�Եз�������� 3 x ATK - DEF �˺�������з��������⿪��״̬�����ٶȽ���75%��debuff)"},
    {Stare,            "����:����һ�������������ԡ� ����з�����debuffһ��"},
    {FinalStrike,      "���չ���:�������е��ˣ����������ȼ�Խ��ʱ���˺�Խ��"}
};
extern const map<Skill_A, string> Map_Skill_A;

const std::map<Skill_B, std::string> Map_Skill_B = {
    {Skill_B::Guard_B,          "����: ʹ�ûغ��ܵ��˺����١�(cost:0)"},
    {Skill_B::PepTal,           "����: ��һ�����ѻ����ʩ�ӿ��ġ�(cost:5)"},
    {Skill_B::Twirl,            "תȦ: ����һ�����ˣ�Ȼ���ÿ��ġ�(cost:10)"},
    {Skill_B::PowerHit,         "ǿ��һ��: ����һ������,Ȼ�󽵵͵��˷�����(cost:20)"},
    {Skill_B::Beatdown,         "����"},
    {Skill_B::WindupThrow,      "�ӱ�һͶ"},
    {Skill_B::LastResort,       "���һ��"}
};
extern const map<Skill_B, string> Map_Skill_B;

const std::map<Skill_C, std::string> Map_Skill_C = {
    {Skill_C::Guard_C,          "����: ʹ�ûغ��ܵ��˺����١�(cost:0)"},
    {Skill_C::Annoy,            "ɧ��: ��һ�����ѻ����ʩ�ӷ�ŭ��(cost:5)"},
    {Skill_C::Rebound,          "�ص�: �����е�������˺���(cost:15)"},
    {Skill_C::RunGun,           "�ں�ս��: ���ҷ����б��������(cost 15)"},
    {Skill_C::Megaphone,        "����Ͳ"},
    {Skill_C::CantCatchMe,      "׽������"},
    {Skill_C::Tickle,           "����"}
};
extern const map<Skill_C, string> Map_Skill_C;

const std::map<Skill_D, std::string> Map_Skill_D = {
    {Skill_D::Guard_D,          "����: ʹ�ûغ��ܵ��˺����١�(cost:0)"},
    {Skill_D::Cook,             "���: �ָ�һ���������ġ�(cost:10)"},
    {Skill_D::Massage,          "��Ħ: �Ƴ�һ�����ѻ���˵�������(cost:5)"},
    {Skill_D::Smile,            "Ц��: ����һ�����˵Ĺ�����(cost:25)"},
    {Skill_D::TeaTime,          "�Ȳ�ʱ��"},
    {Skill_D::HomemadeJam,      "���ƹ���"},
    {Skill_D::Dazzle,           "��Ŀ"}
};
extern const map<Skill_D, string> Map_Skill_D;

//���˼���
typedef enum
{
    BeCute = 1,
    SadEyes,
    RunAround,
    Tangle,
    BlastMusic,
}Skill_Enemy;


#endif // !DEFINE
