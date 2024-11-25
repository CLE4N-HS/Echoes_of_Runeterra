#pragma once
#include "tools.h"
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(std::string _name, int _damage, int _criticalDamage, int _speed);
	Weapon(const Weapon& _weapon);
	~Weapon();

	virtual void Update() override;
	virtual void Display() override;

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
