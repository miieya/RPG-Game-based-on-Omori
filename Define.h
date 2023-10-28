//枚举汇总文件
#ifndef DEFINE
#define DEFINE
#include <map>
#include <string>
using namespace std;

typedef enum Cue_Info
{
    vill_01 = 1, 		//村庄
    Risk_02, 			//冒险

    Shop_03,            //商店
    Shop_Snacks_04,		//
    Shop_Tools_05,		//

    Risk_05,			//
    Fight_06,			//攻击
    NormalAttack_06,
    Skill_06,
    Snack_06,
    Tool_06,
    //UserInfo_03, 		//用户信息
    Read_Write_07,		//存档
}CueInfo;
extern CueInfo CueInfo_;

//情绪名称
enum Emo_Status
{
    Normal = 0,    //正常

    HAPPY,         //开心
    ECSTATIC,      //狂喜
    MANIC,         //癫狂

    ANGRY,         //生气
    ENRAGED,       //愤怒
    FURIOUS,       //狂怒

    SAD,           //悲伤
    DEPRESSED,     //抑郁
    MISERABLE      //痛苦
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

// 回合选择
//（普攻/技能/零食/玩具）
enum FightChoose { Nothing = 0, NormalAttack = 1, Skill, Snack, tOy, };


//Omori技能名
enum Skill_A
{
    Guard_A = 1,//1.防守(Guard)：
    SadPoem,//2.悲伤的诗(Sad Poem)：
    Stab,//3.戳刺(Stab)：
    HackAway,//4.乱砍(Hack Away)：
    Trick,//5.恶作剧(Trick)：
    Stare,//6.瞪视(Stare)：
    FinalStrike//7.最终攻击(Final Strike)：
};

//Aubrey技能名
enum Skill_B
{
    Guard_B = 1,//1.防守(Guard)：
    PepTal,//2.鼓舞(Pep Talk)：
    Twirl,//3.转圈(Twirl)：
    PowerHit,//4.强力一击(Power Hit)：
    Beatdown,//5.暴打(Beatdown)：
    WindupThrow,//6.挥臂一投(Wind-up Throw)：
    LastResort//7.最后一招(Last Resort)：
};

//Kel技能名
enum Skill_C
{
    Guard_C = 1,//1.防守(Guard)：
    Annoy,//2.骚扰(Annoy)：
    Rebound,//3.回弹(Rebound)：
    RunGun,//4.炮轰战术()：
    Megaphone,//5.喇叭筒(Megaphone)：
    CantCatchMe,//6.捉不着我(Can't Catch Me)：
    Tickle//7.挠痒(Tickle)：
};

//Hero技能名
enum Skill_D
{
    Guard_D = 1,//1.防守(Guard)：
    Cook,//2.烹饪(Cook)：
    Massage,//3.按摩(Massage)：
    Smile,//4.笑容(Smile)：
    TeaTime,//5.喝茶时间(Tea Time)：
    HomemadeJam,//6.自制果酱(Homemade Jam)：
    Dazzle//7.炫目(Dazzle)：
};

const std::map<Skill_A, std::string> Map_Skill_A = {
    {Guard_A,          "防守: 使该回合受到伤害减少。(cost:0)"},
    {SadPoem,          "悲伤的诗: 给一名队友或敌人施加悲伤。(cost:5)"},
    {Stab,             "戳刺: 必定暴击,对一名敌人造成伤害,如果Omori处于悲伤状态，则造成更高伤害。(cost:13)"},
    {HackAway,         "乱砍: 攻击三次, 随机命中敌人, 如果Omori处于愤怒状态,则造成更高伤害。(cost:30)"},
    {Trick,            "恶作剧:对敌方单体造成 3 x ATK - DEF 伤害，如果敌方处于任意开心状态，则速度降低75%（debuff)"},
    {Stare,            "瞪视:降低一名敌人所有属性。 赋予敌方单体debuff一级"},
    {FinalStrike,      "最终攻击:攻击所有敌人，当其情绪等级越高时，伤害越高"}
};
extern const map<Skill_A, string> Map_Skill_A;

const std::map<Skill_B, std::string> Map_Skill_B = {
    {Skill_B::Guard_B,          "防守: 使该回合受到伤害减少。(cost:0)"},
    {Skill_B::PepTal,           "鼓舞: 给一名队友或敌人施加开心。(cost:5)"},
    {Skill_B::Twirl,            "转圈: 攻击一名敌人，然后变得开心。(cost:10)"},
    {Skill_B::PowerHit,         "强力一击: 攻击一名敌人,然后降低敌人防御。(cost:20)"},
    {Skill_B::Beatdown,         "暴打"},
    {Skill_B::WindupThrow,      "挥臂一投"},
    {Skill_B::LastResort,       "最后一招"}
};
extern const map<Skill_B, string> Map_Skill_B;

const std::map<Skill_C, std::string> Map_Skill_C = {
    {Skill_C::Guard_C,          "防守: 使该回合受到伤害减少。(cost:0)"},
    {Skill_C::Annoy,            "骚扰: 给一名队友或敌人施加愤怒。(cost:5)"},
    {Skill_C::Rebound,          "回弹: 对所有敌人造成伤害。(cost:15)"},
    {Skill_C::RunGun,           "炮轰战术: 让我方所有变得生气。(cost 15)"},
    {Skill_C::Megaphone,        "喇叭筒"},
    {Skill_C::CantCatchMe,      "捉不着我"},
    {Skill_C::Tickle,           "挠痒"}
};
extern const map<Skill_C, string> Map_Skill_C;

const std::map<Skill_D, std::string> Map_Skill_D = {
    {Skill_D::Guard_D,          "防守: 使该回合受到伤害减少。(cost:0)"},
    {Skill_D::Cook,             "烹饪: 恢复一名队友心心。(cost:10)"},
    {Skill_D::Massage,          "按摩: 移除一名朋友或敌人的情绪。(cost:5)"},
    {Skill_D::Smile,            "笑容: 降低一名敌人的攻击。(cost:25)"},
    {Skill_D::TeaTime,          "喝茶时间"},
    {Skill_D::HomemadeJam,      "自制果酱"},
    {Skill_D::Dazzle,           "炫目"}
};
extern const map<Skill_D, string> Map_Skill_D;

//敌人技能
typedef enum
{
    BeCute = 1,
    SadEyes,
    RunAround,
    Tangle,
    BlastMusic,
}Skill_Enemy;


#endif // !DEFINE
