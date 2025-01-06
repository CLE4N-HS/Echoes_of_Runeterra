#pragma once
#include "Window.h"
#include "Interaction.h"
#include "CharacterManager.h"
#include "DialogueManager.h"
#include "InteractionPlayerNpc.h"
#include "InteractionPlayerMap.h"

class InteractionManager
{
public:
	InteractionManager();
	~InteractionManager();

	void update(Window& _window, PawnManager* _characterManager, DialogueManager* _dialogueManager/*, MapManager* _mapManager*/);

private:
	InteractionPlayerNpc* m_interactionPlayerNpc;
	InteractionPlayerMap* m_interactionPlayerMap;
	//std::vector<Interaction*> m_interaction;
};
