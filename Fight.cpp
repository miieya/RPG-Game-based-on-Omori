#include "Fight.h"
#include "Define.h"
#include "Weapon.h"
#include "Tool.h"
#include "Pack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//总体初始化
Fight::Fight()
{
    //角色初始化
    A = new Player(49, 31, 9, 8, 13, 5, 0);
    A->PlayRole = Player_A;
    A->emo = Normal;

    B = new Player(55, 18, 11, 6, 6, 3, 0);
    B->PlayRole = Player_B;
    B->emo = Normal;

    C = new Player(38, 37, 8, 6, 12, 7, 0);
    C->PlayRole = Player_C;
    C->emo = Normal;

    D = new Player(46, 31, 7, 9, 5, 5, 0);
    D->PlayRole = Player_D;
    D->emo = Normal;

    //背包初始化
    MyPack.GoldCoin = 0;

    //物品初始化
    goods = new ShopGoods;
    WeaponInit();
    ItemInit();

    //添加角色技能初始化+选择
    PlayerInit(A);
    PlayerInit(B);
    PlayerInit(C);
    PlayerInit(D);

}

//玩家属性初始化处理
int Fight::PlayerInit(Player* player)
{
    player->level = 1; //初始化等级

    SkillInit(player); //初始化技能


    //开场默认两个技能 将玩家拥有技能配到技能配备栏
    player->SkillTack.skillnum = 4;
    player->SkillTack.MySkill[0] = player->Skills[0];
    player->SkillTack.MySkill[1] = player->Skills[1];
    player->SkillTack.MySkill[2] = player->Skills[2];
    player->SkillTack.MySkill[3] = player->Skills[3];

    return 0;
}

//角色技能初始化
int Fight::SkillInit(Player* player)
{
    //初始化角色技能数组
    PlayerSkill InitSkill_A[7] = { PlayerSkill(Guard_A,0),PlayerSkill(SadPoem,5),PlayerSkill(Stab,13),PlayerSkill(HackAway,30),PlayerSkill(Trick,20),PlayerSkill(Stare,45),PlayerSkill(FinalStrike,50) };
    PlayerSkill InitSkill_B[7] = { {Guard_B,0},{PepTal,5},{Twirl,10},{PowerHit,20},{Beatdown,30},{WindupThrow,20},{LastResort,50} };
    PlayerSkill InitSkill_C[7] = { {Guard_C,0},{Annoy,5},{Rebound,15},{RunGun,15},{Megaphone,45},{CantCatchMe,50},{Tickle,55} };
    PlayerSkill InitSkill_D[7] = { {Guard_D,0},{Cook,5},{Massage,25},{Smile,25},{TeaTime,25},{HomemadeJam,40},{Dazzle,35} };

    switch (player->PlayRole)
    {
    case Player_A:
    {
        // 技能初始化
        for (int i = 0; i < 7; i++)
        {
            //将技能数组A付给角色A技能组
            memcpy(&player->Skills[i], &InitSkill_A[i], sizeof(PlayerSkill));

            switch (player->Skills[i].skill_type) {
            case Guard_A:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.scale = 0.5;
                player->Skills[i].SkillProperty.Handle = Sub;
                player->Skills[i].SkillProperty.InfightPropertype = Hurt;
                break;
            case SadPoem:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.EmoChange = SAD;
                player->Skills[i].SkillProperty.InfightPropertype = Emochange;
                break;
            case Stab://1.5 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 1.5 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case HackAway://2 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.times = 3;
                player->Skills[i].SkillProperty.Atk = 2 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case Trick://3 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case Stare:

                break;
            case FinalStrike:
                player->Skills[i].SkillProperty.Part = all;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            default:
                break;
            }
        }

        //根据角色等级增加技能
        switch (player->level) {
        case 1:
        {
            //武器属性添加
            WeaponAddition(player, ShinyKnife);
            //开场默认两个技能
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //开场默认两个技能
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //开场默认两个技能
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //开场默认两个技能
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //开场默认两个技能
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //开场默认两个技能
            player->Skills[6].Choose = true;
        }
        break;

        }
    }

    break;
    case Player_B:
    {
        // 技能初始化
        for (int i = 0; i < 7; i++)
        {
            memcpy(&player->Skills[i], &InitSkill_B[i], sizeof(PlayerSkill));

            switch (player->Skills[i].skill_type) {
            case Guard_B:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.scale = 0.5;
                player->Skills[i].SkillProperty.Handle = Sub;
                player->Skills[i].SkillProperty.InfightPropertype = Hurt;
                break;
            case PepTal:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.EmoChange = SAD;
                player->Skills[i].SkillProperty.InfightPropertype = Emochange;
                break;
            case Twirl://1.5 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 1.5 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case PowerHit://2 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.times = 3;
                player->Skills[i].SkillProperty.Atk = 2 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case Beatdown://3 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.times = 3;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case WindupThrow:
                player->Skills[i].SkillProperty.Part = all;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case LastResort:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 4 * player->Property_Def.HP;
                break;
            }

        }

        switch (player->level) {
        case 1:
        {
            //武器属性添加
            WeaponAddition(player, StuffedToy);
            //开场默认两个技能
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //开场默认两个技能
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //开场默认两个技能
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //开场默认两个技能
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //开场默认两个技能
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //开场默认两个技能
            player->Skills[6].Choose = true;
        }
        break;
        }
    }
    break;
    case Player_C:
    {
        // 技能初始化
        for (int i = 0; i < 7; i++)
        {
            memcpy(&player->Skills[i], &InitSkill_C[i], sizeof(PlayerSkill));

            switch (player->Skills[i].skill_type) {
            case Guard_C:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.scale = 0.5;
                player->Skills[i].SkillProperty.Handle = Sub;
                player->Skills[i].SkillProperty.InfightPropertype = Hurt;
                break;
            case Annoy:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.EmoChange = ANGRY;
                player->Skills[i].SkillProperty.InfightPropertype = Emochange;
                break;
            case Rebound://1.5 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 1.5 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case RunGun://2 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.times = 3;
                player->Skills[i].SkillProperty.Atk = 2 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case Megaphone://3 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case CantCatchMe:

                break;
            case Tickle:
                player->Skills[i].SkillProperty.Part = all;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            }
        }


        switch (player->level) {
        case 1:
        {
            //武器属性添加
            WeaponAddition(player, RubberBall);
            //开场默认两个技能
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //开场默认两个技能
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //开场默认两个技能
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //开场默认两个技能
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //开场默认两个技能
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //开场默认两个技能
            player->Skills[6].Choose = true;
        }
        break;

        }

    }
    break;
    case Player_D:
    {
        // 技能初始化
        for (int i = 0; i < 7; i++)
        {
            memcpy(&player->Skills[i], &InitSkill_D[i], sizeof(PlayerSkill));

            switch (player->Skills[i].skill_type) {
            case Guard_D:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.scale = 0.5;
                player->Skills[i].SkillProperty.Handle = Sub;
                player->Skills[i].SkillProperty.InfightPropertype = Hurt;
                break;
            case Cook:
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.EmoChange = SAD;
                player->Skills[i].SkillProperty.InfightPropertype = Emochange;
                break;
            case Massage://1.5 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 1.5 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case Smile://2 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.times = 3;
                player->Skills[i].SkillProperty.Atk = 2 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case TeaTime://3 x ATK - DEF
                player->Skills[i].SkillProperty.Part = single;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            case HomemadeJam:

                break;
            case Dazzle:
                player->Skills[i].SkillProperty.Part = all;
                player->Skills[i].SkillProperty.Atk = 3 * player->Property_Def.Atk;
                player->Skills[i].SkillProperty.Atk -= player->Property_Def.Def;
                break;
            }
        }

        switch (player->level) {
        case 1:
        {
            //武器属性添加
            WeaponAddition(player, GC);
            //开场默认两个技能
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //开场默认两个技能
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //开场默认两个技能
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //开场默认两个技能
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //开场默认两个技能
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //开场默认两个技能
            player->Skills[6].Choose = true;
        }
        break;

        }

    }
    break;
    }
    return 0;
}

