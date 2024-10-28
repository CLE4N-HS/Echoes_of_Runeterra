#pragma once
#include "Race.h"

/// <summary>
/// This race uses its physical resistance and shields to fight
/// </summary>
class Demacian : public Race
{
public:
	Demacian();
	Demacian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _shieldBonus);
	~Demacian();

private:
	int m_shieldBonus;

};
