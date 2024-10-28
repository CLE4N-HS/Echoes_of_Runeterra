#include "Noxian.h"

Noxian::Noxian() : Race(), m_damageBonus(0)
{
}

Noxian::Noxian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _damageBonus) :
	Race(_name, _lifeBonus, _defenseBonus, _speedBonus), m_damageBonus(_damageBonus)
{
}

Noxian::~Noxian()
{
}