//武器初始化
int Fight::WeaponInit()
{
    //武器全局变量初始化
    for (int i = 0; i < 12; i++)
    {
        WeaponPack[i].WeaponType = (Weapon)(i + 1); //给武器起名
        switch (WeaponPack[i].WeaponType)
        {
        case ShinyKnife:    //ATK+5 HIT+100%
        {
            WeaponPack[i].WeaponProperty.Atk += 5;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case RustyKnife:    //ATK+11， DEF+2 ， SPD+6，LUCK+4， HIT+100%

        {
            WeaponPack[i].WeaponProperty.Atk += 11;
            WeaponPack[i].WeaponProperty.Def += 2;
            WeaponPack[i].WeaponProperty.Spd += 6;
            WeaponPack[i].WeaponProperty.Luck += 4;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case RedKnife:      //ATK+13, DEF+6, SPD+6, LUCK+6, HIT+100%
        {
            WeaponPack[i].WeaponProperty.Atk += 13;
            WeaponPack[i].WeaponProperty.Def += 6;
            WeaponPack[i].WeaponProperty.Spd += 6;
            WeaponPack[i].WeaponProperty.Luck += 6;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case StuffedToy:    //ATK+4, HIT+100%
        {
            WeaponPack[i].WeaponProperty.Atk += 4;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case Pillow:        //HP+10，ATK+8，HIT+100%
        {
            WeaponPack[i].WeaponProperty.HP += 10;
            WeaponPack[i].WeaponProperty.Atk += 8;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case BaseballBat:   //HP+10, ATK+20， SPD+10, LUCK+10, HIT+100
        {
            WeaponPack[i].WeaponProperty.HP += 10;
            WeaponPack[i].WeaponProperty.Atk += 20;
            WeaponPack[i].WeaponProperty.Spd += 10;
            WeaponPack[i].WeaponProperty.Luck += 10;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case RubberBall:    //ATK+3,HIT+100%
        {
            WeaponPack[i].WeaponProperty.Atk += 3;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case Coconut:       //活力+50，ATK+8， HIT+100%
        {
            WeaponPack[i].WeaponProperty.MP += 50;
            WeaponPack[i].WeaponProperty.Atk += 8;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case Basketball:    //活力+50，ATK+15,SPD+100, LUCK+15,HIT+100
        {
            WeaponPack[i].WeaponProperty.Atk += 15;
            WeaponPack[i].WeaponProperty.Spd += 100;
            WeaponPack[i].WeaponProperty.Luck += 15;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case GC:            //ATK+4,HIT+100%
        {
            WeaponPack[i].WeaponProperty.Atk += 4;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case JBQ:           //活力+30，ATK+7，HIT+100%
        {
            WeaponPack[i].WeaponProperty.MP += 30;
            WeaponPack[i].WeaponProperty.Atk += 7;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case Friend:        //HP+20，活力+20， ATK+20，HIT+100%
        {
            WeaponPack[i].WeaponProperty.HP += 20;
            WeaponPack[i].WeaponProperty.MP += 20;
            WeaponPack[i].WeaponProperty.Atk += 20;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        default:
            break;
        }
    }

    return 0;
}

int Fight::ItemInit()//补给初始化
{
    //初始化定义数组
    snack ShopSnack[10] = { snack(Tofu,2),{Candy,20},{Donut,30},{Popcorn,50},{PlumJuice,5},{BreadfruitJuice,20},{MangoSmoothie,50},{PeachSoda,30},{coffee,25},{LifeJam,100} };
    Toy  ShopTool[7] = { {Sparkler,20},{Confetti,50},{PoetryBook,20},{RainCloud,50},{Present,20},{AirHorn,50},{Dandelion,30} };

    //零食初始
    for (int i = 0; i < 10; i++)
    {

        memcpy(&goods->SackPack[i], &ShopSnack[i], sizeof(snack));
        switch (goods->SackPack[i].type)
        {
        case Tofu:    //ATK+5 HIT+100%
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.HP += 5;
        }
        break;
        case Candy:    //ATK+11， DEF+2 ， SPD+6，LUCK+4， HIT+100%

        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.HP += 30;
        }
        break;
        case Donut:      //ATK+13, DEF+6, SPD+6, LUCK+6, HIT+100%
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.Handle = Add;
            goods->SackPack[i].Property.InfightPropertype = HP;
            goods->SackPack[i].Property.scale = 0.6;
        }
        break;
        case Popcorn:    //ATK+4, HIT+100%
        {
            goods->SackPack[i].Property.Part = all;
            goods->SackPack[i].Property.HP += 35;
        }
        break;
        case PlumJuice:        //HP+10，ATK+8，HIT+100%
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.MP += 15;
        }
        break;
        case BreadfruitJuice:   //HP+10, ATK+20， SPD+10, LUCK+10, HIT+100
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.MP += 50;
        }
        break;
        case MangoSmoothie:    //ATK+3,HIT+100%
        {
            goods->SackPack[i].Property.Part = all;
            goods->SackPack[i].Property.MP += 40;
        }
        break;
        case PeachSoda:       //活力+50，ATK+8， HIT+100%
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.Handle = Add;
            goods->SackPack[i].Property.InfightPropertype = MP;
            goods->SackPack[i].Property.scale = 0.6;
        }
        break;
        case coffee:    //活力+50，ATK+15,SPD+100, LUCK+15,HIT+100
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.Spd += 10;
        }
        break;
        case LifeJam:            //ATK+4,HIT+100%
        {

        }
        break;
        default:
            break;
        }
    }

    //玩具初始
    for (int i = 0; i < 7; i++)
    {
        memcpy(&goods->ToyPack[i], &ShopTool[i], sizeof(Toy));
        switch (goods->ToyPack[i].type)
        {
        case Sparkler:    //ATK+5 HIT+100%
        {
            goods->ToyPack[i].Property.Part = single;
            goods->ToyPack[i].Property.EmoChange = HAPPY;
        }
        break;
        case Confetti:    //ATK+11， DEF+2 ， SPD+6，LUCK+4， HIT+100%
        {
            goods->ToyPack[i].Property.Part = all;
            goods->ToyPack[i].Property.EmoChange = HAPPY;
        }
        break;
        case PoetryBook:      //ATK+13, DEF+6, SPD+6, LUCK+6, HIT+100%
        {
            goods->ToyPack[i].Property.Part = single;
            goods->ToyPack[i].Property.EmoChange = SAD;
        }
        break;
        case RainCloud:    //ATK+4, HIT+100%
        {
            goods->ToyPack[i].Property.Part = all;
            goods->ToyPack[i].Property.EmoChange = SAD;
        }
        break;
        case Present:        //HP+10，ATK+8，HIT+100%
        {
            goods->ToyPack[i].Property.Part = single;
            goods->ToyPack[i].Property.EmoChange = ANGRY;
        }
        break;
        case AirHorn:   //HP+10, ATK+20， SPD+10, LUCK+10, HIT+100
        {
            goods->ToyPack[i].Property.Part = all;
            goods->ToyPack[i].Property.EmoChange = ANGRY;
        }
        break;
        case Dandelion:    //ATK+3,HIT+100%
        {
            goods->ToyPack[i].Property.Part = all;
            goods->ToyPack[i].Property.EmoChange = Normal;
        }
        break;
        default:
            break;
        }
    }
    return 0;
}

//角色添加武器 通过传入武器枚举名字配备
int Fight::WeaponAddition(Player* player, Weapon WeaponType)
{
    //武器属性添加
    player->WeaponType = WeaponType;
    //给人物属性增加武器属性加成
    player->Property_AddHandle(WeaponPack[(int)(player->WeaponType - 1)].WeaponProperty);

    return 0;
}

//零食加成
int Fight::SnackAddition(Player* player, snack goodstype)
{
    switch (goodstype.type)
    {
        //单体单项
    case Tofu:
    case Candy:
    case PlumJuice:
    case BreadfruitJuice:
        //全体单项
    case Popcorn:
    case MangoSmoothie:
        if (goodstype.Property.Part == single)
            player->Property_AddHandle(goodstype.Property);
        else if (goodstype.Property.Part == all)
        {
            A->Property_AddHandle(goodstype.Property);
            B->Property_AddHandle(goodstype.Property);
            C->Property_AddHandle(goodstype.Property);
            D->Property_AddHandle(goodstype.Property);
        }
        break;
        //百分比项
    case Donut:
    case PeachSoda:
        player->Property_FightPropertyHandle(goodstype.Property);
        break;
        //buff项
    case coffee:
        player->Property_FightPropertyHandle(goodstype.Property);
        break;
    }
    return 0;
}

//玩具加成
int Fight::ToyAddition(Player* player, Toy goodstype)
{
    if (goodstype.Property.Part == single)
        player->Property_FightPropertyHandle(goodstype.Property);
    else if (goodstype.Property.Part == all)
    {
        A->Property_FightPropertyHandle(goodstype.Property);
        B->Property_FightPropertyHandle(goodstype.Property);
        C->Property_FightPropertyHandle(goodstype.Property);
        D->Property_FightPropertyHandle(goodstype.Property);
    }
    return 0;
}

// SkillType ： 替换的技能类型  尚未实现
// instead : 替换掉第几个技能  
int Fight::SkillChoose(Player* player, int SkillType, int instead)
{
    int instead_ = instead - 1; //替换成数组角标

    //该架构为cost准备
    switch (player->PlayRole)
    {
    case Player_A:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //后期补充
        //                    qDebug()<<QString("*%1").arg(i)<< Map_Skill_A[(Skill_A)player->Skill[i].skill] ;
    }
    break;
    case Player_B:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //后期补充
    }
    break;
    case Player_C:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //后期补充
    }
    break;
    case Player_D:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //后期补充
    }
    break;
    }

    return 0;
}

//技能释放
int Fight::SkillAddition(Player* player, vector<Enemy*>list_Enemy, vector<Player*> list_Player)
{
    Random();
    Tool t;
    Property p;
    int damage1 = 0;
    int heal = 0;
    int chosenEnemy = 0;
    int chosenPlayer = 0;
    int choose = 0;
    //int cnt[3] = { 0 };
    vector<int> to_delete;

    switch (player->PlayRole)
    {
    case Player_A:
    {
        switch (player->CurrentSkill.skill_type)
        {
        case Guard_A:
            t.gotoXY(47, 3);
            cout << "Omori选择了防守.";
            break;

        case SadPoem:
            choose = EnemyorPlayer_Choose();
            t.clear(1, 2, 17, 4);
            if (choose == 1)
            {
                // t.clear(1, 2,);

                chosenEnemy = Enemy_Choose();
                t.gotoXY(47, 3);
                list_Enemy[chosenEnemy]->emo = SAD;
                cout << "Omori读了一首悲伤的诗,";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "变得悲伤了.";
            }

            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                t.gotoXY(47, 3);
                list_Player[chosenPlayer]->emo = SAD;
                cout << "Omori读了一首悲伤的诗,";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "变得悲伤了.";
            }
            break;

        case Stab: //必定暴击，对敌方单体造成1.5 x ATK - DEF 伤害，如果自己处于任意悲伤状态，则造成造成2 x ATK - DEF 伤害
            chosenEnemy = Enemy_Choose();
            if (player->emo == SAD)
                damage1 = player->calc_Damage(list_Enemy[chosenEnemy], 2.5, 2);
            else
                damage1 = player->calc_Damage(list_Enemy[chosenEnemy], 2, 2);
            if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
            {
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage1;
                t.gotoXY(47, 3);
                cout << "Omori捅了一刀" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << ".";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "受到 " << damage1 << " 伤害!";
            }
            else
            {
                damage1 = list_Enemy.at(chosenEnemy)->Property_Inbattle.HP;
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP = 0;
                if (list_Enemy.at(chosenEnemy) == Enemy_01)
                {
                    t.clear(38 + 5, 13, 8, 1);
                    t.gotoXY(38, 13);
                    cout << "心心: 0";
                }
                else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                {
                    t.clear(62 + 5, 13, 8, 1);
                    t.gotoXY(62, 13);
                    cout << "心心: 0";
                }
                t.gotoXY(47, 3);
                cout << "Omori捅了一刀" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << ".";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "受到 " << damage1 << " 伤害!";
                list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
            }
            break;

        case HackAway: //攻击三次，随机命中敌人, 每次伤害 2 x ATK - DEF， 如果自己处于任意愤怒状态， 每次伤害 2.25 x ATK - DEF
            t.gotoXY(47, 3);
            cout << Map_Player.at(player->PlayRole) << "疯狂地乱砍." << endl;
            for (int i = 0; i < 3; i++)
            {
                Random();
                if (player->emo == ANGRY)
                    damage1 = player->calc_Damage(list_Enemy[RandEnemy], 2, 1);
                else
                    damage1 = player->calc_Damage(list_Enemy[RandEnemy], 2.25, 1);

                if (list_Enemy.at(RandEnemy)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(RandEnemy)->Property_Inbattle.HP)
                {
                    list_Enemy[RandEnemy]->Property_Inbattle.HP -= damage1;
                    t.gotoXY(47, 4 + i);
                    cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "0" << list_Enemy[RandEnemy]->Fight_Num << "受到 " << damage1 << " 伤害!" << endl;
                }
                else
                {
                    damage1 = list_Enemy.at(RandEnemy)->Property_Inbattle.HP;
                    list_Enemy.at(RandEnemy)->Property_Inbattle.HP = 0;
                    if (list_Enemy.at(RandEnemy) == Enemy_01)
                    {
                        t.clear(38 + 5, 13, 8, 1);
                        t.gotoXY(38, 13);
                        cout << "心心: 0";
                    }
                    else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                    {
                        t.clear(62 + 5, 13, 8, 1);
                        t.gotoXY(62, 13);
                        cout << "心心: 0";
                    }
                    t.gotoXY(47, 4 + i);
                    cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "0" << list_Enemy[RandEnemy]->Fight_Num << "受到 " << damage1 << " 伤害!" << endl;
                    list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
                }
            }
            break;

        case Trick: //对敌方单体造成 3 x ATK - DEF 伤害，如果敌方处于任意开心状态，则速度降低75%（debuff) 

            damage1 = player->calc_Damage(list_Enemy[RandEnemy], 3, 1);
            list_Enemy[RandEnemy]->Property_Inbattle.HP -= damage1;

            t.gotoXY(47, 3);
            cout << "Omori对" << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "做恶作剧.";
            list_Enemy.at(RandEnemy)->Property_Inbattle.Spd -= list_Enemy.at(RandEnemy)->Property_Def.Spd * 0.1;
            t.gotoXY(47, 4);
            cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "受到 " << damage1 << " 伤害!" << endl;
            t.gotoXY(47, 5);
            cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "的速度下降了!" << endl;
            break;

        case FinalStrike:
            if (player->CurrentSkill.SkillProperty.times > 1)
            {
                for (int i = 0; i < player->CurrentSkill.SkillProperty.times; i++)
                    list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            }
            else
                list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            std::cout << "A释放了他的终极攻击！" << std::endl;
            break;

        case Stare:
            break;
        }
    }
    break;
    case Player_B:
    {
        switch (player->CurrentSkill.skill_type)
        {
        case Guard_B:
            t.gotoXY(47, 3);
            cout << Map_Player.at(player->PlayRole) << "选择了防守.";
            break;

        case PepTal: //让一名队友或敌人变得开心
            choose = EnemyorPlayer_Choose();
            t.clear(1, 2, 17, 4);
            if (choose == 1)
            {
                chosenEnemy = Enemy_Choose();
                t.gotoXY(47, 3);
                list_Enemy[chosenEnemy]->emo = HAPPY;
                cout << "Aubrey给" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "鼓气,";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "变得开心了!";
            }

            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                t.gotoXY(47, 3);
                list_Player[chosenPlayer]->emo = HAPPY;
                cout << "Aubrey给" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "鼓气,";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "变得开心了!";
            }
            break;

        case Twirl: //攻击一名敌人，然后变得开心
            damage1 = player->calc_Damage(list_Enemy.at(chosenEnemy), 2.5, 1);
            if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
            {
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage1;
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "攻击了" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "受到 " << damage1 << " 伤害!";
                t.gotoXY(47, 5);
            }
            else
            {
                damage1 = list_Enemy.at(chosenEnemy)->Property_Inbattle.HP;
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP = 0;
                if (list_Enemy.at(chosenEnemy) == Enemy_01)
                {
                    t.clear(38 + 5, 13, 8, 1);
                    t.gotoXY(38, 13);
                    cout << "心心: 0";
                }
                else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                {
                    t.clear(62 + 5, 13, 8, 1);
                    t.gotoXY(62, 13);
                    cout << "心心: 0";
                }
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "攻击了" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "受到 " << damage1 << " 伤害!";
                list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
            }

            t.gotoXY(47, 5);
            player->emo = HAPPY;
            cout << Map_Player.at(player->PlayRole) << "变得开心了!";
            break;

        case PowerHit: //降低敌人防御。 伤害：2.5 x ATK
            damage1 = player->calc_Damage(list_Enemy.at(RandEnemy), 2.5, 1);
            if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
            {
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage1;
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "挥出了她的武器!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "受到  " << damage1 << " 伤害!";
                t.gotoXY(47, 5);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "的防御下降了!";
            }
            else
            {
                damage1 = list_Enemy.at(chosenEnemy)->Property_Inbattle.HP;
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP = 0;
                if (list_Enemy.at(chosenEnemy) == Enemy_01)
                {
                    t.clear(38 + 5, 13, 8, 1);
                    t.gotoXY(38, 13);
                    cout << "心心: 0";
                }
                else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                {
                    t.clear(62 + 5, 13, 8, 1);
                    t.gotoXY(62, 13);
                    cout << "心心: 0";
                }
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "挥出了她的武器!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "受到  " << damage1 << " 伤害!";
                list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
            }
            break;

        case Beatdown:
        case LastResort:
            if (player->CurrentSkill.SkillProperty.times > 1)
            {
                for (int i = 0; i < player->CurrentSkill.SkillProperty.times; i++)
                    list_Enemy[RandEnemy]->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            }
            else
                list_Enemy[RandEnemy]->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            break;
        case WindupThrow:
            for (int i = 0; i < list_Enemy.size(); i++)
            {
                list_Enemy.at(i)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            }
            break;
        }
    }
    break;
    case Player_C:
    {
        switch (player->CurrentSkill.skill_type)
        {
        case Guard_C:
            t.gotoXY(47, 3);
            cout << Map_Player.at(player->PlayRole) << "选择了防守." << endl;
            break;

        case Annoy:
            choose = EnemyorPlayer_Choose();
            t.clear(1, 2, 17, 4);
            if (choose == 1)
            {
                chosenEnemy = Enemy_Choose();
                t.gotoXY(47, 3);
                list_Enemy[chosenEnemy]->emo = ANGRY;
                cout << "Kel让" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "很恼火,";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "变得生气了!";
            }

            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                t.gotoXY(47, 3);
                list_Player[chosenPlayer]->emo = ANGRY;
                cout << "Kel让" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "很恼火,";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "变得生气了!";
            }
            break;

        case Rebound: //对所有敌人造成伤害。2.5 x ATK - DEF
            t.gotoXY(47, 3);
            cout << "Kel的球弹来弹去!" << endl;
            for (int i = 0; i < list_Enemy.size(); i++)
            {
                damage1 = player->calc_Damage(list_Enemy.at(i), 2.5, 1);

                if (list_Enemy.at(i)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(i)->Property_Inbattle.HP)
                {
                    list_Enemy.at(i)->Property_Inbattle.HP -= damage1;
                    t.gotoXY(47, 4 + i);
                    cout << Map_Enemy.at(list_Enemy.at(i)->Type) << "0" << list_Enemy[i]->Fight_Num << "受到了 " << damage1 << " 伤害!" << endl;
                }
                else
                {
                    damage1 = list_Enemy.at(i)->Property_Inbattle.HP;
                    list_Enemy.at(i)->Property_Inbattle.HP = 0;
                    if (list_Enemy.at(i) == Enemy_01)
                    {
                        t.clear(38 + 5, 13, 8, 1);
                        t.gotoXY(38, 13);
                        cout << "心心: 0";
                    }
                    else if (list_Enemy.at(i) == Enemy_02)
                    {
                        t.clear(62 + 5, 13, 8, 1);
                        t.gotoXY(62, 13);
                        cout << "心心: 0";
                    }
                    t.gotoXY(47, 4 + i);
                    cout << Map_Enemy.at(list_Enemy.at(i)->Type) << "0" << list_Enemy[i]->Fight_Num << "受到了 " << damage1 << " 伤害!" << endl;
                    to_delete.push_back(i);
                    //cnt[i] = 1; //标记应该删除的敌人
                }
            }

            //删除敌人
            /*for (int j = 0; j < 3; j++)
            {
                if (cnt[j] == 1)
                    list_Enemy.erase(list_Enemy.begin() + j);
            }*/
            for (int i = to_delete.size() - 1; i >= 0; --i)
            {
                list_Enemy.erase(list_Enemy.begin() + to_delete[i]);
            }
            break;

        case RunGun: //使用速度值而非攻击力进行一次攻击 1.5 x SPD - DEF

        case Megaphone: //让所有队友变得生气
            t.gotoXY(47, 3);
            cout << "Kel四处骚扰,把大家弄得心烦气躁." << endl;
            for (int i = 0; i < list_Player.size(); i++)
            {
                list_Player.at(i)->emo = ANGRY;
                t.gotoXY(47, 4 + i);
                cout << Map_Player.at(list_Player.at(i)->PlayRole) << "变得生气了!" << endl;
            }

        case Tickle:
            if (player->CurrentSkill.SkillProperty.times > 1)
            {
                for (int i = 0; i < player->CurrentSkill.SkillProperty.times; i++)
                    list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            }
            else
                list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            break;
        case CantCatchMe:
            for (int i = 0; i < list_Enemy.size(); i++)
            {
                list_Enemy.at(i)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            }
            break;
        }
    }
    break;
    case Player_D:
    {
        switch (player->CurrentSkill.skill_type)
        {
        case Guard_D:
            t.gotoXY(47, 3);
            cout << Map_Player.at(player->PlayRole) << "选择了防守." << endl;
            break;

        case Cook: //给队友回血
            chosenPlayer = Player_Choose();
            p.InfightPropertype = HP;
            heal = list_Player[chosenPlayer]->Property_Def.HP - list_Player[chosenPlayer]->Property_Inbattle.HP;
            list_Player[chosenPlayer]->Property_Handle(p, Add, 0.75);

            //加血后溢出血槽的情况
            if (list_Player[chosenPlayer]->Property_Inbattle.HP > list_Player[chosenPlayer]->Property_Def.HP)
            {
                list_Player[chosenPlayer]->Property_Inbattle.HP = list_Player[chosenPlayer]->Property_Def.HP;
                t.gotoXY(47, 3);
                cout << "Hero给" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "手工制作了曲奇";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "恢复了" << heal << "心心.";
            }
            else
            {
                t.gotoXY(47, 3);
                cout << "Hero给" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "手工制作了曲奇";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "恢复了" << 0.75 * list_Player[chosenPlayer]->Property_Def.HP << "心心.";
            }
            break;

        case Massage: //移除一名队友或敌人的情绪
            choose = EnemyorPlayer_Choose();
            if (choose == 1)
            {
                chosenEnemy = Enemy_Choose();
                list_Enemy[chosenEnemy]->emo = Normal;
                t.gotoXY(47, 3);
                cout << "Hero给" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "按摩.";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "冷静下来了.";
            }
            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                list_Player[chosenPlayer]->emo = Normal;
                t.gotoXY(47, 3);
                cout << "Hero给" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "按摩.";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "冷静下来了.";
            }
            break;

        case Smile: //降低一名敌人的攻击
            chosenEnemy = Enemy_Choose();
            p.InfightPropertype = Atk;
            list_Enemy[chosenEnemy]->Property_Handle(p, Sub, 0.1);
            t.gotoXY(47, 3);
            cout << "Hero对着" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "微笑,";
            t.gotoXY(47, 4);
            cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "的攻击下降了!";
            break;

        case TeaTime:
        case Dazzle:
            if (player->CurrentSkill.SkillProperty.times > 1)
            {
                for (int i = 0; i < player->CurrentSkill.SkillProperty.times; i++)
                    list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            }
            else
                list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            break;
        case HomemadeJam:
            break;
        }
    }
    break;
    }
    return 0;
}

