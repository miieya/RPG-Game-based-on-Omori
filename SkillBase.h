#ifndef SKILLBASE
#define SKILLBASE
#include "Skill.h"

//玩家技能
class PlayerSkill :public skill
{
public:

	PlayerSkill();
	PlayerSkill(int skillType, int cost, int num = 0);
	virtual~PlayerSkill();

	skill MySkill[4];    //配备技能：最多四个
	int skillnum;        //当前个数
};

#endif // !SKILLBASE


