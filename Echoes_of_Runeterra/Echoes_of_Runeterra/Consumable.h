#pragma once
#include "tools.h"
#include "Item.h"

class Consumable : public Item
{
public:
	Consumable();
	Consumable(std::string _name, int _hp, int _defense, int _speed);
	~Consumable();

	virtual void Update() override;
	virtual void Display() override;
	virtual void displayStats(Window& _window);

	int getHpBuff() const;
	int getDefenseBuff() const;
	int getSpeedBuff() const;

private:
	std::string m_name;
	int m_hp;
	int m_defense;
	int m_speed;

};
