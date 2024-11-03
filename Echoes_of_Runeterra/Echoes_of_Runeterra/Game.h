#pragma once
#include "State.h"
#include "ItemDatabase.h"
#include "CharacterManager.h"
#include "Map.h"
#include "DialogueManager.h"
#include "InteractionManager.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();
	virtual void update(Window& _window, State*& _state);
	virtual void display(Window& _window);

private:
	ItemDataBase* m_itemDB;
	CharacterManager m_characterManager;
	Map m_map;
	DialogueManager m_dialogueManager;
	InteractionManager m_interactionManager;

};
