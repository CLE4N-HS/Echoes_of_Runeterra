#include "FightStateAttack.h"
#include "MouseManager.h"
#include "FightManager.h"

FigthStateAttack::FigthStateAttack()
{
}

void FigthStateAttack::Update()
{
	m_timer += Tools::GetDeltaTime();

	if (m_timer > 1.f)
	{
		Player* player = FightManager::GetFight()->GetPlayer();
		std::vector<Enemy*> enemy = FightManager::GetFight()->GetEnemies();
	}
}

void FigthStateAttack::Display()
{
}
