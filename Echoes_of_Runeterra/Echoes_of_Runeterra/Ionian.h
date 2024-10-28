#pragma once
#include "Race.h"

/// <summary>
/// This race uses its agile sences to fight
/// </summary>
class Ionian : public Race
{
public:
	Ionian();
	Ionian(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _agility);
	~Ionian();

private:
	int m_agilityBonus;

};
