#pragma once
#include "Character.h"

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
	std::list<Item*> m_item;

};