//技能释放(敌人)
int Fight::SkillAddition(Enemy* player)
{
    Random();

    switch (player->CurrentAttack)
    {
    case Em_1_Normal:
        list_Player.at(RandPlayer)->Property_Inbattle.HP -= 2 * player->Property_Inbattle.Atk - list_Player.at(RandPlayer)->Property_Inbattle.Def;
        break;
    case Em_3_Skill:
    {
        switch (player->CurrentSkill) {
        case BeCute:
            list_Player.at(RandPlayer)->Property_Inbattle.Atk -= 10;
            break;
        case SadEyes:
            list_Player.at(RandPlayer)->emo = SAD;
            break;
        case RunAround://1.5 x ATK - DEF
            list_Player.at(RandPlayer)->Property_Inbattle.HP -= 1.5 * player->Property_Inbattle.Atk - list_Player.at(RandPlayer)->Property_Inbattle.Def;
            list_Player.at(RandPlayer)->Property_Inbattle.HP -= 1.5 * player->Property_Inbattle.Atk - list_Player.at(RandPlayer)->Property_Inbattle.Def;
            break;
        case Tangle://2 x ATK - DEF
            list_Player.at(RandPlayer)->Property_Inbattle.Spd -= 10;
            break;
        case BlastMusic://3 x ATK - DEF
        {
            for (int i = 0; i < list_Player.size(); i++)
            {
                list_Player.at(i)->Property_Inbattle.HP -= 2 * player->Property_Inbattle.Atk - list_Player.at(RandPlayer)->Property_Inbattle.Def;
            }
        }
        break;
        }
    }
    break;
    }
    return 0;
}

