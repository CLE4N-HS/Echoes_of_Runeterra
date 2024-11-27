#pragma once
#include "Tools.h"

class FightState
{
public:
	FightState() = default;
	~FightState() = default;

	virtual void Update() = 0;
	virtual void Display() = 0;
	
private:

};
