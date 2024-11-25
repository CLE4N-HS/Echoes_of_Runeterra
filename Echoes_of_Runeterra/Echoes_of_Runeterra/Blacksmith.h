#pragma once
#include "Profession.h"

class Blacksmith : public Profession
{
public:
	Blacksmith();
	~Blacksmith() = default;

	virtual void Update() override;
	virtual void Display() override;

	virtual inline std::string ToString() const override { return "blacksmith"; }

private:

};
