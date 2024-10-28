#include "Race.h"

Race::Race() : Race("Default Race Name", 0, 0, 0)
{
}

Race::Race(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus) :
	m_name(_name), m_lifeBonus(_lifeBonus), m_defenseBonus(_defenseBonus), m_speedBonus(_speedBonus)
{
}

Race::~Race()
{
}
