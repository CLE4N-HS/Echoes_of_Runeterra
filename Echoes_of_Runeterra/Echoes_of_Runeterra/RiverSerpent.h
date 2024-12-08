#pragma once
#include "Enemy.h"

class RiverSerpent : public Enemy
{
public:
	RiverSerpent();
	RiverSerpent(const RiverSerpent& _riverSerpent);
	~RiverSerpent();

	virtual void Update() override;
	virtual void Display() override;

private:

};
