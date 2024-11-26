#pragma once
#include "Fighter.h"

class MapFighter
{
public:
	MapFighter(Fighter* _fighter);
	~MapFighter();

	void Update();
	void Display();

private:
	Fighter* m_fighter;

};
