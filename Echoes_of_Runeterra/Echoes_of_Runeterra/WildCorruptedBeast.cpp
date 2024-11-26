#include "WildCorruptedBeast.h"
#include "ItemDatabase.h"

WildCorruptedBeast::WildCorruptedBeast() : Enemy()
{
	// TODO claw
	this->SetWeapon(dynamic_cast<Weapon*>(ItemDatabase::CreateNewItem("sword")));
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
