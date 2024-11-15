#pragma once
#include "Character.h"

class Npc : public Pawn
{
public:
	Npc();
	Npc(std::string _name, std::string _dialogueKey);
	~Npc();

	virtual void Update() override;

	virtual void Display() override;

	sf::FloatRect getRect();

protected:

};
