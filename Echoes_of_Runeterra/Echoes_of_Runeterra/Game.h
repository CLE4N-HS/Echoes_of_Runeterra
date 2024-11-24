#pragma once
#include "State.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();

	virtual void Update();

	virtual void Display();

private:
	//DialogueManager m_dialogueManager;
	//InteractionManager m_interactionManager;

};