//选择技能时的输出
int Fight::useSkill_Print(Player* player)
{
    Tool t;
    int choose = 0;
    switch (player->PlayRole)
    {
    case Player_A:
    {
        for (int i = 0; i < player->SkillTack.skillnum; i++)
        {
            if (i == 0) t.gotoXY(20, 26); else if (i == 1) t.gotoXY(60, 26); else if (i == 2) t.gotoXY(20, 27); else if (i == 3)t.gotoXY(20, 28);
            cout << i + 1 << "." << Map_Skill_A.at((Skill_A)player->SkillTack.MySkill[i].skill_type);
        }
        cin >> choose;
        return choose;
    }
    break;
    case Player_B:
    {
        for (int i = 0; i < player->SkillTack.skillnum; i++)
        {
            if (i == 0) t.gotoXY(20, 26); else if (i == 1) t.gotoXY(60, 26); else if (i == 2) t.gotoXY(20, 27); else if (i == 3)t.gotoXY(20, 28);
            cout << i + 1 << "." << Map_Skill_B.at((Skill_B)player->SkillTack.MySkill[i].skill_type);
        }
        cin >> choose;
        return choose;
    }
    break;
    case Player_C:
    {
        for (int i = 0; i < player->SkillTack.skillnum; i++)
        {
            if (i == 0) t.gotoXY(20, 26); else if (i == 1) t.gotoXY(60, 26); else if (i == 2) t.gotoXY(20, 27); else if (i == 3)t.gotoXY(20, 28);
            cout << i + 1 << "." << Map_Skill_C.at((Skill_C)player->SkillTack.MySkill[i].skill_type);
        }
        cin >> choose;
        return choose;
    }
    break;
    case Player_D:
    {
        for (int i = 0; i < player->SkillTack.skillnum; i++)
        {
            if (i == 0) t.gotoXY(20, 26); else if (i == 1) t.gotoXY(60, 26); else if (i == 2) t.gotoXY(20, 27); else if (i == 3)t.gotoXY(20, 28);
            cout << i + 1 << "." << Map_Skill_D.at((Skill_D)player->SkillTack.MySkill[i].skill_type);
        }
        cin >> choose;
        return choose;
    }
    break;
    }
}

