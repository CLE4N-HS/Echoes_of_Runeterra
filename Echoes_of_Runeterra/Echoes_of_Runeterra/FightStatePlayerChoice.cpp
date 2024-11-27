#include "FightStatePlayerChoice.h"
#include "Window.h"
#include "MouseManager.h"
#include "FightManager.h"
#include "FightStateInventory.h"

FightStatePlayerChoice::FightStatePlayerChoice()
{
	m_button.reserve(3);
	const sf::Vector2f buttonSize(300.f, 80.f);
	m_button.push_back(new Button("Skills",    Entity(Transform(sf::Vector2f(480.f , 800.f), buttonSize))));
	m_button.push_back(new Button("Attack",    Entity(Transform(sf::Vector2f(960.f , 800.f), buttonSize))));
	m_button.push_back(new Button("Inventory", Entity(Transform(sf::Vector2f(1440.f, 800.f), buttonSize))));
}

FightStatePlayerChoice::~FightStatePlayerChoice()
{
}

void FightStatePlayerChoice::Update()
{
	const sf::Vector2f mousePos = Window::GetMousePos();
	for (size_t i = 0; i < m_button.size(); i++)
	{
		if (m_button[i]->transform->GetRect().contains(mousePos) && MouseManager::OneTimePressed())
		{
			switch (i)
			{
			// Inventory
			case 2:
				FightManager::ChangeFightState(new FightStateInventory()); break;

			default:
				break;
			}
		}
	}
}

void FightStatePlayerChoice::Display()
{
	// this color was found (randomly) by Bryan (c)
	Window::rectangle.setFillColor(sf::Color(170, 70, 230));
	for (size_t i = 0; i < m_button.size(); i++)
	{
		m_button[i]->Display();
	}
}
