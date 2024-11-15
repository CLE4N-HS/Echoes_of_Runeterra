#include "StateManager.h"
#include "ressourcesManager.h"
#include "Game.h"

State* StateManager::m_state = new Game();

StateManager stateManager;

StateManager::StateManager()
{
	res_load(RES_ALL);
}

StateManager::~StateManager()
{
	delete m_state;
}

void StateManager::Update()
{
	m_state->Update();
}

void StateManager::Display()
{
	m_state->Display();
}

void StateManager::changeState(State* _state)
{
	delete m_state;
	m_state = _state;
}
