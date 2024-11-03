#include "StateManager.h"
#include "ressourcesManager.h"
#include "Game.h"

StateManager::StateManager()
{
	res_load(RES_ALL);
	m_state = new Game;
}

StateManager::~StateManager()
{
}

void StateManager::update(Window& _window, State*& _state)
{
	m_state->update(_window, _state);
}

void StateManager::display(Window& _window)
{
	m_state->display(_window);
}

void StateManager::changeState(State* _state)
{
	delete m_state;
	m_state = _state;
}
