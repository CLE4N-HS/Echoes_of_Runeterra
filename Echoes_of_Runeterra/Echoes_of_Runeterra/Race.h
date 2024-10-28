#pragma once
#include "tools.h"

class Race
{
public:
	Race();
	Race(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus);
	~Race();

protected:
	std::string m_name;
	int m_lifeBonus;
	int m_defenseBonus;
	int m_speedBonus;

};
