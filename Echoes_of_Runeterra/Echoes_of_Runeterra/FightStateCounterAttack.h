#pragma once
#include "FightState.h"

class FigthStateCounterAttack : public FightState
{
public:
	FigthStateCounterAttack();
	~FigthStateCounterAttack() = default;

	virtual void Update() override;
	virtual void Display() override;

private:
	float m_timer = 0.f;

};
