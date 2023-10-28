#ifndef ENEMY
#define ENEMY
#include "Role.h"
#include "SkillBase.h"
#include "Player.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

//��������
enum EnemyType { Em_1_ForestBunny = 1, Em_2_SproutMole, Em_3_Mixtape, Em_4_Doombox };

//�����ж�(�չ���ʲô���������ͷż���)
enum AttackType { Em_1_Normal = 1, Em_2_Rest, Em_3_Skill, };

//�������ʴ���
struct Probability
{
    int probability_1;
    int probability_2;
    Skill_Enemy SkillType;
};

class Enemy :public Role
{
public:

    Enemy();
    Enemy(int hp, int MP, int atk, int def, int spd, int luck, int hit, EnemyType type);
    virtual ~Enemy();

    int Attack(int probability_1, int probability_2, Skill_Enemy SkillType, vector<Player*>list_Player, int RandPlayer);
    void EmoStatus(const string& object, vector<Player*>list_Player, int RandPlayer);
    int useSkill(vector<Player*>list_Player, int RandPlayer);
    int Set_Describe(const string& object, int damage);

    //����
    EnemyType Type;

    // ��ǰ����
    AttackType CurrentAttack;
    Skill_Enemy CurrentSkill;

    // ��������
    int AttackObject;

    Probability EmoAttackPro[4];

    //����ʹ�ô���
    int Skill_useTimes;

    int Fight_Num; //ս���б��
};

//������������
const std::map<EnemyType, string> Map_Enemy = {
    {EnemyType::Em_1_ForestBunny,   "ɭ������"},
    {EnemyType::Em_2_SproutMole,    "��������"},
    {EnemyType::Em_3_Mixtape,       "������"},
    {EnemyType::Em_4_Doombox,       "��������"},
};
extern const map<EnemyType, string> Map_Enemy;

#endif // !ENEMY


