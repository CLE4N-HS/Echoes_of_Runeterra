#include "FightStateAttack.h"
#include "MouseManager.h"
#include "FightManager.h"
#include "FightStateCounterAttack.h"

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

		int attackValue = player->GetFightStats().attack;
		if (Weapon* playerWeapon = player->GetWeapon())
			attackValue += playerWeapon->getDamage();

		int randomEnemy = rand() % enemy.size();

		int defenseValue = enemy[randomEnemy]->GetFightStats().defense;
		if (Armor* enemyArmor = enemy[randomEnemy]->GetArmor())
			defenseValue += enemyArmor->getDefense();

		enemy[randomEnemy]->GetFightStats().hp -= std::max(0, attackValue - defenseValue);

		FightManager::ChangeFightState(new FigthStateCounterAttack());
	}
}

void FigthStateAttack::Display()
{
}
