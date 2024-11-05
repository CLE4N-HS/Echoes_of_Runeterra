#pragma once
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"

class Player : public Character
{
public:
	Player();
	Player(std::string _name);
	~Player();

	virtual void update(Window& _window);
	virtual void display(Window& _window);
	sf::FloatRect getRect();

private:
	void updateMovement(Window& _window);
	void updateInventoryInteractions(Window& _window);

	Weapon* m_weapon;
	Armor* m_armor;

};
