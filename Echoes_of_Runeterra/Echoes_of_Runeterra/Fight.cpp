#include "Fight.h"
#include "FightStatePlayerChoice.h"

Fight::Fight(Player* _player, const std::vector<Enemy*>& _enemy) : m_player(_player), m_enemy(_enemy)
{
	m_state = new FightStatePlayerChoice();
}

Fight::~Fight()
{
	delete m_state;
}

void Fight::Update()
{
	m_state->Update();
}

void Fight::Display()
{
	m_state->Display();
}

void Fight::ChangeState(FightState* _state)
{
	delete m_state;
	m_state = _state;
}
