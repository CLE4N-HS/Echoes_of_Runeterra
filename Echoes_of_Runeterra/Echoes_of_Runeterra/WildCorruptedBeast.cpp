#include "WildCorruptedBeast.h"
#include "ItemDatabase.h"
#include "ComponentName.h"

WildCorruptedBeast::WildCorruptedBeast() : Enemy()
{
	this->SetWeapon(dynamic_cast<Weapon*>(ItemDatabase::CreateNewItem("sword")));
	this->AddComponent<ComponentName>("WildCorruptedBeast");
	this->m_fightStats = FightStats(11, 24, 5);
}

WildCorruptedBeast::WildCorruptedBeast(const WildCorruptedBeast& _wildCorruptedBeast) : WildCorruptedBeast()
{
}

WildCorruptedBeast::~WildCorruptedBeast()
{
}

void WildCorruptedBeast::Update()
{
}

void WildCorruptedBeast::Display()
{
}
