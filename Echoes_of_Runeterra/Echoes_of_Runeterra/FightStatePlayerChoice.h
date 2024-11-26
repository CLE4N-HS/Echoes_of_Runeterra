#pragma once
#include "FightState.h"
#include "Button.h"

class FightStatePlayerChoice : public FightState
{
public:
	FightStatePlayerChoice();
	~FightStatePlayerChoice();

	virtual void Update() override;

private:
	std::vector<Button*> m_button;

};

