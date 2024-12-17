#pragma once
#include "State.h"
#include "CharacterManager.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();

	virtual void Update();

	virtual void Display();

private:
	PawnManager m_pawnManager;
	//DialogueManager m_dialogueManager;
	//InteractionManager m_interactionManager;

};
