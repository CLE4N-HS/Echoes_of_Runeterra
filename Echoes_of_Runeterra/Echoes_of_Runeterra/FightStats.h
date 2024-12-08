#pragma once

struct FightStats
{
	int hp = 1;
	int attack = 1;
	int defense = 0;
	inline FightStats(int _hp, int _attack, int _defense) : hp(_hp), attack(_attack), defense(_defense) {}
	inline FightStats() : FightStats(0, 0, 0) {}
};

