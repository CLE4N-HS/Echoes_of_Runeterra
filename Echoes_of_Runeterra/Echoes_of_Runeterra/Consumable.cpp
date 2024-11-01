#include "Consumable.h"
#include <fstream>

Consumable::Consumable() : Consumable("Default Consumable Name", 0, 0, 0)
{
}

Consumable::Consumable(std::string _name, int _hp, int _defense, int _speed) : Item(_name),
	m_name(_name), m_hp(_hp), m_defense(_defense), m_speed(_speed)
{
}

Consumable::~Consumable()
{
}

void Consumable::display(Window& _window)
{
}

void Consumable::displayStats(Window& _window, sf::Vector2f _pos)
{
}
