#ifndef SKILLBASE
#define SKILLBASE
#include "Skill.h"

//��Ҽ���
class PlayerSkill :public skill
{
public:

	PlayerSkill();
	PlayerSkill(int skillType, int cost, int num = 0);
	virtual~PlayerSkill();

	skill MySkill[4];    //�䱸���ܣ�����ĸ�
	int skillnum;        //��ǰ����
};

#endif // !SKILLBASE


