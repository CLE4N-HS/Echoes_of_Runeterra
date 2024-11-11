#pragma once
#include "Window.h"
#include "SkillsBranch.h"

class SkillsTree
{
public:
	SkillsTree(const std::vector<SkillsBranch*>& _branches);
	~SkillsTree();

	void update(Window& _window);

private:
	std::vector<SkillsBranch*> m_tree;

};
