#pragma once
#include "Skills.h"

class FightingSkills : public Skills
{
public:
	FightingSkills(const std::string& _name);
	~FightingSkills();

	virtual void Update() override;

private:

};
