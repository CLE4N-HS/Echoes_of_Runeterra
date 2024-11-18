#include "SkillsBranch.h"

SkillsBranch::SkillsBranch(const std::vector<SkillsLeaf*>& _leaves)
{
	m_branch.reserve(sizeof(SkillsLeaf*) * _leaves.size());
	for (size_t i = 0; i < _leaves.size(); i++)
	{
		m_branch.push_back(_leaves[i]);
		m_branch[i]->SetOwner(this);
	}
}

SkillsBranch::~SkillsBranch()
{
}

void SkillsBranch::Update()
{
	for (size_t i = 0; i < m_branch.size(); i++)
	{
		m_branch[i]->Update();
	}
}

void SkillsBranch::Display()
{
	for (size_t i = 0; i < m_branch.size(); i++)
	{
		m_branch[i]->Display();
	}
}

void SkillsBranch::CorrectPositions(const sf::Vector2f& _pos)
{
	this->transform->setPos(_pos);

	for (size_t i = 0; i < m_branch.size(); i++)
	{
		sf::Vector2f tmpPos = this->transform->getPos() + sf::Vector2f(0.f, -100.f);
		tmpPos.y += -100.f * static_cast<float>(i);

		m_branch[i]->transform->setPos(tmpPos);
	}
}
