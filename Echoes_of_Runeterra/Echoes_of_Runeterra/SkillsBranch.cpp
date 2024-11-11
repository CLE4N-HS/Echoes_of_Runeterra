#include "SkillsBranch.h"

SkillsBranch::SkillsBranch(const std::vector<SkillsLeaf*>& _leaves)
{
	m_branch.reserve(sizeof(SkillsLeaf*) * _leaves.size());
	for (size_t i = 0; i < _leaves.size(); i++)
	{
		m_branch.push_back(_leaves[i]);
	}
}

SkillsBranch::~SkillsBranch()
{
}

void SkillsBranch::update(Window& _window)
{
	for (size_t i = 0; i < m_branch.size(); i++)
	{
		m_branch[i]->update(_window);
	}
}
