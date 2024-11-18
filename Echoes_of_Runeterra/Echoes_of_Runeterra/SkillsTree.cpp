#include "SkillsTree.h"
#include "ComponentName.h"

SkillsTree::SkillsTree() : SkillsTree("", {})
{
}

SkillsTree::SkillsTree(SkillsTree* _skillTree) : SkillsTree(*_skillTree)
{
}

SkillsTree::SkillsTree(const std::string& _name, const std::vector<SkillsBranch*>& _branches) :
	Entity(),
	m_xp(0), m_levelXp(1)
{
	this->AddComponent<ComponentName>(_name);

	m_tree.reserve(sizeof(SkillsBranch*) * _branches.size());
	for (size_t i = 0; i < _branches.size(); i++)
	{
		m_tree.push_back(_branches[i]);
	}
}

SkillsTree::~SkillsTree()
{
}

void SkillsTree::Update()
{
	for (size_t i = 0; i < m_tree.size(); i++)
	{
		m_tree[i]->Update();
	}
}

void SkillsTree::Display()
{
	for (size_t i = 0; i < m_tree.size(); i++)
	{
		m_tree[i]->Display();
	}
}
