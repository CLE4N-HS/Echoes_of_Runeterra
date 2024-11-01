#pragma once
#include "State.h"
#include "ItemDatabase.h"
#include "Character.h"
#include "Map.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();
	virtual void update(Window& _window, State*& _state);
	virtual void display(Window& _window);

private:
	ItemDataBase* m_itemDB;
	Map m_map;
	Character m_character1;
	Character m_character2;

};
