#include "Fight.h"
#include "Define.h"
#include "Weapon.h"
#include "Tool.h"
#include "Pack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//�����ʼ��
Fight::Fight()
{
    //��ɫ��ʼ��
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

    //������ʼ��
    MyPack.GoldCoin = 0;

    //��Ʒ��ʼ��
    goods = new ShopGoods;
    WeaponInit();
    ItemInit();

    //��ӽ�ɫ���ܳ�ʼ��+ѡ��
    PlayerInit(A);
    PlayerInit(B);
    PlayerInit(C);
    PlayerInit(D);

}

//������Գ�ʼ������
int Fight::PlayerInit(Player* player)
{
    player->level = 1; //��ʼ���ȼ�

    SkillInit(player); //��ʼ������


    //����Ĭ���������� �����ӵ�м����䵽�����䱸��
    player->SkillTack.skillnum = 4;
    player->SkillTack.MySkill[0] = player->Skills[0];
    player->SkillTack.MySkill[1] = player->Skills[1];
    player->SkillTack.MySkill[2] = player->Skills[2];
    player->SkillTack.MySkill[3] = player->Skills[3];

    return 0;
}

//��ɫ���ܳ�ʼ��
int Fight::SkillInit(Player* player)
{
    //��ʼ����ɫ��������
    PlayerSkill InitSkill_A[7] = { PlayerSkill(Guard_A,0),PlayerSkill(SadPoem,5),PlayerSkill(Stab,13),PlayerSkill(HackAway,30),PlayerSkill(Trick,20),PlayerSkill(Stare,45),PlayerSkill(FinalStrike,50) };
    PlayerSkill InitSkill_B[7] = { {Guard_B,0},{PepTal,5},{Twirl,10},{PowerHit,20},{Beatdown,30},{WindupThrow,20},{LastResort,50} };
    PlayerSkill InitSkill_C[7] = { {Guard_C,0},{Annoy,5},{Rebound,15},{RunGun,15},{Megaphone,45},{CantCatchMe,50},{Tickle,55} };
    PlayerSkill InitSkill_D[7] = { {Guard_D,0},{Cook,5},{Massage,25},{Smile,25},{TeaTime,25},{HomemadeJam,40},{Dazzle,35} };

    switch (player->PlayRole)
    {
    case Player_A:
    {
        // ���ܳ�ʼ��
        for (int i = 0; i < 7; i++)
        {
            //����������A������ɫA������
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

        //���ݽ�ɫ�ȼ����Ӽ���
        switch (player->level) {
        case 1:
        {
            //�����������
            WeaponAddition(player, ShinyKnife);
            //����Ĭ����������
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //����Ĭ����������
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //����Ĭ����������
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //����Ĭ����������
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //����Ĭ����������
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //����Ĭ����������
            player->Skills[6].Choose = true;
        }
        break;

        }
    }

    break;
    case Player_B:
    {
        // ���ܳ�ʼ��
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
            //�����������
            WeaponAddition(player, StuffedToy);
            //����Ĭ����������
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //����Ĭ����������
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //����Ĭ����������
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //����Ĭ����������
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //����Ĭ����������
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //����Ĭ����������
            player->Skills[6].Choose = true;
        }
        break;
        }
    }
    break;
    case Player_C:
    {
        // ���ܳ�ʼ��
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
            //�����������
            WeaponAddition(player, RubberBall);
            //����Ĭ����������
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //����Ĭ����������
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //����Ĭ����������
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //����Ĭ����������
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //����Ĭ����������
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //����Ĭ����������
            player->Skills[6].Choose = true;
        }
        break;

        }

    }
    break;
    case Player_D:
    {
        // ���ܳ�ʼ��
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
            //�����������
            WeaponAddition(player, GC);
            //����Ĭ����������
            player->Skills[0].Choose = true;
            player->Skills[1].Choose = true;
        }
        break;
        case 3:
        {
            //����Ĭ����������
            player->Skills[2].Choose = true;
            player->SkillTack.MySkill[2] = player->Skills[2];
            player->SkillTack.skillnum++;
        }
        break;
        case 5:
        {
            //����Ĭ����������
            player->Skills[3].Choose = true;
            player->SkillTack.MySkill[3] = player->Skills[3];
            player->SkillTack.skillnum++;
        }
        break;
        case 7:
        {
            //����Ĭ����������
            player->Skills[4].Choose = true;
        }
        break;
        case 8:
        {
            //����Ĭ����������
            player->Skills[5].Choose = true;
        }
        break;
        case 10:
        {
            //����Ĭ����������
            player->Skills[6].Choose = true;
        }
        break;

        }

    }
    break;
    }
    return 0;
}

