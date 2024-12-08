#pragma once
#include "Enemy.h"

class SpiritWolf : public Enemy
{
public:
	SpiritWolf();
	SpiritWolf(const SpiritWolf& _spiritWolf);
	~SpiritWolf();

	virtual void Update() override;
	virtual void Display() override;

private:

};

