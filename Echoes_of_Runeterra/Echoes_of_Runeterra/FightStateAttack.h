#pragma once
#include "FightState.h"

class FigthStateAttack : public FightState
{
public:
	FigthStateAttack();
	~FigthStateAttack() = default;

	virtual void Update() override;
	virtual void Display() override;

private:
	float m_timer = 0.f;

};
