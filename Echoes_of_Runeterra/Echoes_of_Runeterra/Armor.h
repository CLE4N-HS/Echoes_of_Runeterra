#pragma once
#include "tools.h"

class Armor
{
public:
	Armor();
	~Armor();

	int getDefense() const;
	int getSpeed() const;
	int getDurability() const;

private:
	std::string m_name;
	int m_defense;
	int m_speed;
	int m_durability;

};
