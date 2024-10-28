#include "Shuriman.h"

Shuriman::Shuriman() : Race(), m_resurrectionHealthBonus(0)
{
}

Shuriman::Shuriman(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _resurrectionHealthBonus) :
	Race(_name, _lifeBonus, _defenseBonus, _speedBonus), m_resurrectionHealthBonus(_resurrectionHealthBonus)
{
}

Shuriman::~Shuriman()
{
}
