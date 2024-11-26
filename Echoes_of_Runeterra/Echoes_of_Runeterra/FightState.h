#pragma once
#include "Tools.h"

class FightState
{
public:
	FightState() = default;
	~FightState() = default;

	virtual void Update() = 0;
	
private:

};