//使用零食时显示
int Fight::useSnack_Print(Player* player)
{
    Tool t;
    int x = 1;
    int choose = 0;
    if (MyPack.snack_num == 0)
    {
        t.gotoXY(1, 2);
        cout << "暂无零食";
        t.wait(500);
        return -1;
    }
    else
    {
        t.gotoXY(1, 2);
        cout << "选择使用的零食:";
        int i = 0;
        for (i = 0; i < 10; i++)
        {
            if (MyPack.ShopSnack[i].type != 0)
            {
                t.gotoXY(1, 3 + i);
                cout << x << "." << Map_Snacks.at(static_cast<Snacks>(MyPack.ShopSnack[i].type));
                x++;
            }
        }

        t.gotoXY(1, 4 + i);
        cin >> choose;
        if (choose > 0 && choose < x)
            return choose;
        else
            useSnack_Print(player);
    }
    return 0;
}

//使用玩具时显示
int Fight::useToy_Print(Player* player)
{
    Tool t;
    int x = 1;
    int choose = 0;
    if (MyPack.toy_num == 0)
    {
        t.gotoXY(1, 2);
        cout << "暂无玩具";
        t.wait(500);
        return -1;
    }
    else
    {
        t.gotoXY(1, 2);
        cout << "选择使用的玩具:";
        int i = 0;
        for (i = 0; i < MyPack.toy_num; i++)
        {
            if (MyPack.ShopToy[i].type != 0)
            {
                t.gotoXY(1, 3 + i);
                cout << x << "." << Map_Toys.at(static_cast<Toys>(MyPack.ShopToy[i].type));
                x++;
            }
        }

        t.gotoXY(1, 4 + i);
        cin >> choose;
        if (choose > 0 && choose < x)
            return choose;
        else
            useToy_Print(player);
    }
    return 0;
}

