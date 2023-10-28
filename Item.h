#ifndef ITEM
#define ITEM
#include "Property.h"
#include <map>
#include <string>

enum Snacks;
enum Toys;

class Item
{
public:

    Item();
    Item(int type, int cost);
    virtual ~Item();

    Property Property;  //属性
    int type; //对应枚举
    int pay;  //价格
};

class snack :public Item
{
public:

    snack();
    snack(int type, int cost);
    virtual ~snack();

    Snacks SackPack;  //零食
};

class Toy :public Item
{
public:

    Toy();
    Toy(int type, int cost);
    virtual ~Toy();

    Toys ToysType;    //玩具
};

// 商品
enum Snacks
{
    Tofu = 1,          //1.豆腐
    Candy,             //2.糖果
    Donut,             //3.甜甜圈
    Popcorn,           //4.爆米花
    PlumJuice,         //5.梅子汁
    BreadfruitJuice,   //6.面包果汁
    MangoSmoothie,     //7.芒果冰沙
    PeachSoda,         //8.桃子汽水
    coffee,            //9.咖啡
    LifeJam            //10.生命果酱
};

//玩具
enum Toys
{
    Sparkler = 1,  //1.烟花棒  让一名队友或敌人变得开心
    Confetti,      //2.五彩纸片 让所有队友变得开心
    PoetryBook,    //3.诗集  让一名队友或敌人变得悲伤
    RainCloud,     //4.雨云
    Present,       //5.礼物
    AirHorn,       //6.空气喇叭 让所有队友变得生气
    Dandelion      //7.蒲公英   消除一名队友或敌人的情绪
};

const std::map<Snacks, std::string> Map_Snacks = {
    {Snacks::Tofu, "豆腐"},
    {Snacks::Candy, "糖果"},
    {Snacks::Donut, "甜甜圈"},
    {Snacks::Popcorn, "爆米花"},
    {Snacks::PlumJuice, "梅子汁"},
    {Snacks::BreadfruitJuice, "面包果汁"},
    {Snacks::MangoSmoothie, "芒果冰沙 全体回复40MP"},
    {Snacks::PeachSoda, "桃子汽水"},
    {Snacks::coffee, "咖啡"},
    {Snacks::LifeJam, "生命果酱"},
};

const std::map<Toys, std::string> Map_Toys = {
    {Toys::Sparkler, "烟花棒 "},
    {Toys::Confetti, "五彩纸片"},
    {Toys::PoetryBook, "诗集 "},
    {Toys::RainCloud, "雨云"},
    {Toys::Present, "礼物"},
    {Toys::AirHorn, "空气喇叭"},
    {Toys::Dandelion, "蒲公英  消除一名队友或敌人的情绪"},
};

#endif // !ITEM


