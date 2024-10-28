#include "Freljordian.h"

Freljordian::Freljordian() : Race(), m_passiveHealthBonus(0)
{
}

Freljordian::Freljordian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _passiveHealthBonus) :
	Race(_name, _lifeBonus, _defenseBonus, _speedBonus), m_passiveHealthBonus(_passiveHealthBonus)
{
}

Freljordian::~Freljordian()
{
}
