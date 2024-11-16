#include "SkillsTree.h"

SkillsTree::SkillsTree(const std::vector<SkillsBranch*>& _branches) : m_xp(0), m_levelXp(1)
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

void SkillsTree::update(Window& _window)
{
	for (size_t i = 0; i < m_tree.size(); i++)
	{
		m_tree[i]->update(_window);
	}
}
