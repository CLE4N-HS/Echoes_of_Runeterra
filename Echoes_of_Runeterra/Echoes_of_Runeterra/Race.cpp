#include "Race.h"

Race::Race() : Race(RACE_NULL, "Default Race Name", 0, 0, 0)
{
}

Race::Race(RaceType _race, std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus) :
	m_race(_race), m_name(_name), m_lifeBonus(_lifeBonus), m_defenseBonus(_defenseBonus), m_speedBonus(_speedBonus),
	m_agilityBonus(0), m_shieldBonus(0), m_damageBonus(0), m_passiveHealBonus(0), m_criticalDamageBonus(0), m_resurrectionHealthBonus(0),
	m_natureSkill(false), m_justiceSkill(false), m_ambitiousSkill(false), m_handleColdSkill(false), m_unpredictableSkill(false), m_sunVisionSkill(false)
{
	switch (_race)
	{
	case RACE_IONIAN:
		m_agilityBonus = 20;
		m_natureSkill = true;
		break;
	case RACE_DEMACIAN:
		m_shieldBonus = 20;
		m_justiceSkill = true;
		break;
	case RACE_NOXIAN:
		m_damageBonus = 15;
		m_ambitiousSkill = true;
		break;
	case RACE_FRELJORDIAN:
		m_passiveHealBonus = 10;
		m_handleColdSkill = true;
		break;
	case RACE_BILGEWATER:
		m_criticalDamageBonus = 30;
		m_unpredictableSkill = true;
		break;
	case RACE_SHURIMAN:
		m_resurrectionHealthBonus = 20;
		m_sunVisionSkill = true;
		break;
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

	std::cout << "\nRace stats skills :" << std::endl;
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

	if (m_natureSkill)
		std::cout << "You are familar with nature" << std::endl;
	if (m_justiceSkill)
		std::cout << "You are familiar with justice" << std::endl;
	if (m_ambitiousSkill)
		std::cout << "You are familiar with ambition" << std::endl;
	if (m_handleColdSkill)
		std::cout << "You can handle cold easily" << std::endl;
	if (m_unpredictableSkill)
		std::cout << "You are unpredictable" << std::endl;
	if (m_sunVisionSkill)
		std::cout << "You are familiar with sun visions" << std::endl;
}

void Race::changeStats(std::string _name)
{
	m_name = _name;
}

void Race::changeStats(int _lifeBonus, int _defenseBonus, int _speedBonus)
{
	m_lifeBonus = _lifeBonus;
	m_defenseBonus = _defenseBonus;
	m_speedBonus = _speedBonus;
}
