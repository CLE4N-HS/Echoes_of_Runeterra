#include "StateManager.h"
#include "ressourcesManager.h"
#include "Game.h"
#include "Editor.h"

State* StateManager::m_state = nullptr;

StateManager::StateManager()
{
	res_load(RES_ALL);
	m_state = new Editor();
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
