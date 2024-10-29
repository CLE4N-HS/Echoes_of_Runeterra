#include "State.h"
#include "ressourcesManager.h"

State::State() : m_mouseManager(), m_character("Player"), m_character2()
{
	res_load(RES_ALL);
	m_character.setPos(sf::Vector2f(960.f, 800.f));
	m_character2.setPos(sf::Vector2f(1200.f, 100.f));
}

State::~State()
{
}

void State::update(Window& _window)
{
	m_mouseManager.update(_window);
	m_character.update(_window);
	m_character2.update(_window);

	if (vec2fGetMagnitude(sf::Vector2f(m_character.getPos() - m_character2.getPos())) < 500.f)
	{
		m_character.attack(m_character2);
	}
}

void State::display(Window& _window)
{
	m_character.display(_window);
	m_character2.display(_window);
}
