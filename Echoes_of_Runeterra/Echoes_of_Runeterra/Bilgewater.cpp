#include "Bilgewater.h"

Bilegewater::Bilegewater() : Race(), m_criticalDamageBonus(0)
{
}

Bilegewater::Bilegewater(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _criticalDamageBonus) :
	Race(_name, _lifeBonus, _defenseBonus, _speedBonus), m_criticalDamageBonus(m_criticalDamageBonus)
{
}

Bilegewater::~Bilegewater()
{
}