//输出战斗中选项
void Fight::Infight_Choose_Print(Player* player)
{
    Tool t;
    t.gotoXY(43, 22);
    cout << "1.普通攻击";
    t.gotoXY(60, 22);
    cout << "2.使用技能";
    t.gotoXY(43, 23);
    cout << "3.使用零食";
    t.gotoXY(60, 23);
    cout << "4.使用玩具";
    t.gotoXY(43, 24);
    cout << Map_Player.at(player->PlayRole) << "的回合," "请做选择!";
}

//输出玩家信息
void Fight::Show_Info(int type, Player* player)
{
    if (type == 0)
    {
        Tool t;
        //左上角
        t.gotoXY(24, 3);
        t.clear(24, 3, 20, 1);
        t.gotoXY(24, 3);
        cout << "Aubrey (" << map_EmoStatusNames.at(B->emo) << ")";
        if (this->B->Property_Inbattle.HP <= 0)
            this->B->Property_Inbattle.HP = 0;
        t.gotoXY(24, 4);
        t.clear(29, 4, 10, 1);
        t.gotoXY(24, 4);
        cout << "心心: " << this->B->Property_Inbattle.HP;
        if (this->B->Property_Inbattle.MP <= 0)
            this->B->Property_Inbattle.MP = 0;
        t.gotoXY(24, 5);
        t.clear(29, 5, 10, 1);
        t.gotoXY(24, 5);
        cout << "活力: " << this->B->Property_Inbattle.MP;

        // 右上角
        t.gotoXY(82, 3);  
        t.clear(82, 3, 15, 1);
        t.gotoXY(82, 3);
        cout << "Hero (" << map_EmoStatusNames.at(D->emo) << ")";
        if (this->D->Property_Inbattle.HP <= 0)
            this->D->Property_Inbattle.HP = 0;
        t.gotoXY(82, 4);
        t.clear(87, 4, 5, 1);
        t.gotoXY(82, 4);
        cout << "心心: " << this->D->Property_Inbattle.HP;
        //t.gotoXY(82, 5);
        if (this->D->Property_Inbattle.MP <= 0)
            this->D->Property_Inbattle.MP = 0;
        t.gotoXY(82, 5);
        t.clear(87, 5, 10, 1);
        t.gotoXY(82, 5);
        cout << "活力: " << this->D->Property_Inbattle.MP;

        // 左下角
        t.gotoXY(24, 18);
        t.clear(24, 18, 20, 1);
        t.gotoXY(24, 18);
        cout << "Omori (" << map_EmoStatusNames.at(A->emo) << ")";
        if (this->A->Property_Inbattle.HP <= 0)
            this->A->Property_Inbattle.HP = 0;
        t.gotoXY(24, 19);
        t.clear(29, 19, 10, 1);
        t.gotoXY(24, 19);
        cout << "心心: " << this->A->Property_Inbattle.HP;
        if (this->A->Property_Inbattle.MP <= 0)
            this->A->Property_Inbattle.MP = 0;
        t.gotoXY(24, 20);
        t.clear(29, 20, 10, 1);
        t.gotoXY(24, 20);
        cout << "活力: " << this->A->Property_Inbattle.MP;

        // 右下角
        t.gotoXY(82, 18);
        t.clear(82, 18, 15, 1);
        t.gotoXY(82, 18);
        cout << "kel (" << map_EmoStatusNames.at(C->emo) << ")";
        if (this->C->Property_Inbattle.HP <= 0)
            this->C->Property_Inbattle.HP = 0;
        t.gotoXY(82, 19);
        t.clear(87, 19, 10, 1);
        t.gotoXY(82, 19);
        cout << "心心: " << this->C->Property_Inbattle.HP;
        if (this->C->Property_Inbattle.MP <= 0)
            this->C->Property_Inbattle.MP = 0;
        t.gotoXY(82, 20);
        t.clear(87, 20, 10, 1);
        t.gotoXY(82, 20);
        cout << "活力: " << this->C->Property_Inbattle.MP;
    }
}

//输出边框
void Fight::Screen_Print()
{
    Tool t;

    t.gotoXY(20, 1);
    cout << "┌";
    for (int i = 0; i < 80; ++i)
        cout << "─";
    cout << "┐";

    t.gotoXY(20, 25);
    cout << "└";
    for (int i = 0; i < 80; ++i)
        cout << "─";
    cout << "┘";

    for (int i = 2; i <= 24; ++i)
    {
        t.gotoXY(20, i);
        cout << "│";
        t.gotoXY(101, i);
        cout << "│";
    }
}

void Fight::Show_EnemyInfo(int type)
{
    Tool t;

    if (!list_Enemy.empty())
    {
        int x = 0;
        for (const auto& enemy : list_Enemy)
        {
            if (enemy->Fight_Num == 1) //按照敌人序号输出左右顺序
                x = 38;
            else if (enemy->Fight_Num == 2)
                x = 62;

            t.clear(x, 12, 20, 1);
            t.gotoXY(x, 12);
            cout << Map_Enemy.at(enemy->Type) << "0" << enemy->Fight_Num << "(" << map_EmoStatusNames.at(enemy->emo) << ")";
            t.gotoXY(x, 13);
            if (enemy->Property_Inbattle.HP <= 0)
                enemy->Property_Inbattle.HP = 0;
            t.clear(x + 5, 13, 10, 1);
            t.gotoXY(x, 13);
            cout << "心心: " << enemy->Property_Inbattle.HP;
        }
    }
    else
    {
        t.clear(47, 3, 30, 5); //覆盖上面伤害信息
        t.clear(38, 12, 50, 5); //覆盖敌人信息
        t.gotoXY(50, 12);
        cout << "已全部清缴";
    }
}

