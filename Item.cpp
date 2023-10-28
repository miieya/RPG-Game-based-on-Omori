#include "Item.h"

//Item基类
Item::Item() {};
Item::~Item() {};

Item::Item(int type, int cost)
{
	this->type = type;
	this->pay = cost;
}

//snack派生类
snack::snack() :SackPack(Tofu) {};
snack::~snack() {};

snack::snack(int type, int cost)
{
	this->type = type;
	this->pay = cost;
	//Item(type, cost);
}

//Toy派生类
Toy::Toy() :ToysType(Sparkler) {};
Toy::~Toy() {};

Toy::Toy(int type, int cost)
{
	this->type = type;
	this->pay = cost;
	//Item(type, cost);
}