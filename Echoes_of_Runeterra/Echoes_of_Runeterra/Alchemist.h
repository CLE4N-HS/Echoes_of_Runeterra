#pragma once
#include "Profession.h"

class Alchemist : public Profession
{
public:
	Alchemist();
	~Alchemist() = default;

	virtual void Update() override;
	virtual void Display() override;

	virtual inline std::string ToString() const override { return "alchemist"; }

private:

};
