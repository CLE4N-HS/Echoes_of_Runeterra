#pragma once
#include "FightState.h"

class FightStateInventory : public FightState
{
public:
	FightStateInventory();
	~FightStateInventory();

	virtual void Update() override;
	virtual void Display() override;

private:

};
