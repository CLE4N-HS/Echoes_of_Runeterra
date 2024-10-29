#include "State.h"

State::State() : m_mouseManager(), m_character()
{
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
