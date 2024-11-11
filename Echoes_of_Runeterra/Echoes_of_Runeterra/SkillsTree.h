#pragma once
#include "Window.h"
#include "SkillsBranch.h"

class SkillsTree
{
public:
	SkillsTree(const std::vector<SkillsBranch*>& _branches);
	~SkillsTree();

private:
	std::vector<SkillsBranch*> m_tree;

};
