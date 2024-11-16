#pragma once
#include "Window.h"
#include "SkillsLeaf.h"

class SkillsBranch
{
public:
	SkillsBranch(const std::vector<SkillsLeaf*>& _leaves);
	~SkillsBranch();

	void update(Window& _window);

private:
	std::vector<SkillsLeaf*> m_branch;

};
