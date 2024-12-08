#pragma once
#include "tools.h"
#include "Item.h"

class Consumable : public Item
{
public:
	Consumable();
	Consumable(std::string _name, int _hp, int _attack, int _defense);
	Consumable(const Consumable& _consumable);
	~Consumable();

	virtual void Update() override;
	virtual void Display() override;

	int getHpBuff() const;
	inline int GetAttackBuff() const { return m_attack; }
	int getDefenseBuff() const;

private:
	std::string m_name;
	int m_hp;
	int m_attack;
	int m_defense;

};
