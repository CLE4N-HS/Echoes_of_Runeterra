#pragma once
#include "State.h"
#include "MapManager.h"
#include "DialogueManager.h"
#include "InteractionManager.h"
#include "CraftManager.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();

	virtual void Update();

	virtual void Display();

private:
	MapManager m_mapManager;
	DialogueManager m_dialogueManager;
	InteractionManager m_interactionManager;
	CraftManager m_craftManager;

};
