#pragma once
#include "Tools.h"
#include "SkillsLeaf.h"

class SkillsBranch
{
public:
	SkillsBranch(const std::vector<SkillsLeaf*>& _leaves);
	~SkillsBranch();

	void Update();

private:
	std::vector<SkillsLeaf*> m_branch;

};
