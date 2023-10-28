#include "Skill.h"

skill::skill() : skill_type(0), cost(0), Choose(false), SkillProperty() {};

skill::skill(int skillType, int cost)
{
	this->skill_type = skillType;
	this->cost = cost;
}

skill::~skill() {};