// 选择技能
int Fight::Infight_01(Player* player)
{
    Tool t;
    int Input;

    // 使用技能
    player->InfightChoose = Skill;

    while (true)
    {
        Input = useSkill_Print(player); // 进入角色选择后的显示
        if (Input == 0);
        if (player->Property_Inbattle.MP > player->SkillTack.MySkill[Input - 1].cost)
        {
            // 技能选择锁定
            player->CurrentSkill = player->SkillTack.MySkill[Input - 1];
            player->Property_Inbattle.MP -= player->SkillTack.MySkill[Input - 1].cost;
            break;
        }
        else
        {
            for (int i = 26; i <= 28; i++)
                t.clearLine(1, i);
            t.gotoXY(25, 26);
            cout << "活力不足，无法释放该技能！";
            t.wait(1000);
            t.clearLine(25, 26);
            Infight_01(player);
        }
    }

    return 0;
}

//选择零食玩具
// 参数： type ： 0 零食，1 玩具 || player ： 接受者
int Fight::Infight_02(int type, Player* player)
{
    Tool t;
    int Input;
    if (type == 0) //零食
    {
        //进入角色选择后的显示
        int Input = useSnack_Print(player);

        if (Input == -1) //暂无零食情况
        {
            t.clear(1, 2, 15, 20);
            return -1;
        }

        if (Input <= MyPack.toy_num)
        {
            t.gotoXY(47, 3);
            cout << Map_Player.at(player->PlayRole) << "吃了:" << Map_Snacks.at(static_cast<Snacks>(MyPack.ShopSnack[Input - 1].type)) << "!";
            // 零食加成
            SnackAddition(player, MyPack.ShopSnack[Input - 1]);
            memset(&MyPack.ShopSnack[Input - 1], 0, sizeof(snack));
            MyPack.snack_num--;
        }
    }
    else if (type == 1)  //玩具
    {
        //进入角色选择后的显示
        int Input = useToy_Print(player);

        if (Input == -1) //暂无玩具情况
        {
            t.clear(1, 2, 15, 20);
            return -1;
        }

        if (Input <= MyPack.toy_num)
        {
            t.gotoXY(48, 3);
            cout << Map_Player.at(player->PlayRole) << "使用了:" << Map_Toys.at(static_cast<Toys>(MyPack.ShopToy[Input - 1].type)) << "!";

            // 零食加成
            ToyAddition(player, MyPack.ShopToy[Input - 1]);
            memset(&MyPack.ShopToy[Input - 1], 0, sizeof(Toy));
            MyPack.toy_num--;
        }
    }
    t.clear(1, 2, 15, 20);
    return 0;
}

//产生随机攻击对象
int Fight::Random()
{
    Tool t;

    if (list_Player.size() != 0)
    {
        RandPlayer = t.generateRandomNumber(list_Player.size());
    }
    else
        RandPlayer = 0;
    if (list_Enemy.size() != 0)
    {
        RandEnemy = t.generateRandomNumber(list_Enemy.size());
    }
    else
        RandEnemy = 0;

    return 0;
}

//选择特定敌人
int Fight::Enemy_Choose()
{
    Tool t;

    t.gotoXY(1, 2);
    cout << "请选择想攻击的敌人";
    int chosenEnemy;
    int k;
    for (k = 1; k <= list_Enemy.size(); ++k)
    {
        t.gotoXY(1, 2 + k);
        cout << k << ": " << Map_Enemy.at(list_Enemy[k - 1]->Type) << "0" << list_Enemy.at(k - 1)->Fight_Num;
    }

    t.gotoXY(1, k + 2);
    cin >> chosenEnemy;
    cin.ignore();
    if (chosenEnemy > 0 && chosenEnemy < list_Enemy.size() + 1)
        return chosenEnemy - 1;
    else
    {
        t.clear(1, 2, 18, 25); //覆盖询问攻击敌人信息
        t.gotoXY(1, 2);
        cout << "输入有误,重新输入.";
        t.wait(500);
        Enemy_Choose();
    }
}

//选择特定队友
int Fight::Player_Choose()
{
    Tool t;

    t.gotoXY(1, 2);
    cout << "请选择队友";
    int chosenPlayer;
    int k;
    for (k = 1; k <= list_Player.size(); ++k)
    {
        t.gotoXY(1, 2 + k);
        cout << k << ": " << Map_Player.at(list_Player[k - 1]->PlayRole);
    }

    t.gotoXY(1, k + 2);
    cin >> chosenPlayer;
    cin.ignore();
    if (chosenPlayer > 0 && chosenPlayer < list_Player.size() + 1)
        return chosenPlayer - 1;
    else
    {
        t.clear(1, 2, 19, 25); //覆盖询问信息
        t.gotoXY(1, 2);
        cout << "输入有误,重新输入.";
        t.wait(500);
        Player_Choose();
    }
}

//选择敌人或队友
int Fight::EnemyorPlayer_Choose()
{
    Tool t;
    int choose = 1;

    t.gotoXY(1, 2);
    cout << "选择敌人还是队友?";
    t.gotoXY(1, 3);
    cout << "1. 敌人";
    t.gotoXY(1, 4);
    cout << "2. 队友";

    t.gotoXY(1, 5);
    cin >> choose;

    if (choose == 1 || choose == 2)
        return choose;
    else
    {
        t.clear(1, 2, 18, 25); //覆盖询问信息
        t.gotoXY(1, 2);
        cout << "输入有误,重新输入.";
        t.wait(500);
        EnemyorPlayer_Choose();
    }
}

//战斗模块-判断胜利条件
int Fight::ListHPCheck()
{
    int ret = 0;
    if (list_Enemy.size() != 0)
    {
        for (int i = list_Enemy.size() - 1; i >= 0; i--)
        {
            if (list_Enemy.at(i)->Property_Inbattle.HP <= 0)
            {
                list_Enemy.at(i)->Property_Inbattle.HP = 0;
                list_Enemy.erase(list_Enemy.begin() + i);
                if (list_Enemy.size() == 0)
                    return 2;
            }
        }
    }
    else
        return 2; //游戏成功

    if (list_Player.size() != 0)
    {
        for (int i = list_Player.size() - 1; i >= 0; i--)
        {
            if (list_Player.at(i)->Property_Inbattle.HP <= 0)
            {
                list_Player.at(i)->Property_Inbattle.HP = 0;
                list_Player.erase(list_Player.begin() + i);
            }
        }
    }
    else
        return 0; //游戏失败

    return 1; //游戏继续
}

