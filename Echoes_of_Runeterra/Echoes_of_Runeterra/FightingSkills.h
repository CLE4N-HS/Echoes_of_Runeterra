#pragma once
#include "Skills.h"

class FightingSkills : public Skills
{
public:
	FightingSkills();
	~FightingSkills();

	virtual void update(Window& _window) override;

private:

};
