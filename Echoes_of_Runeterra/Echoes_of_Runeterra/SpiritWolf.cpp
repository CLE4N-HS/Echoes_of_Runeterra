#include "SpiritWolf.h"
#include "ItemDatabase.h"
#include "ComponentName.h"

SpiritWolf::SpiritWolf() : Enemy()
{
	this->SetWeapon(dynamic_cast<Weapon*>(ItemDatabase::CreateNewItem("sword")));
	this->AddComponent<ComponentName>("SpiritWolf");
	this->m_fightStats = FightStats(1, 1, 2);
}

SpiritWolf::SpiritWolf(const SpiritWolf& _spiritWolf) : SpiritWolf()
{
}

SpiritWolf::~SpiritWolf()
{
}

void SpiritWolf::Update()
{
}

void SpiritWolf::Display()
{
}
