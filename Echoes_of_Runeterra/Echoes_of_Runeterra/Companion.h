#pragma once
#include "Fighter.h"

class Companion : public Fighter
{
public:
	Companion();
	~Companion() = default;

	virtual void Update() override;
	virtual void Display() override;

private:

};
