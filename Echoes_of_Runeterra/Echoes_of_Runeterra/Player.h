#pragma once
#include "Character.h"
#include "Inventory.h"

class Player : public Pawn
{
public:
	Player();
	Player(std::string _name);
	~Player();

	virtual void Update() override;
	virtual void Display() override;

	sf::FloatRect getRect();

protected:
	Inventory m_inventory;

	void UpdateMovement();
	void UpdateInventoryInteractions();

};
