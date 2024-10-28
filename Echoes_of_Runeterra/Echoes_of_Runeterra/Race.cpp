#include "Race.h"

Race::Race() : Race(RACE_NULL)
{
}

Race::Race(RaceType _race)
{
	switch (_race)
	{
	case RACE_IONIAN:
		Race(RACE_IONIAN, "Ionian", 0, 0, 20); break;
	case RACE_DEMACIAN:
		Race(RACE_DEMACIAN, "Demacian", 15, 10, -5); break;
	case RACE_NOXIAN:
		Race(RACE_NOXIAN, "Noxian", 10, 0, 5); break;
	case RACE_FRELJORDIAN:
		Race(RACE_FRELJORDIAN, "Freljordian", 25, 0, 0); break;
	case RACE_BILGEWATER:
		Race(RACE_BILGEWATER, "Bilgewater", -2, -5, 25); break;
	case RACE_SHURIMAN:
		Race(RACE_SHURIMAN, "Shuriman", 4, 4, 4); break;
	default:
		Race(RACE_NULL, "Default Race Name", 0, 0, 0);
		break;
	}
}

Race::Race(RaceType _race, std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus) :
	m_race(_race), m_name(_name), m_lifeBonus(_lifeBonus), m_defenseBonus(_defenseBonus), m_speedBonus(_speedBonus),
	m_agilityBonus(0), m_shieldBonus(0), m_damageBonus(0), m_passiveHealBonus(0), m_criticalDamageBonus(0), m_resurrectionHealthBonus(0)
{
	switch (_race)
	{
	case RACE_IONIAN:
		m_agilityBonus = 20; break;
	case RACE_DEMACIAN:
		m_shieldBonus = 20; break;
	case RACE_NOXIAN:
		m_damageBonus = 15; break;
	case RACE_FRELJORDIAN:
		m_passiveHealBonus = 10; break;
	case RACE_BILGEWATER:
		m_criticalDamageBonus = 30; break;
	case RACE_SHURIMAN:
		m_resurrectionHealthBonus = 20; break;
	default:
		break;
	}
}

Race::~Race()
{
}

void Race::displayStats() const
{
	std::cout << "Name : " << m_name << std::endl;
	std::cout << "Life Bonus : " << m_lifeBonus << std::endl;
	std::cout << "Defense Bonus : " << m_defenseBonus << std::endl;
	std::cout << "Speed Bonus : " << m_speedBonus << std::endl;

	std::cout << "Race stats bonus :" << std::endl;
	switch (m_race)
	{
	case RACE_IONIAN:
		std::cout << "Agility Bonus : " << m_agilityBonus << std::endl; break;
	case RACE_DEMACIAN:
		std::cout << "Shield Bonus : " << m_shieldBonus << std::endl; break;
	case RACE_NOXIAN:
		std::cout << "Damage Bonus : " << m_damageBonus << std::endl; break;
	case RACE_FRELJORDIAN:
		std::cout << "Passive Heal Bonus : " << m_passiveHealBonus << std::endl; break;
	case RACE_BILGEWATER:
		std::cout << "Critical Damage Bonus : " << m_criticalDamageBonus << std::endl; break;
	case RACE_SHURIMAN:
		std::cout << "Resurrection Health Bonus : " << m_resurrectionHealthBonus << std::endl; break;
	default:
		break;
	}
}
