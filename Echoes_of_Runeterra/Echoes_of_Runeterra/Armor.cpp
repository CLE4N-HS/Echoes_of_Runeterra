#include "Armor.h"

Armor::Armor() : m_name("Default Armor Name"), m_defense(0), m_speed(0), m_durability(0)
{
}

Armor::~Armor()
{
}

int Armor::getDefense() const
{
	return m_defense;
}

int Armor::getSpeed() const
{
	return m_speed;
}

int Armor::getDurability() const
{
	return m_durability;
}
