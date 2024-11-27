#include "FightManager.h"

Fight* FightManager::m_fight = nullptr;
bool FightManager::m_isInFight = false;

FightManager::~FightManager()
{
	delete m_fight;
}

void FightManager::Update()
{
	if (m_fight)
	{
		m_fight->Update();
	}
}

void FightManager::Display()
{
	if (m_fight)
	{
		m_fight->Display();
	}
}

void FightManager::SetupFight(Fight* _fight)
{
	if (_fight != nullptr)
	{
		m_fight = _fight;
		SetInInFight(true);
	}
}

void FightManager::ChangeFightState(FightState* _state)
{
	if (m_fight && _state)
		m_fight->ChangeState(_state);
}
