#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Profession.h"

class Player : public Pawn
{
public:
	Player();
	Player(std::string _name);
	~Player();

	virtual void Update() override;

	virtual void Display() override;

	sf::FloatRect getRect();

private:
	void UpdateMovement();
	void UpdateInventoryInteractions();

	Weapon* m_weapon;
	Armor* m_armor;

	Profession* m_profession;

};
