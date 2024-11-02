#pragma once
#include "State.h"
#include "ItemDatabase.h"
#include "Character.h"
#include "Map.h"
#include "DialogueManager.h"

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
	std::map<std::string, Character*> m_character;
	DialogueManager m_dialogueManager;

};
