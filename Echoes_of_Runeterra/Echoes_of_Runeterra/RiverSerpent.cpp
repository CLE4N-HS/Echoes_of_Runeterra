#include "RiverSerpent.h"
#include "ItemDatabase.h"
#include "ComponentName.h"

RiverSerpent::RiverSerpent() : Enemy()
{
	this->SetWeapon(dynamic_cast<Weapon*>(ItemDatabase::CreateNewItem("sword")));
	this->AddComponent<ComponentName>("RiverSerpent");
	this->m_fightStats = FightStats(10, 4, 1);
}

RiverSerpent::RiverSerpent(const RiverSerpent& _riverSerpent) : RiverSerpent()
{
}

RiverSerpent::~RiverSerpent()
{
}

void RiverSerpent::Update()
{
}

void RiverSerpent::Display()
{
}
