#pragma once
#include "State.h"
#include "Character.h"
#include "ItemDatabase.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();
	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:
	Character m_character1;
	Character m_character2;
	ItemDataBase m_itemDataBase;

};
