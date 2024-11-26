#pragma once
#include "Npc.h"

class Fighter: public Npc
{
public:
	Fighter();
	~Fighter();

	virtual void Update() = 0;
	virtual void Display() = 0;

private:

};
