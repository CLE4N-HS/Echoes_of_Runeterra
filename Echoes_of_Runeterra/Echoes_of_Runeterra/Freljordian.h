#pragma once
#include "Race.h"

/// <summary>
/// This race uses its survival skills to fight
/// </summary>
class Freljordian : public Race
{
public:
	Freljordian();
	Freljordian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _passiveHealthBonus);
	~Freljordian();

private:
	int m_passiveHealthBonus;

};
