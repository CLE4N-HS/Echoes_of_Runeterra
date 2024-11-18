#include "SkillTreeManager.h"
#include "TreeDataBase.h"

std::vector<SkillsTree*> SkillTreeManager::m_tree = {};
int SkillTreeManager::m_currentTreeIndex = -1;

SkillTreeManager::SkillTreeManager()
{
	m_tree.push_back(TreeDataBase::CreateNewTree("tree1"));
	m_tree.push_back(TreeDataBase::CreateNewTree("tree2"));
	m_tree.push_back(TreeDataBase::CreateNewTree("tree3"));
	m_tree.push_back(TreeDataBase::CreateNewTree("tree4"));
	m_tree.push_back(TreeDataBase::CreateNewTree("tree5"));
	m_tree.push_back(TreeDataBase::CreateNewTree("tree6"));
	// debug
	m_currentTreeIndex = 0;
}

SkillTreeManager::~SkillTreeManager()
{
	for (size_t i = 0; i < m_tree.size();)
	{
		delete m_tree[i];
		m_tree.erase(m_tree.begin());
	}
}

void SkillTreeManager::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_currentTreeIndex = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_currentTreeIndex = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		m_currentTreeIndex = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		m_currentTreeIndex = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		m_currentTreeIndex = 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		m_currentTreeIndex = 5;
	}

	if (m_currentTreeIndex >= 0 && m_currentTreeIndex < m_tree.size())
	{
		m_tree[m_currentTreeIndex]->Update();
	}
}

void SkillTreeManager::Display()
{
	if (m_currentTreeIndex >= 0 && m_currentTreeIndex < m_tree.size())
	{
		m_tree[m_currentTreeIndex]->Display();
	}
}
