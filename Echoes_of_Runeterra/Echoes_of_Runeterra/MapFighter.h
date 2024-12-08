#pragma once
#include "Fighter.h"

struct MapFighter
{
	MapFighter(Fighter* _fighter);
	~MapFighter();

	void Update();
	void Display();

	Fighter* m_fighter;
};
