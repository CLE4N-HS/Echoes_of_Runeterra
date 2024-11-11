#pragma once
#include "Window.h"
#include "SkillsTree.h"

class SkillsSystem
{
public:
	SkillsSystem();
	~SkillsSystem();

	void update(Window& _window);

private:
	SkillsTree* m_skillTree;

};
