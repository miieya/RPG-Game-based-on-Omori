#ifndef ENEMY
#define ENEMY
#include "Role.h"
#include "SkillBase.h"
#include "Player.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

//敌人种类
enum EnemyType { Em_1_ForestBunny = 1, Em_2_SproutMole, Em_3_Mixtape, Em_4_Doombox };

//敌人行动(普攻、什么都不做、释放技能)
enum AttackType { Em_1_Normal = 1, Em_2_Rest, Em_3_Skill, };

//攻击概率处理
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

    //种类
    EnemyType Type;

    // 当前技能
    AttackType CurrentAttack;
    Skill_Enemy CurrentSkill;

    // 攻击对象
    int AttackObject;

    Probability EmoAttackPro[4];

    //技能使用次数
    int Skill_useTimes;

    int Fight_Num; //战斗中编号
};

//敌人名字描述
const std::map<EnemyType, string> Map_Enemy = {
    {EnemyType::Em_1_ForestBunny,   "森林兔兔"},
    {EnemyType::Em_2_SproutMole,    "树苗鼹鼠"},
    {EnemyType::Em_3_Mixtape,       "混音带"},
    {EnemyType::Em_4_Doombox,       "毁灭音箱"},
};
extern const map<EnemyType, string> Map_Enemy;

#endif // !ENEMY


