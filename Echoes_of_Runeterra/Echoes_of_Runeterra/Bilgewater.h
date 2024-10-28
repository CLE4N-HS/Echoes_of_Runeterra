#pragma once
#include "Race.h"

/// <summary>
/// This race uses its fast and imprevisible skills to fight
/// </summary>
class Bilegewater : public Race
{
public:
	Bilegewater();
	Bilegewater(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _criticalDamageBonus);
	~Bilegewater();

private:
	int m_criticalDamageBonus;

};
