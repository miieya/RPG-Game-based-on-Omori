#include "SkillBase.h"

PlayerSkill::PlayerSkill() {};

PlayerSkill::PlayerSkill(int skillType, int cost, int num)
{
	this->skill_type = skillType;
	this->cost = cost;
	this->skillnum = 0;
}

PlayerSkill::~PlayerSkill() {};