//������ʼ��
int Fight::WeaponInit()
{
    //����ȫ�ֱ�����ʼ��
    for (int i = 0; i < 12; i++)
    {
        WeaponPack[i].WeaponType = (Weapon)(i + 1); //����������
        switch (WeaponPack[i].WeaponType)
        {
        case ShinyKnife:    //ATK+5 HIT+100%
        {
            WeaponPack[i].WeaponProperty.Atk += 5;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case RustyKnife:    //ATK+11�� DEF+2 �� SPD+6��LUCK+4�� HIT+100%

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
        case Pillow:        //HP+10��ATK+8��HIT+100%
        {
            WeaponPack[i].WeaponProperty.HP += 10;
            WeaponPack[i].WeaponProperty.Atk += 8;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case BaseballBat:   //HP+10, ATK+20�� SPD+10, LUCK+10, HIT+100
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
        case Coconut:       //����+50��ATK+8�� HIT+100%
        {
            WeaponPack[i].WeaponProperty.MP += 50;
            WeaponPack[i].WeaponProperty.Atk += 8;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case Basketball:    //����+50��ATK+15,SPD+100, LUCK+15,HIT+100
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
        case JBQ:           //����+30��ATK+7��HIT+100%
        {
            WeaponPack[i].WeaponProperty.MP += 30;
            WeaponPack[i].WeaponProperty.Atk += 7;
            WeaponPack[i].WeaponProperty.Hit += 1;
        }
        break;
        case Friend:        //HP+20������+20�� ATK+20��HIT+100%
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

int Fight::ItemInit()//������ʼ��
{
    //��ʼ����������
    snack ShopSnack[10] = { snack(Tofu,2),{Candy,20},{Donut,30},{Popcorn,50},{PlumJuice,5},{BreadfruitJuice,20},{MangoSmoothie,50},{PeachSoda,30},{coffee,25},{LifeJam,100} };
    Toy  ShopTool[7] = { {Sparkler,20},{Confetti,50},{PoetryBook,20},{RainCloud,50},{Present,20},{AirHorn,50},{Dandelion,30} };

    //��ʳ��ʼ
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
        case Candy:    //ATK+11�� DEF+2 �� SPD+6��LUCK+4�� HIT+100%

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
        case PlumJuice:        //HP+10��ATK+8��HIT+100%
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.MP += 15;
        }
        break;
        case BreadfruitJuice:   //HP+10, ATK+20�� SPD+10, LUCK+10, HIT+100
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
        case PeachSoda:       //����+50��ATK+8�� HIT+100%
        {
            goods->SackPack[i].Property.Part = single;
            goods->SackPack[i].Property.Handle = Add;
            goods->SackPack[i].Property.InfightPropertype = MP;
            goods->SackPack[i].Property.scale = 0.6;
        }
        break;
        case coffee:    //����+50��ATK+15,SPD+100, LUCK+15,HIT+100
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

    //��߳�ʼ
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
        case Confetti:    //ATK+11�� DEF+2 �� SPD+6��LUCK+4�� HIT+100%
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
        case Present:        //HP+10��ATK+8��HIT+100%
        {
            goods->ToyPack[i].Property.Part = single;
            goods->ToyPack[i].Property.EmoChange = ANGRY;
        }
        break;
        case AirHorn:   //HP+10, ATK+20�� SPD+10, LUCK+10, HIT+100
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

//��ɫ������� ͨ����������ö�������䱸
int Fight::WeaponAddition(Player* player, Weapon WeaponType)
{
    //�����������
    player->WeaponType = WeaponType;
    //���������������������Լӳ�
    player->Property_AddHandle(WeaponPack[(int)(player->WeaponType - 1)].WeaponProperty);

    return 0;
}

//��ʳ�ӳ�
int Fight::SnackAddition(Player* player, snack goodstype)
{
    switch (goodstype.type)
    {
        //���嵥��
    case Tofu:
    case Candy:
    case PlumJuice:
    case BreadfruitJuice:
        //ȫ�嵥��
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
        //�ٷֱ���
    case Donut:
    case PeachSoda:
        player->Property_FightPropertyHandle(goodstype.Property);
        break;
        //buff��
    case coffee:
        player->Property_FightPropertyHandle(goodstype.Property);
        break;
    }
    return 0;
}

//��߼ӳ�
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

// SkillType �� �滻�ļ�������  ��δʵ��
// instead : �滻���ڼ�������  
int Fight::SkillChoose(Player* player, int SkillType, int instead)
{
    int instead_ = instead - 1; //�滻������Ǳ�

    //�üܹ�Ϊcost׼��
    switch (player->PlayRole)
    {
    case Player_A:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //���ڲ���
        //                    qDebug()<<QString("*%1").arg(i)<< Map_Skill_A[(Skill_A)player->Skill[i].skill] ;
    }
    break;
    case Player_B:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //���ڲ���
    }
    break;
    case Player_C:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //���ڲ���
    }
    break;
    case Player_D:
    {
        player->SkillTack.MySkill[instead_].skill_type = SkillType;
        player->SkillTack.MySkill[instead_].cost = 0;         //���ڲ���
    }
    break;
    }

    return 0;
}

//�����ͷ�
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
            cout << "Omoriѡ���˷���.";
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
                cout << "Omori����һ�ױ��˵�ʫ,";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "��ñ�����.";
            }

            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                t.gotoXY(47, 3);
                list_Player[chosenPlayer]->emo = SAD;
                cout << "Omori����һ�ױ��˵�ʫ,";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "��ñ�����.";
            }
            break;

        case Stab: //�ض��������Եз��������1.5 x ATK - DEF �˺�������Լ��������Ɐ��״̬����������2 x ATK - DEF �˺�
            chosenEnemy = Enemy_Choose();
            if (player->emo == SAD)
                damage1 = player->calc_Damage(list_Enemy[chosenEnemy], 2.5, 2);
            else
                damage1 = player->calc_Damage(list_Enemy[chosenEnemy], 2, 2);
            if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
            {
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage1;
                t.gotoXY(47, 3);
                cout << "Omoriͱ��һ��" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << ".";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�ܵ� " << damage1 << " �˺�!";
            }
            else
            {
                damage1 = list_Enemy.at(chosenEnemy)->Property_Inbattle.HP;
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP = 0;
                if (list_Enemy.at(chosenEnemy) == Enemy_01)
                {
                    t.clear(38 + 5, 13, 8, 1);
                    t.gotoXY(38, 13);
                    cout << "����: 0";
                }
                else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                {
                    t.clear(62 + 5, 13, 8, 1);
                    t.gotoXY(62, 13);
                    cout << "����: 0";
                }
                t.gotoXY(47, 3);
                cout << "Omoriͱ��һ��" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << ".";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�ܵ� " << damage1 << " �˺�!";
                list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
            }
            break;

        case HackAway: //�������Σ�������е���, ÿ���˺� 2 x ATK - DEF�� ����Լ����������ŭ״̬�� ÿ���˺� 2.25 x ATK - DEF
            t.gotoXY(47, 3);
            cout << Map_Player.at(player->PlayRole) << "�����ҿ�." << endl;
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
                    cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "0" << list_Enemy[RandEnemy]->Fight_Num << "�ܵ� " << damage1 << " �˺�!" << endl;
                }
                else
                {
                    damage1 = list_Enemy.at(RandEnemy)->Property_Inbattle.HP;
                    list_Enemy.at(RandEnemy)->Property_Inbattle.HP = 0;
                    if (list_Enemy.at(RandEnemy) == Enemy_01)
                    {
                        t.clear(38 + 5, 13, 8, 1);
                        t.gotoXY(38, 13);
                        cout << "����: 0";
                    }
                    else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                    {
                        t.clear(62 + 5, 13, 8, 1);
                        t.gotoXY(62, 13);
                        cout << "����: 0";
                    }
                    t.gotoXY(47, 4 + i);
                    cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "0" << list_Enemy[RandEnemy]->Fight_Num << "�ܵ� " << damage1 << " �˺�!" << endl;
                    list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
                }
            }
            break;

        case Trick: //�Եз�������� 3 x ATK - DEF �˺�������з��������⿪��״̬�����ٶȽ���75%��debuff) 

            damage1 = player->calc_Damage(list_Enemy[RandEnemy], 3, 1);
            list_Enemy[RandEnemy]->Property_Inbattle.HP -= damage1;

            t.gotoXY(47, 3);
            cout << "Omori��" << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "��������.";
            list_Enemy.at(RandEnemy)->Property_Inbattle.Spd -= list_Enemy.at(RandEnemy)->Property_Def.Spd * 0.1;
            t.gotoXY(47, 4);
            cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "�ܵ� " << damage1 << " �˺�!" << endl;
            t.gotoXY(47, 5);
            cout << Map_Enemy.at(list_Enemy.at(RandEnemy)->Type) << "���ٶ��½���!" << endl;
            break;

        case FinalStrike:
            if (player->CurrentSkill.SkillProperty.times > 1)
            {
                for (int i = 0; i < player->CurrentSkill.SkillProperty.times; i++)
                    list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            }
            else
                list_Enemy.at(RandEnemy)->Property_Inbattle.HP -= player->CurrentSkill.SkillProperty.Atk;
            std::cout << "A�ͷ��������ռ�������" << std::endl;
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
            cout << Map_Player.at(player->PlayRole) << "ѡ���˷���.";
            break;

        case PepTal: //��һ�����ѻ���˱�ÿ���
            choose = EnemyorPlayer_Choose();
            t.clear(1, 2, 17, 4);
            if (choose == 1)
            {
                chosenEnemy = Enemy_Choose();
                t.gotoXY(47, 3);
                list_Enemy[chosenEnemy]->emo = HAPPY;
                cout << "Aubrey��" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "����,";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "��ÿ�����!";
            }

            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                t.gotoXY(47, 3);
                list_Player[chosenPlayer]->emo = HAPPY;
                cout << "Aubrey��" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "����,";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "��ÿ�����!";
            }
            break;

        case Twirl: //����һ�����ˣ�Ȼ���ÿ���
            damage1 = player->calc_Damage(list_Enemy.at(chosenEnemy), 2.5, 1);
            if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
            {
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage1;
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "������" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�ܵ� " << damage1 << " �˺�!";
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
                    cout << "����: 0";
                }
                else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                {
                    t.clear(62 + 5, 13, 8, 1);
                    t.gotoXY(62, 13);
                    cout << "����: 0";
                }
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "������" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�ܵ� " << damage1 << " �˺�!";
                list_Enemy.erase(list_Enemy.begin() + chosenEnemy);
            }

            t.gotoXY(47, 5);
            player->emo = HAPPY;
            cout << Map_Player.at(player->PlayRole) << "��ÿ�����!";
            break;

        case PowerHit: //���͵��˷����� �˺���2.5 x ATK
            damage1 = player->calc_Damage(list_Enemy.at(RandEnemy), 2.5, 1);
            if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
            {
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage1;
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "�ӳ�����������!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�ܵ�  " << damage1 << " �˺�!";
                t.gotoXY(47, 5);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�ķ����½���!";
            }
            else
            {
                damage1 = list_Enemy.at(chosenEnemy)->Property_Inbattle.HP;
                list_Enemy.at(chosenEnemy)->Property_Inbattle.HP = 0;
                if (list_Enemy.at(chosenEnemy) == Enemy_01)
                {
                    t.clear(38 + 5, 13, 8, 1);
                    t.gotoXY(38, 13);
                    cout << "����: 0";
                }
                else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                {
                    t.clear(62 + 5, 13, 8, 1);
                    t.gotoXY(62, 13);
                    cout << "����: 0";
                }
                t.gotoXY(47, 3);
                cout << Map_Player.at(player->PlayRole) << "�ӳ�����������!";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�ܵ�  " << damage1 << " �˺�!";
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
            cout << Map_Player.at(player->PlayRole) << "ѡ���˷���." << endl;
            break;

        case Annoy:
            choose = EnemyorPlayer_Choose();
            t.clear(1, 2, 17, 4);
            if (choose == 1)
            {
                chosenEnemy = Enemy_Choose();
                t.gotoXY(47, 3);
                list_Enemy[chosenEnemy]->emo = ANGRY;
                cout << "Kel��" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "���ջ�,";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "���������!";
            }

            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                t.gotoXY(47, 3);
                list_Player[chosenPlayer]->emo = ANGRY;
                cout << "Kel��" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "���ջ�,";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "���������!";
            }
            break;

        case Rebound: //�����е�������˺���2.5 x ATK - DEF
            t.gotoXY(47, 3);
            cout << "Kel��������ȥ!" << endl;
            for (int i = 0; i < list_Enemy.size(); i++)
            {
                damage1 = player->calc_Damage(list_Enemy.at(i), 2.5, 1);

                if (list_Enemy.at(i)->Property_Inbattle.HP > 0 && damage1 <= list_Enemy.at(i)->Property_Inbattle.HP)
                {
                    list_Enemy.at(i)->Property_Inbattle.HP -= damage1;
                    t.gotoXY(47, 4 + i);
                    cout << Map_Enemy.at(list_Enemy.at(i)->Type) << "0" << list_Enemy[i]->Fight_Num << "�ܵ��� " << damage1 << " �˺�!" << endl;
                }
                else
                {
                    damage1 = list_Enemy.at(i)->Property_Inbattle.HP;
                    list_Enemy.at(i)->Property_Inbattle.HP = 0;
                    if (list_Enemy.at(i) == Enemy_01)
                    {
                        t.clear(38 + 5, 13, 8, 1);
                        t.gotoXY(38, 13);
                        cout << "����: 0";
                    }
                    else if (list_Enemy.at(i) == Enemy_02)
                    {
                        t.clear(62 + 5, 13, 8, 1);
                        t.gotoXY(62, 13);
                        cout << "����: 0";
                    }
                    t.gotoXY(47, 4 + i);
                    cout << Map_Enemy.at(list_Enemy.at(i)->Type) << "0" << list_Enemy[i]->Fight_Num << "�ܵ��� " << damage1 << " �˺�!" << endl;
                    to_delete.push_back(i);
                    //cnt[i] = 1; //���Ӧ��ɾ���ĵ���
                }
            }

            //ɾ������
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

        case RunGun: //ʹ���ٶ�ֵ���ǹ���������һ�ι��� 1.5 x SPD - DEF

        case Megaphone: //�����ж��ѱ������
            t.gotoXY(47, 3);
            cout << "Kel�Ĵ�ɧ��,�Ѵ��Ū���ķ�����." << endl;
            for (int i = 0; i < list_Player.size(); i++)
            {
                list_Player.at(i)->emo = ANGRY;
                t.gotoXY(47, 4 + i);
                cout << Map_Player.at(list_Player.at(i)->PlayRole) << "���������!" << endl;
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
            cout << Map_Player.at(player->PlayRole) << "ѡ���˷���." << endl;
            break;

        case Cook: //�����ѻ�Ѫ
            chosenPlayer = Player_Choose();
            p.InfightPropertype = HP;
            heal = list_Player[chosenPlayer]->Property_Def.HP - list_Player[chosenPlayer]->Property_Inbattle.HP;
            list_Player[chosenPlayer]->Property_Handle(p, Add, 0.75);

            //��Ѫ�����Ѫ�۵����
            if (list_Player[chosenPlayer]->Property_Inbattle.HP > list_Player[chosenPlayer]->Property_Def.HP)
            {
                list_Player[chosenPlayer]->Property_Inbattle.HP = list_Player[chosenPlayer]->Property_Def.HP;
                t.gotoXY(47, 3);
                cout << "Hero��" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "�ֹ�����������";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "�ָ���" << heal << "����.";
            }
            else
            {
                t.gotoXY(47, 3);
                cout << "Hero��" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "�ֹ�����������";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "�ָ���" << 0.75 * list_Player[chosenPlayer]->Property_Def.HP << "����.";
            }
            break;

        case Massage: //�Ƴ�һ�����ѻ���˵�����
            choose = EnemyorPlayer_Choose();
            if (choose == 1)
            {
                chosenEnemy = Enemy_Choose();
                list_Enemy[chosenEnemy]->emo = Normal;
                t.gotoXY(47, 3);
                cout << "Hero��" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "��Ħ.";
                t.gotoXY(47, 4);
                cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�侲������.";
            }
            else if (choose == 2)
            {
                chosenPlayer = Player_Choose();
                list_Player[chosenPlayer]->emo = Normal;
                t.gotoXY(47, 3);
                cout << "Hero��" << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "��Ħ.";
                t.gotoXY(47, 4);
                cout << Map_Player.at(list_Player[chosenPlayer]->PlayRole) << "�侲������.";
            }
            break;

        case Smile: //����һ�����˵Ĺ���
            chosenEnemy = Enemy_Choose();
            p.InfightPropertype = Atk;
            list_Enemy[chosenEnemy]->Property_Handle(p, Sub, 0.1);
            t.gotoXY(47, 3);
            cout << "Hero����" << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "΢Ц,";
            t.gotoXY(47, 4);
            cout << Map_Enemy.at(list_Enemy[chosenEnemy]->Type) << "0" << list_Enemy[chosenEnemy]->Fight_Num << "�Ĺ����½���!";
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

//�����ͷ�(����)
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

//ѡ����ʱ�����
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

//ʹ����ʳʱ��ʾ
int Fight::useSnack_Print(Player* player)
{
    Tool t;
    int x = 1;
    int choose = 0;
    if (MyPack.snack_num == 0)
    {
        t.gotoXY(1, 2);
        cout << "������ʳ";
        t.wait(500);
        return -1;
    }
    else
    {
        t.gotoXY(1, 2);
        cout << "ѡ��ʹ�õ���ʳ:";
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

//ʹ�����ʱ��ʾ
int Fight::useToy_Print(Player* player)
{
    Tool t;
    int x = 1;
    int choose = 0;
    if (MyPack.toy_num == 0)
    {
        t.gotoXY(1, 2);
        cout << "�������";
        t.wait(500);
        return -1;
    }
    else
    {
        t.gotoXY(1, 2);
        cout << "ѡ��ʹ�õ����:";
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

//���ս����ѡ��
void Fight::Infight_Choose_Print(Player* player)
{
    Tool t;
    t.gotoXY(43, 22);
    cout << "1.��ͨ����";
    t.gotoXY(60, 22);
    cout << "2.ʹ�ü���";
    t.gotoXY(43, 23);
    cout << "3.ʹ����ʳ";
    t.gotoXY(60, 23);
    cout << "4.ʹ�����";
    t.gotoXY(43, 24);
    cout << Map_Player.at(player->PlayRole) << "�Ļغ�," "����ѡ��!";
}

//��������Ϣ
void Fight::Show_Info(int type, Player* player)
{
    if (type == 0)
    {
        Tool t;
        //���Ͻ�
        t.gotoXY(24, 3);
        t.clear(24, 3, 20, 1);
        t.gotoXY(24, 3);
        cout << "Aubrey (" << map_EmoStatusNames.at(B->emo) << ")";
        if (this->B->Property_Inbattle.HP <= 0)
            this->B->Property_Inbattle.HP = 0;
        t.gotoXY(24, 4);
        t.clear(29, 4, 10, 1);
        t.gotoXY(24, 4);
        cout << "����: " << this->B->Property_Inbattle.HP;
        if (this->B->Property_Inbattle.MP <= 0)
            this->B->Property_Inbattle.MP = 0;
        t.gotoXY(24, 5);
        t.clear(29, 5, 10, 1);
        t.gotoXY(24, 5);
        cout << "����: " << this->B->Property_Inbattle.MP;

        // ���Ͻ�
        t.gotoXY(82, 3);  
        t.clear(82, 3, 15, 1);
        t.gotoXY(82, 3);
        cout << "Hero (" << map_EmoStatusNames.at(D->emo) << ")";
        if (this->D->Property_Inbattle.HP <= 0)
            this->D->Property_Inbattle.HP = 0;
        t.gotoXY(82, 4);
        t.clear(87, 4, 5, 1);
        t.gotoXY(82, 4);
        cout << "����: " << this->D->Property_Inbattle.HP;
        //t.gotoXY(82, 5);
        if (this->D->Property_Inbattle.MP <= 0)
            this->D->Property_Inbattle.MP = 0;
        t.gotoXY(82, 5);
        t.clear(87, 5, 10, 1);
        t.gotoXY(82, 5);
        cout << "����: " << this->D->Property_Inbattle.MP;

        // ���½�
        t.gotoXY(24, 18);
        t.clear(24, 18, 20, 1);
        t.gotoXY(24, 18);
        cout << "Omori (" << map_EmoStatusNames.at(A->emo) << ")";
        if (this->A->Property_Inbattle.HP <= 0)
            this->A->Property_Inbattle.HP = 0;
        t.gotoXY(24, 19);
        t.clear(29, 19, 10, 1);
        t.gotoXY(24, 19);
        cout << "����: " << this->A->Property_Inbattle.HP;
        if (this->A->Property_Inbattle.MP <= 0)
            this->A->Property_Inbattle.MP = 0;
        t.gotoXY(24, 20);
        t.clear(29, 20, 10, 1);
        t.gotoXY(24, 20);
        cout << "����: " << this->A->Property_Inbattle.MP;

        // ���½�
        t.gotoXY(82, 18);
        t.clear(82, 18, 15, 1);
        t.gotoXY(82, 18);
        cout << "kel (" << map_EmoStatusNames.at(C->emo) << ")";
        if (this->C->Property_Inbattle.HP <= 0)
            this->C->Property_Inbattle.HP = 0;
        t.gotoXY(82, 19);
        t.clear(87, 19, 10, 1);
        t.gotoXY(82, 19);
        cout << "����: " << this->C->Property_Inbattle.HP;
        if (this->C->Property_Inbattle.MP <= 0)
            this->C->Property_Inbattle.MP = 0;
        t.gotoXY(82, 20);
        t.clear(87, 20, 10, 1);
        t.gotoXY(82, 20);
        cout << "����: " << this->C->Property_Inbattle.MP;
    }
}

//����߿�
void Fight::Screen_Print()
{
    Tool t;

    t.gotoXY(20, 1);
    cout << "��";
    for (int i = 0; i < 80; ++i)
        cout << "��";
    cout << "��";

    t.gotoXY(20, 25);
    cout << "��";
    for (int i = 0; i < 80; ++i)
        cout << "��";
    cout << "��";

    for (int i = 2; i <= 24; ++i)
    {
        t.gotoXY(20, i);
        cout << "��";
        t.gotoXY(101, i);
        cout << "��";
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
            if (enemy->Fight_Num == 1) //���յ�������������˳��
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
            cout << "����: " << enemy->Property_Inbattle.HP;
        }
    }
    else
    {
        t.clear(47, 3, 30, 5); //���������˺���Ϣ
        t.clear(38, 12, 50, 5); //���ǵ�����Ϣ
        t.gotoXY(50, 12);
        cout << "��ȫ�����";
    }
}

// ѡ����
int Fight::Infight_01(Player* player)
{
    Tool t;
    int Input;

    // ʹ�ü���
    player->InfightChoose = Skill;

    while (true)
    {
        Input = useSkill_Print(player); // �����ɫѡ������ʾ
        if (Input == 0);
        if (player->Property_Inbattle.MP > player->SkillTack.MySkill[Input - 1].cost)
        {
            // ����ѡ������
            player->CurrentSkill = player->SkillTack.MySkill[Input - 1];
            player->Property_Inbattle.MP -= player->SkillTack.MySkill[Input - 1].cost;
            break;
        }
        else
        {
            for (int i = 26; i <= 28; i++)
                t.clearLine(1, i);
            t.gotoXY(25, 26);
            cout << "�������㣬�޷��ͷŸü��ܣ�";
            t.wait(1000);
            t.clearLine(25, 26);
            Infight_01(player);
        }
    }

    return 0;
}

//ѡ����ʳ���
// ������ type �� 0 ��ʳ��1 ��� || player �� ������
int Fight::Infight_02(int type, Player* player)
{
    Tool t;
    int Input;
    if (type == 0) //��ʳ
    {
        //�����ɫѡ������ʾ
        int Input = useSnack_Print(player);

        if (Input == -1) //������ʳ���
        {
            t.clear(1, 2, 15, 20);
            return -1;
        }

        if (Input <= MyPack.toy_num)
        {
            t.gotoXY(47, 3);
            cout << Map_Player.at(player->PlayRole) << "����:" << Map_Snacks.at(static_cast<Snacks>(MyPack.ShopSnack[Input - 1].type)) << "!";
            // ��ʳ�ӳ�
            SnackAddition(player, MyPack.ShopSnack[Input - 1]);
            memset(&MyPack.ShopSnack[Input - 1], 0, sizeof(snack));
            MyPack.snack_num--;
        }
    }
    else if (type == 1)  //���
    {
        //�����ɫѡ������ʾ
        int Input = useToy_Print(player);

        if (Input == -1) //����������
        {
            t.clear(1, 2, 15, 20);
            return -1;
        }

        if (Input <= MyPack.toy_num)
        {
            t.gotoXY(48, 3);
            cout << Map_Player.at(player->PlayRole) << "ʹ����:" << Map_Toys.at(static_cast<Toys>(MyPack.ShopToy[Input - 1].type)) << "!";

            // ��ʳ�ӳ�
            ToyAddition(player, MyPack.ShopToy[Input - 1]);
            memset(&MyPack.ShopToy[Input - 1], 0, sizeof(Toy));
            MyPack.toy_num--;
        }
    }
    t.clear(1, 2, 15, 20);
    return 0;
}

//���������������
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

//ѡ���ض�����
int Fight::Enemy_Choose()
{
    Tool t;

    t.gotoXY(1, 2);
    cout << "��ѡ���빥���ĵ���";
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
        t.clear(1, 2, 18, 25); //����ѯ�ʹ���������Ϣ
        t.gotoXY(1, 2);
        cout << "��������,��������.";
        t.wait(500);
        Enemy_Choose();
    }
}

//ѡ���ض�����
int Fight::Player_Choose()
{
    Tool t;

    t.gotoXY(1, 2);
    cout << "��ѡ�����";
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
        t.clear(1, 2, 19, 25); //����ѯ����Ϣ
        t.gotoXY(1, 2);
        cout << "��������,��������.";
        t.wait(500);
        Player_Choose();
    }
}

//ѡ����˻����
int Fight::EnemyorPlayer_Choose()
{
    Tool t;
    int choose = 1;

    t.gotoXY(1, 2);
    cout << "ѡ����˻��Ƕ���?";
    t.gotoXY(1, 3);
    cout << "1. ����";
    t.gotoXY(1, 4);
    cout << "2. ����";

    t.gotoXY(1, 5);
    cin >> choose;

    if (choose == 1 || choose == 2)
        return choose;
    else
    {
        t.clear(1, 2, 18, 25); //����ѯ����Ϣ
        t.gotoXY(1, 2);
        cout << "��������,��������.";
        t.wait(500);
        EnemyorPlayer_Choose();
    }
}

//ս��ģ��-�ж�ʤ������
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
        return 2; //��Ϸ�ɹ�

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
        return 0; //��Ϸʧ��

    return 1; //��Ϸ����
}

//��ս������
int Fight::fight()
{

    Screen_Print();

    Tool t;
    int Input;
    int x = 0;
    Player* player = nullptr;
    Enemy* enemy = nullptr;

    //��ʼ���б�
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

    //�ж�Ѫ��
    while (ListHPCheck())
    {
     
        bool Fight_suc = false;

       //���ж��ٶȣ������ж�˳��
        listRand.clear();
        for (int i = 0; i < list_Player.size(); i++)
        {
            listRand.push_back(list_Player.at(i)->Property_Inbattle.Spd);
        }

        //�����ٶ��ɸߵ��ͽ�������
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

        // ����Ĭ��ѡ�����˳��ѡ��
        // ��ʾ������Ϣ
        Show_EnemyInfo(0);
        x = 0;
        int ret = 0;

        //��Ҳ�����ѭ
        for (int j = 0; j < list_Player.size(); j++)
        {
            Random();//���������������

            //�ж���˭
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

            // �ؼ�������ʼ��
            memset(&player->CurrentSkill, 0, sizeof(skill));
            player->InfightChoose = Nothing;

            //���ս��ѡ��
            int RETURN = 0;
            do {
                RETURN = 0;
                Infight_Choose_Print(player);

                cin >> Input;
                cin.ignore(); //��������ַ�

                t.clear(47, 3, 30, 5); //�����һ�ع�����Ϣ
                t.clear(43, 24, 50, 1); //���ѡ������

                player->InfightChoose = static_cast<FightChoose>(Input);

                int damage = 0;
                int chosenEnemy = 0;

                switch (player->InfightChoose) {
                case NormalAttack: //�չ�
                    chosenEnemy = Enemy_Choose();
                    damage = player->calc_Damage(list_Enemy.at(chosenEnemy), 2, 1);
                    if (list_Enemy.at(chosenEnemy)->Property_Inbattle.HP > 0 && damage <= list_Enemy.at(chosenEnemy)->Property_Inbattle.HP)
                    {
                        list_Enemy.at(chosenEnemy)->Property_Inbattle.HP -= damage;
                        t.gotoXY(47, 3);
                        cout << Map_Player.at(player->PlayRole) << "������" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "!";
                        t.gotoXY(47, 4);
                        cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "�ܵ� " << damage << " �˺�!";
                    }
                    else
                    {
                        damage = list_Enemy.at(chosenEnemy)->Property_Inbattle.HP;
                        list_Enemy.at(chosenEnemy)->Property_Inbattle.HP = 0;
                        if (list_Enemy.at(chosenEnemy) == Enemy_01)
                        {
                            t.clear(38 + 5, 13, 8, 1);
                            t.gotoXY(38, 13);
                            cout << "����: 0";
                        }
                        else if (list_Enemy.at(chosenEnemy) == Enemy_02)
                        {
                            t.clear(62 + 5, 13, 8, 1);
                            t.gotoXY(62, 13);
                            cout << "����: 0";
                        }
                        t.gotoXY(47, 3);
                        cout << Map_Player.at(player->PlayRole) << "������" << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "!";
                        t.gotoXY(47, 4);
                        cout << Map_Enemy.at(list_Enemy.at(chosenEnemy)->Type) << "�ܵ� " << damage << " �˺�!";
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
                    cout << "ѡ�����������ѡ��" << endl;
                    Input = -1;
                    break;
                }
            } while (RETURN == -1);

            //������������Ϣ
            Show_Info(0, A);
            Show_Info(0, B);
            Show_Info(0, C);
            Show_Info(0, C);

            t.clear(1, 2, 18, 25); //����ѯ�ʹ���������Ϣ
            ret = ListHPCheck();
            Show_EnemyInfo(0); //������ʾ����Ѫ�� 
            if (ret == 2)
            {
                Fight_suc = true;
                return 0;           //�ɹ�
            }
        }

        //���˲�����ѯ
        for (int j = 0; j < list_Enemy.size(); j++)
        {
            t.wait(1500);
            Random();
            t.clear(47, 3, 35, 3); //�����һ�ع�����Ϣ
            list_Enemy.at(j)->EmoStatus(Map_Player.at(list_Player.at(RandPlayer)->PlayRole), list_Player, RandPlayer);

            ret = ListHPCheck();
            if (ret == 0)
            {
                Fight_suc = true;
                return -1;           //�ɹ�
            }

            if (list_Player.size() != 0) //Ѫ����Ϊ�㣬���뺯��
                Show_Info(0, list_Player.at(RandPlayer));
            else //������պ����
            {
                t.clear(29, 4, 10, 1);
                t.gotoXY(24, 4);
                cout << "����: " << this->B->Property_Inbattle.HP;
                t.clear(87, 4, 10, 1);
                t.gotoXY(82, 4);
                cout << "����: " << this->D->Property_Inbattle.HP;
                t.clear(29, 19, 10, 1);
                t.gotoXY(24, 19);
                cout << "����: " << this->A->Property_Inbattle.HP;
                t.clear(87, 19, 5, 1);
                t.gotoXY(82, 19);
                cout << "����: " << this->C->Property_Inbattle.HP;
            }
        }
    }
    return -1;           //�ɹ�
}

//����ģ��
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

    //���ܸ���
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
    // ��ֻɭ������
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


    //ս��
    ret = fight();
    if (ret)
    {
        t.clearLine(22, 27);
        cout << "�ҷ�����ȫ����û����Ҫ���ģ�����Ŭ����" << endl;
        return -1;
    }

    t.gotoXY(22, 27);
    cout << "�ҷ�����ɹ���ʤ�����50��ң���5�鶹����" << endl;


    // ���50��ҡ�����*5
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

