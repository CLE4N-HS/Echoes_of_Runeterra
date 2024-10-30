#pragma once
#include "tools.h"

class Weapon
{
public:
	Weapon();
	Weapon(std::string _name, int _damage, int _criticalDamage, int _speed);
	~Weapon();

	int getDamage() const;
	int getSpeed() const;

private:
	bool isAttackCritical() const;

	std::string m_name;
	int m_damage;
	int m_critcalDamage;
	int m_speed;

};
