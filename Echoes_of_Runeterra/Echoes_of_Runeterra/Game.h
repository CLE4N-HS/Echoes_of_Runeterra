#pragma once
#include "State.h"
#include "ItemDatabase.h"
#include "CharacterManager.h"
#include "MapManager.h"
#include "DialogueManager.h"
#include "InteractionManager.h"
#include "CraftManager.h"

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
	MapManager m_mapManager;
	DialogueManager m_dialogueManager;
	InteractionManager m_interactionManager;
	CraftManager m_craftManager;

};
