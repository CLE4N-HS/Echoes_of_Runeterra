#pragma once
#include "Window.h"
#include "SkillsTree.h"
#include "TreeDataBase.h"

/// <summary>
/// tbh evoqued but not usefull now
/// </summary>
class SkillsSystem
{
public:
	SkillsSystem(TreeDataBase* _treeDB);
	~SkillsSystem();

	void update(Window& _window);

private:
	SkillsTree* m_skillTree;

};
