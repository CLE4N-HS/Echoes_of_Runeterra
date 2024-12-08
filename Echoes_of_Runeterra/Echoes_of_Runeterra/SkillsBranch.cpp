#include "SkillsBranch.h"
#include "Window.h"
#include "MouseManager.h"
#include "CharacterManager.h"
#include "Player.h"

SkillsBranch::SkillsBranch(const std::vector<SkillsLeaf*>& _leaves) : Entity(Transform(sf::Vector2f(), sf::Vector2f(60.f, 60.f)))
{
	m_branch.reserve(_leaves.size());
	for (size_t i = 0; i < _leaves.size(); i++)
	{
		m_branch.push_back(_leaves[i]);
		m_branch[i]->SetOwner(this);
	}
	
	if (m_branch.size() > 0)
	{
		m_branch[0]->SetState(SkillsLeaf::State::OBTAINABLE);
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

	const sf::Vector2f mousePos = Window::GetMousePos();

	for (size_t i = 0; i < m_branch.size(); i++)
	{
		if (m_branch[i]->GetState() == SkillsLeaf::State::OBTAINABLE)
		{
			if (m_branch[i]->transform->GetRect().contains(mousePos) && MouseManager::OneTimePressed())
			{
				m_branch[i]->SetState(SkillsLeaf::State::ACQUIRED);

				if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
				{
					player->AddSkill(m_branch[i]->GetSkill());
				}

				if (m_branch.size() > i + 1)
				{
					m_branch[i + 1]->SetState(SkillsLeaf::State::OBTAINABLE);
				}

				bool hasAllLeaf(true);
				for (size_t i = 0; i < m_branch.size(); i++)
				{
					if (m_branch[i]->GetState() != SkillsLeaf::ACQUIRED)
					{
						hasAllLeaf = false;
						break;
					}
				}

				if (hasAllLeaf)
				{
					m_isComplete = true;
				}
			}
		}
	}
}

void SkillsBranch::Display()
{
	this->transform->CorrectWindowRectangle();
	Window::rectangle.setRotation(45.f);

	Window::rectangle.setFillColor((m_isComplete ? sf::Color(0, 255, 0) : sf::Color(255, 255, 255)));

	Window::Draw(Window::rectangle);
	Window::rectangle.setRotation(0.f);

	for (size_t i = 0; i < m_branch.size(); i++)
	{
		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
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

			switch (m_branch[i + 1]->GetState())
			{
			case SkillsLeaf::LOCKED:
				Window::rectangle.setFillColor(sf::Color(255, 255, 255));
				break;
			case SkillsLeaf::OBTAINABLE:
				Window::rectangle.setFillColor(sf::Color(255, 0, 0));
				break;
			case SkillsLeaf::ACQUIRED:
				Window::rectangle.setFillColor(sf::Color(0, 255, 0));
				break;
			default:
				Window::rectangle.setFillColor(sf::Color(255, 255, 255));
				break;
			}

			Window::Draw(Window::rectangle);
		}
		Window::rectangle.setRotation(0.f);

		m_branch[i]->Display();
	}

	Window::rectangle.setFillColor(sf::Color(255, 255, 255));
}

void SkillsBranch::CorrectPositions(const sf::Vector2f& _pos)
{
	this->transform->setPos(_pos);

	for (size_t i = 0; i < m_branch.size(); i++)
	{
		sf::Vector2f tmpPos = this->transform->getPos() + sf::Vector2f(0.f, -100.f);
		float sizeY = 500.f;
		tmpPos.y -= lerp(0.f, sizeY, (m_branch.size() - 1 <= 0 ? 0.f : static_cast<float>(i) / static_cast<float>(m_branch.size() - 1)));

		m_branch[i]->transform->setPos(tmpPos);
	}
}
