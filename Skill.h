#ifndef SKILL
#define SKILL
#include "Property.h"

//������
class skill
{
public:

    skill();
    skill(int skillType, int cost);
    virtual ~skill();

    int skill_type;  //��Ӧö��
    int cost;        //����MP
    bool Choose;     //��ѡ����

    // ������������
    Property   SkillProperty;
};

#endif // !SKILL

