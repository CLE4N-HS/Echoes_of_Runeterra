#pragma once
#include "Character.h"

class Npc : public Character
{
public:
	Npc();
	Npc(std::string _name, std::string _dialogueKey);
	~Npc();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

	sf::FloatRect getRect();

protected:

};
