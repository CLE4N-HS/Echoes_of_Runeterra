#pragma once
#include "Window.h"
#include "Skills.h"

class SkillsLeaf
{
public:
	SkillsLeaf(Skills* _skill);
	~SkillsLeaf();

private:
	Skills* m_skill;

};
