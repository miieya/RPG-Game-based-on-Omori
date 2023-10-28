#ifndef SKILL
#define SKILL
#include "Property.h"

//技能类
class skill
{
public:

    skill();
    skill(int skillType, int cost);
    virtual ~skill();

    int skill_type;  //对应枚举
    int cost;        //消耗MP
    bool Choose;     //可选择性

    // 参数调整性能
    Property   SkillProperty;
};

#endif // !SKILL

