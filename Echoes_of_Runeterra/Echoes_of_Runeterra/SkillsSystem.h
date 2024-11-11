#pragma once
#include "Window.h"
#include "SkillsTree.h"
#include "TreeDataBase.h"

class SkillsSystem
{
public:
	SkillsSystem(TreeDataBase* _treeDB);
	~SkillsSystem();

	void update(Window& _window);

private:
	SkillsTree* m_skillTree;

};
