#include "Ionian.h"

Ionian::Ionian() : Race(), m_agilityBonus(0)
{
}

Ionian::Ionian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _agilityBonus) :
	Race(_name, _lifeBonus, _defenseBonus, _speedBonus), m_agilityBonus(_agilityBonus)
{
}

Ionian::~Ionian()
{
}

void Ionian::displayStats() const
{
	Race::displayStats();
	std::cout << "Ionian allows " << m_agilityBonus << " bonus agility" << std::endl;
}
