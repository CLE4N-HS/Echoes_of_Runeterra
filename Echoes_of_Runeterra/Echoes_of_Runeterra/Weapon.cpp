#include "Weapon.h"

Weapon::Weapon() : Weapon("Default Weapon Name", 0, 0, 0)
{
}

Weapon::Weapon(std::string _name, int _damage, int _criticalDamage, int _speed) :
	m_name(_name), m_damage(_damage), m_critcalDamage(_criticalDamage), m_speed(_speed)
{
}

Weapon::~Weapon()
{
}

int Weapon::getDamage() const
{
	if (isAttackCritical())
		return (m_damage + m_critcalDamage);

	return m_damage;
}

int Weapon::getSpeed() const
{
	return m_speed;
}

bool Weapon::isAttackCritical() const
{
	return (rand() % 100 < 20);  // 20% chance to get critical damage
}
