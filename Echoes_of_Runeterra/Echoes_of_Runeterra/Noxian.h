#pragma once
#include "Race.h"

/// <summary>
/// This race uses its brute strength to fight
/// </summary>
class Noxian : public Race
{
public:
	Noxian();
	Noxian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _damageBonus);
	~Noxian();

	virtual void displayStats() const;

private:
	int m_damageBonus;

};
