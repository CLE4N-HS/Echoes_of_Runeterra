#include "FightStateCounterAttack.h"
#include "MouseManager.h"
#include "FightManager.h"
#include "FightStatePlayerChoice.h"

FigthStateCounterAttack::FigthStateCounterAttack()
{
}

void FigthStateCounterAttack::Update()
{
	m_timer += Tools::GetDeltaTime();

	if (m_timer > 1.f)
	{
		Player* player = FightManager::GetFight()->GetPlayer();
		std::vector<Enemy*> enemy = FightManager::GetFight()->GetEnemies();

		for (size_t i = 0; i < enemy.size(); i++)
		{
			int attackValue = enemy[i]->GetFightStats().attack;
			if (Weapon* enemyWeapon = enemy[i]->GetWeapon())
				attackValue += enemyWeapon->getDamage();

			int defenseValue = player->GetFightStats().defense;
			if (Armor* playerArmor = player->GetArmor())
				defenseValue += playerArmor->getDefense();

			player->GetFightStats().hp -= std::max(0, attackValue - defenseValue);
		}

		FightManager::ChangeFightState(new FightStatePlayerChoice());
	}
}
void FigthStateCounterAttack::Display()
{
}
