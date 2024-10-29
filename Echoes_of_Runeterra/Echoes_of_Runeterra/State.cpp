#include "State.h"
#include "ressourcesManager.h"

State::State() : m_mouseManager(), m_character()
{
	//res_load(RES_ALL);
	m_character.setPos(sf::Vector2f(960.f, 800.f));
}

State::~State()
{
}

void State::update(Window& _window)
{
	m_mouseManager.update(_window);
	m_character.update(_window);
}

void State::display(Window& _window)
{
	m_character.display(_window);
}
