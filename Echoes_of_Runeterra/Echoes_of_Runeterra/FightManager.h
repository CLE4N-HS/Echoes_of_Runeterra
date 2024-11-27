#pragma once
#include "Tools.h"
#include "Fight.h"

class FightManager
{
public:
	FightManager() = default;
	~FightManager();

	static void Update();
	static void Display();

	static void SetupFight(Fight* _fight);
	static void ChangeFightState(FightState* _state);

	static inline void SetInInFight(bool _isInFight) { m_isInFight = _isInFight; }
	static inline bool IsInFight() { return m_isInFight; }

private:
	static Fight* m_fight;
	static bool m_isInFight;

};
