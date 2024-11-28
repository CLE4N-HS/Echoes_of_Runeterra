#include "Companion.h"
#include "ComponentName.h"

Companion::Companion() : Fighter()
{
	this->AddComponent<ComponentName>("Companion");
}

void Companion::Update()
{
}

void Companion::Display()
{
}
