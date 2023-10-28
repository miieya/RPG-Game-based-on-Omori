#ifndef FIGHT
#define FIGHT
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Tool.h"
#include "ShopGoods.h"
#include "Pack.h"
#include <vector>
using namespace std;

class Fight
{
public:

    Fight();

    int PlayerInit(Player* player);
    int SkillInit(Player* player);
    int WeaponInit();
    int ItemInit();

    int WeaponAddition(Player* player, Weapon Weapontype);
    int SnackAddition(Player* player, snack goodstype);
    int ToyAddition(Player* player, Toy goodstype);
    int SkillAddition(Player* player, vector<Enemy*>list_Enemy, vector<Player*> list_Player);
    int SkillAddition(Enemy* player);
    int SkillChoose(Player* player, int SkillType, int instead);

    void Show_Info(int type, Player* player);
    void Show_EnemyInfo(int type);
    int useSkill_Print(Player* player);
    int useSnack_Print(Player* player);
    int useToy_Print(Player* player);
    void Infight_Choose_Print(Player* player);
    void Screen_Print();

    int fight();
    int Infight_01(Player* player);
    int Infight_02(int type, Player* player);
    void levelUp();

    int Level_01();

    int Random();
    int Enemy_Choose();
    int Player_Choose();
    int EnemyorPlayer_Choose();
    int ListHPCheck();

    //���Ƕ���
    Player* A;
    Player* B;
    Player* C;
    Player* D;

    //����
    weapon WeaponPack[12];

    //����
    ShopGoods* goods;

    //����
    Pack MyPack;

    //���˶���
    Enemy* Enemy_01;
    Enemy* Enemy_02;

    //�غ϶���
    vector<Enemy*> list_Enemy;
    vector<Player*> list_Player;

    //�����������
    int RandPlayer;
    int RandEnemy;
};

#endif // !FIGHT


