#pragma once
#include "Enemy.h"

class WildCorruptedBeast : public Enemy
{
public:
	WildCorruptedBeast();
	~WildCorruptedBeast();

	virtual void Update() override;
	virtual void Display() override;

private:

};

