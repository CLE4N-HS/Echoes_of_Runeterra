#pragma once
#include "Profession.h"

class Alchemist : public Profession
{
public:
	Alchemist();
	~Alchemist() = default;

	virtual void Update() override;
	virtual void Display() override;

private:

};
