#include "FightStateInventory.h"
#include "CharacterManager.h"
#include "Player.h"
#include "FightManager.h"
#include "FightStatePlayerChoice.h"

FightStateInventory::FightStateInventory()
{
	if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
	{
		player->GetInventory().setOpening(true);
	}
}

FightStateInventory::~FightStateInventory()
{
}

void FightStateInventory::Update()
{
	if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
	{
		player->GetInventory().Update();
		if (!player->GetInventory().isOpen())
		{
			FightManager::ChangeFightState(new FightStatePlayerChoice());
		}
	}
}

void FightStateInventory::Display()
{
	if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
	{
		player->GetInventory().Display();
	}
}
