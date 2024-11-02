#pragma once
#include "tools.h"
#include "Item.h"

class Consumable : public Item
{
public:
	Consumable();
	Consumable(std::string _name, int _hp, int _defense, int _speed);
	~Consumable();

	virtual void update(Window& _window);
	virtual void display(Window& _window);
	virtual void displayStats(Window& _window);

private:
	std::string m_name;
	int m_hp;
	int m_defense;
	int m_speed;

};
