#include "Demacian.h"

Demacian::Demacian() : Race(), m_shieldBonus(0)
{
}

Demacian::Demacian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _shieldBonus) :
	Race(_name, _lifeBonus, _defenseBonus, _speedBonus), m_shieldBonus(_shieldBonus)
{
}

Demacian::~Demacian()
{
}
