#include "Armor.h"

Armor::Armor() : Armor("Default Armor Name", 0, 0, 0)
{
}

Armor::Armor(std::string _name, int _defense, int _speed, int _durability) : Item(_name),
	m_name(_name), m_defense(_defense), m_speed(_speed), m_durability(_durability)
{
}

Armor::~Armor()
{
}

void Armor::display(Window& _window)
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
