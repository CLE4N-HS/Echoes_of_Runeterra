#pragma once
#include "Window.h"
#include "Interaction.h"
#include "InteractionPlayerNpc.h"
#include "CharacterManager.h"
#include "DialogueManager.h"

class InteractionManager
{
public:
	InteractionManager();
	~InteractionManager();

	void update(Window& _window, CharacterManager* _characterManager, DialogueManager* _dialogueManager);

private:
	InteractionPlayerNpc* m_interactionPlayerNpc;

};
