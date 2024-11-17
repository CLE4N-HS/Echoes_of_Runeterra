#pragma once
#include "Tools.h"
#include "Item.h"

class Armor : public Item
{
public:
	Armor();
	Armor(std::string _name, int _defense, int _speed, int _durability);
	~Armor();

	virtual void Update() override;
	virtual void Display() override;

	int getDefense() const;
	int getSpeed() const;
	int getDurability() const;

private:
	std::string m_name;
	int m_defense;
	int m_speed;
	int m_durability;

};
