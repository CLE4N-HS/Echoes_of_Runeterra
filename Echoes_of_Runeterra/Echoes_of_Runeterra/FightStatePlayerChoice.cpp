#include "FightStatePlayerChoice.h"

FightStatePlayerChoice::FightStatePlayerChoice()
{
	m_button.reserve(4);
	const sf::Vector2f buttonSize(100.f, 50.f);
	m_button.push_back(new Button("Attack", Entity(Transform(sf::Vector2f(300.f, 700.f), buttonSize))));
}

FightStatePlayerChoice::~FightStatePlayerChoice()
{
}

void FightStatePlayerChoice::Update()
{
}