//主战斗函数
int Fight::fight()
{

    Screen_Print();

    Tool t;
    int Input;
    int x = 0;
    Player* player = nullptr;
    Enemy* enemy = nullptr;

    //初始化列表
    list_Enemy.push_back(Enemy_01);
    list_Enemy.push_back(Enemy_02);
    list_Player.push_back(A);
    list_Player.push_back(B);
    list_Player.push_back(C);
    list_Player.push_back(D);

    vector<int> listRand;

    Show_Info(0, A);
    Show_Info(0, B);
    Show_Info(0, C);
    Show_Info(0, C);

    //判断血槽
    while (ListHPCheck())
    {
     
        bool Fight_suc = false;

       //先判断速度，决定行动顺序
        listRand.clear();
        for (int i = 0; i < list_Player.size(); i++)
        {
            listRand.push_back(list_Player.at(i)->Property_Inbattle.Spd);
        }

        //根据速度由高到低进行排序
        for (int i = 0; i < listRand.size() - 1; ++i)
        {
            for (int j = 0; j < listRand.size() - 1; ++j)
            {
                if (listRand[j] < listRand[j + 1])
                {
                    swap(listRand[j], listRand[j + 1]);
                }
            }
        }

        // 敌人默认选择，玩家顺序选择
        // 显示敌人信息
        Show_EnemyInfo(0);
        x = 0;
        int ret = 0;

        //玩家操作轮循
        for (int j = 0; j < list_Player.size(); j++)
        {
            Random();//更新随机攻击对象

            //判断是谁
            for (int i = 0; i < listRand.size(); i++)
            {
                if (list_Player.at(i)->Property_Inbattle.Spd == listRand[x])
                {
                    player = nullptr;
                    player = list_Player.at(i);
                    x++;
                    break;
                }
            }

            // 关键参数初始化
            memset(&player->CurrentSkill, 0, sizeof(skill));
            player->InfightChoose = Nothing;

            //输出战中选项
            int RETURN = 0;
            do {
                RETURN = 0;
                Infight_Choose_Print(player);

                cin >> Input;
                cin.ignore(); //清除垃圾字符

                t.clear(47, 3, 30, 5); //清除上一回攻击信息
                t.clear(43, 24, 50, 1); //清除选项提问

                player->InfightChoose = static_cast<FightChoose>(Input);

                int damage = 0;
                int chosenEnemy = 0;

                switch (player->InfightChoose) {
                case NormalAttack: //普攻
                    chosenEnemy = Enemy_Choose();
                    damage = player->calc_Damage(list_Enemy.at(chosenEnemy), 2, 1);
                    if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
                    {
                        list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage;
                        t.gotoXY(47, 3);
                        cout << Map_Player.at(player->PlayRole) << "攻击了" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "!";
                        t.gotoXY(47, 4);
                        cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "受到 " << damage << " 伤害!";
                    }
                    else
                    {
                        damage = list_Enemy.at(chosenEnemy)->Property_Inbattle.HP;
                        list_Enemy.at(chosenEnemy)->Property_Inbattle.HP = 0;
                        if (list_Enemy.at(chosenEnemy) == Enemy_01)
                        {
                            t.clear(38 + 5, 13, 8, 1);
                            t.gotoXY(38, 13);
                            cout << "心心: 0";
                        }
                        else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                        {
                            t.clear(62 + 5, 13, 8, 1);
                            t.gotoXY(62, 13);
                            cout << "心心: 0";
                        }
                        t.gotoXY(47, 3);
                        cout << Map_Player.at(player->PlayRole) << "攻击了" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "!";
                        t.gotoXY(47, 4);
                        cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "受到 " << damage << " 伤害!";
                        list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
                    }
                    break;

                case Skill:
                    Infight_01(player);
                    SkillAddition(player, list_Enemy, list_Player);
                    for (int i = 26; i <= 28; i++)
                        t.clearLine(20, i);
                    break;
                case Snack:
                    RETURN = Infight_02(0, player);
                    break;
                case tOy:
                    RETURN = Infight_02(1, list_Player.at(RandPlayer));
                    break;
                default:
                    cout << "选择错误，请重新选择" << endl;
                    Input = -1;
                    break;
                }
            } while (RETURN == -1);

            //更新输出玩家信息
            Show_Info(0, A);
            Show_Info(0, B);
            Show_Info(0, C);
            Show_Info(0, C);

            t.clear(1, 2, 18, 25); //覆盖询问攻击敌人信息
            ret = ListHPCheck();
            Show_EnemyInfo(0); //更新显示敌人血量 
            if (ret == 2)
            {
                Fight_suc = true;
                return 0;           //成功
            }
        }

        //敌人操作轮询
        for (int j = 0; j < list_Enemy.size(); j++)
        {
            t.wait(1500);
            Random();
            t.clear(47, 3, 35, 3); //清除上一回攻击信息
            list_Enemy.at(j)->EmoStatus(Map_Player.at(list_Player.at(RandPlayer)->PlayRole), list_Player, RandPlayer);

            ret = ListHPCheck();
            if (ret == 0)
            {
                Fight_suc = true;
                return -1;           //成功
            }

            if (list_Player.size() != 0) //血量不为零，进入函数
                Show_Info(0, list_Player.at(RandPlayer));
            else //容器清空后输出
            {
                t.clear(29, 4, 10, 1);
                t.gotoXY(24, 4);
                cout << "心心: " << this->B->Property_Inbattle.HP;
                t.clear(87, 4, 10, 1);
                t.gotoXY(82, 4);
                cout << "心心: " << this->D->Property_Inbattle.HP;
                t.clear(29, 19, 10, 1);
                t.gotoXY(24, 19);
                cout << "心心: " << this->A->Property_Inbattle.HP;
                t.clear(87, 19, 5, 1);
                t.gotoXY(82, 19);
                cout << "心心: " << this->C->Property_Inbattle.HP;
            }
        }
    }
    return -1;           //成功
}

//升级模块
void Fight::levelUp()
{
    A->Property_Set(71, 46, 15, 13, 17, 8, 0);
    B->Property_Set(81, 27, 19, 13, 10, 5, 0);
    C->Property_Set(54, 53, 14, 10, 22, 7, 0);
    D->Property_Set(73, 46, 10, 16, 8, 5, 0);

    A->level++;
    B->level++;
    C->level++;
    D->level++;

    //技能更新
    SkillInit(A);
    SkillInit(B);
    SkillInit(C);
    SkillInit(D);
}

int Fight::Level_01()
{
    //levelUp();
    Tool t;
    int ret = 0;
    // 两只森林兔兔
    /*Enemy_01 = new Enemy(10, 42, 10, 2, 10, 10, 100, Em_1_ForestBunny);
    Enemy_02 = new Enemy(10, 42, 10, 2, 10, 10, 100, Em_1_ForestBunny);*/

    Enemy_01 = new Enemy(200, 42, 10, 2, 10, 10, 100, Em_2_SproutMole);
    Enemy_02 = new Enemy(200, 42, 10, 2, 10, 10, 100, Em_1_ForestBunny);

    Enemy_01->emo = Normal;
    Enemy_02->emo = Normal;
    Enemy_01->level = 1;
    Enemy_02->level = 2;
    Enemy_01->Fight_Num = 1;
    Enemy_02->Fight_Num = 2;


    //战斗
    ret = fight();
    if (ret)
    {
        t.clearLine(22, 27);
        cout << "我方队伍全军覆没，不要灰心，继续努力！" << endl;
        return -1;
    }

    t.gotoXY(22, 27);
    cout << "我方队伍成功获胜，获得50金币，和5块豆腐！" << endl;


    // 获得50金币、豆腐*5
    list_Enemy.clear();
    list_Player.clear();

    free(Enemy_01);
    Enemy_01 = NULL;
    free(Enemy_02);
    Enemy_02 = NULL;

    MyPack.GoldCoin += 50;
    for (int i = 0; i < 5; i++)
    {
        MyPack.ShopSnack[i] = goods->SackPack[0];
        MyPack.snack_num++;
    }

    return 0;
}

