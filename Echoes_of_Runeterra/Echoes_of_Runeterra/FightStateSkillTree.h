#pragma once
#include "FightState.h"

class FightStateSkillTree : public FightState
{
public:
	FightStateSkillTree();
	~FightStateSkillTree();

	virtual void Update() override;
	virtual void Display() override;

private:

};
