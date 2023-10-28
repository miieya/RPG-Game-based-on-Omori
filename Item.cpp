#include "Item.h"

//Item����
Item::Item() {};
Item::~Item() {};

Item::Item(int type, int cost)
{
	this->type = type;
	this->pay = cost;
}

//snack������
snack::snack() :SackPack(Tofu) {};
snack::~snack() {};

snack::snack(int type, int cost)
{
	this->type = type;
	this->pay = cost;
	//Item(type, cost);
}

//Toy������
Toy::Toy() :ToysType(Sparkler) {};
Toy::~Toy() {};

Toy::Toy(int type, int cost)
{
	this->type = type;
	this->pay = cost;
	//Item(type, cost);
}