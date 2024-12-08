#pragma once
#include "Enemy.h"

class WildCorruptedBeast : public Enemy
{
public:
	WildCorruptedBeast();
	WildCorruptedBeast(const WildCorruptedBeast& _wildCorruptedBeast);
	~WildCorruptedBeast();

	virtual void Update() override;
	virtual void Display() override;

private:

};

