#include "SkillsBranch.h"
#include "Window.h"

SkillsBranch::SkillsBranch(const std::vector<SkillsLeaf*>& _leaves) : Entity(Transform(sf::Vector2f(), sf::Vector2f(60.f, 60.f)))
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
	this->transform->CorrectWindowRectangle();
	Window::rectangle.setRotation(45.f);

	Window::Draw(Window::rectangle);
	Window::rectangle.setRotation(0.f);

	for (size_t i = 0; i < m_branch.size(); i++)
	{
		if (i < m_branch.size() - 1)
		{
			// lines
			const sf::Vector2f firstPos = m_branch[i]->transform->getPos();
			const sf::Vector2f secondPos = m_branch[i + 1]->transform->getPos();
			float distance = fabsf(vec2fGetMagnitude(firstPos - secondPos));
			float angle = getAngleBetweenVectors(sf::Vector2f(0.f, 0.f), sf::Vector2f(firstPos - secondPos));
			sf::Vector2f size(distance, 10.f);

			Window::rectangle.setPosition(lerpVector(firstPos, secondPos, 0.5f));
			Window::rectangle.setSize(size);
			Window::rectangle.setOrigin(size * 0.5f);
			Window::rectangle.setScale(sf::Vector2f(1.f, 1.f));
			Window::rectangle.setRotation(angle * RAD2DEG);

			Window::Draw(Window::rectangle);
		}
		Window::rectangle.setRotation(0.f);

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
