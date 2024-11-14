#pragma once
#include "tools.h"
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(std::string _name, int _damage, int _criticalDamage, int _speed);
	~Weapon();

	virtual void update(Window& _window);
	virtual void display(Window& _window);
	virtual void displayStats(Window& _window);

	int getDamage() const;
	int getSpeed() const;

	inline void SETSPEEDTESTTODO(int _a) { m_speed += _a; }


private:
	bool isAttackCritical() const;

	std::string m_name;
	int m_damage;
	int m_critcalDamage;
	int m_speed;

};
