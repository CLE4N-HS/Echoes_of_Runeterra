#pragma once
#include "Race.h"

/// <summary>
/// This race uses its resurrection skills to fight
/// </summary>
class Shuriman : public Race
{
public:
	Shuriman();
	Shuriman(std::string _name, int _lifeBonus, int _defenseBonus, int _speedBonus, int _resurrectionHealthBonus);
	~Shuriman();

	virtual void displayStats() const;

private:
	int m_resurrectionHealthBonus;

};
