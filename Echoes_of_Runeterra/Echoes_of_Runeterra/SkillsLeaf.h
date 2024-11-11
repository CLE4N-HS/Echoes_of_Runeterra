#pragma once
#include "Window.h"
#include "Skills.h"

class SkillsLeaf
{
public:
	SkillsLeaf(Skills* _skill);
	~SkillsLeaf();

	void update(Window& _window);

private:
	Skills* m_skill;

};
