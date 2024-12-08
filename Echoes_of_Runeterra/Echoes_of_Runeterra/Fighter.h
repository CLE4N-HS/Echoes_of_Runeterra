#pragma once
#include "Npc.h"
#include "FightStats.h"

class Fighter: public Npc
{
public:
	Fighter();
	~Fighter();

	virtual void Update() = 0;
	virtual void Display() = 0;

	inline FightStats& GetFightStats() { return m_fightStats; }

protected:
	FightStats m_fightStats = FightStats();

};
