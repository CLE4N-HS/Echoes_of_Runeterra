#include "SkillsTree.h"

SkillsTree::SkillsTree(const std::vector<SkillsBranch*>& _branches)
{
	m_tree.reserve(sizeof(SkillsBranch*) * _branches.size());
	for (size_t i = 0; i < _branches.size(); i++)
	{
		m_tree.push_back(_branches[i]);
	}
}

SkillsTree::~SkillsTree()
{
}
