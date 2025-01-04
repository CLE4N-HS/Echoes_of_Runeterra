#pragma once
#include "State.h"
#include "Map.h"
#include "DayNightSystem.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();

	virtual void Update();

	virtual void Display();

private:
	Map m_Map;
	DayNightSystem m_DayNightSystem;

	void DisplayLayer(size_t _layer);

	//DialogueManager m_dialogueManager;
	//InteractionManager m_interactionManager;

};
