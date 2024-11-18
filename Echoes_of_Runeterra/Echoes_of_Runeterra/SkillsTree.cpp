#include "SkillsTree.h"
#include "ComponentName.h"
#include "Window.h"

SkillsTree::SkillsTree() : SkillsTree("", {})
{
}

SkillsTree::SkillsTree(SkillsTree* _skillTree) : SkillsTree(*_skillTree)
{
}

SkillsTree::SkillsTree(const std::string& _name, const std::vector<SkillsBranch*>& _branches) :
	Entity(Transform(sf::Vector2f(960.f, 800.f), sf::Vector2f(100.f, 100.f))),
	m_xp(0), m_levelXp(1)
{
	this->AddComponent<ComponentName>(_name);

	m_tree.reserve(sizeof(SkillsBranch*) * _branches.size());
	for (size_t i = 0; i < _branches.size(); i++)
	{
		m_tree.push_back(_branches[i]);
		m_tree[i]->SetOwner(this);
	}

	this->CorrectPositions();
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
	this->transform->CorrectWindowRectangle();

	Window::Draw(Window::rectangle);

	for (size_t i = 0; i < m_tree.size(); i++)
	{
		m_tree[i]->Display();
	}
}

void SkillsTree::CorrectPositions()
{
	for (size_t i = 0; i < m_tree.size(); i++)
	{
		sf::Vector2f tmpPos = this->transform->getPos() + sf::Vector2f(0.f, -100.f);
		float halfSizeX(0.f);
		if (m_tree.size() % 2 == 0)
		{
			halfSizeX = static_cast<float>(m_tree.size()) * 300.f;
			tmpPos.x += lerp(-halfSizeX, halfSizeX, 1.f - static_cast<float>(m_tree.size()) / static_cast<float>(i));
			tmpPos.x += (i <= m_tree.size() / 2 ? -1.f : 1.f) * halfSizeX / static_cast<float>(m_tree.size()) * 0.5f;
			//tmpPos.x += halfSizeX - static_cast<float>(m_tree.size()) * (i % 2 == 0 ? -1.f : 1.f) + 150.f;
		}
		else
		{
			halfSizeX = static_cast<float>(m_tree.size()) * 300.f;
			tmpPos.x += (i <= m_tree.size() / 2 ? -1.f : 1.f) * halfSizeX / static_cast<float>(m_tree.size()) * 0.5f;
			//tmpPos.x += 300.f * static_cast<float>(i) * (i % 2 == 0 ? -1.f : 1.f);
		}

		m_tree[i]->CorrectPositions(tmpPos);
	}
}
