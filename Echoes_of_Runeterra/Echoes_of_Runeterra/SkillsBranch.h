#pragma once
#include "Window.h"
#include "SkillsLeaf.h"

class SkillsBranch
{
public:
	SkillsBranch(const std::vector<SkillsLeaf*>& _leaves);
	~SkillsBranch();

private:
	std::vector<SkillsLeaf*> m_branch;

};
