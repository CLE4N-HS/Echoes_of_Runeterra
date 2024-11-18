#pragma once
#include "Character.h"
#include "SkillsTree.h"

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
	void UpdateMovement();
	void UpdateInventoryInteractions();

};
