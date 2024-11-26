#include "WildCorruptedBeast.h"
#include "Weapon.h"

WildCorruptedBeast::WildCorruptedBeast() : Enemy()
{
	this->SetWeapon(new Weapon("Claw", 10, 10, 10));
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
