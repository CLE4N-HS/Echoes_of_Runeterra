#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:
	std::list<Item*> m_item;

};
