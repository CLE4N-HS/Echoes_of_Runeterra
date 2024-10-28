#pragma once
#include "tools.h"

class Race
{
public:
	typedef enum {
		RACE_NULL = -1,
		RACE_IONIAN = 0,  // This race uses its agile sences to fight
		RACE_DEMACIAN,    // This race uses its physical resistance and shields to fight
		RACE_NOXIAN,      // This race uses its brute strength to fight
		RACE_FRELJORDIAN, // This race uses its survival skills to fight
		RACE_BILGEWATER,  // This race uses its fast and imprevisible skills to fight
		RACE_SHURIMAN,    // This race uses its resurrection skills to fight

		RACE_COUNT // <- keep last
	}RaceType;

	Race();
	Race(RaceType _race, std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus);
	~Race();

	void displayStats() const;
	void changeStats(std::string _name);
	void changeStats(int _lifeBonus, int _defenseBonus, int _speedBonus);

private:
	// common
	RaceType m_race;
	std::string m_name;
	int m_lifeBonus;
	int m_defenseBonus;
	int m_speedBonus;
	//

	// fighting skills
	int m_agilityBonus;
	int m_shieldBonus;
	int m_damageBonus;
	int m_passiveHealBonus;
	int m_criticalDamageBonus;
	int m_resurrectionHealthBonus;
	//

	// world skills
	bool m_natureSkill;
	bool m_justiceSkill;
	bool m_ambitiousSkill;
	bool m_handleColdSkill;
	bool m_unpredictableSkill;
	bool m_sunVisionSkill;
	//

};
