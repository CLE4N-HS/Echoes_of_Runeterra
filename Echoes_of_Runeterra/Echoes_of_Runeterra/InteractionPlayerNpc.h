#pragma once
#include "Interaction.h"
#include "Window.h"
#include "CharacterManager.h"
#include "DialogueManager.h"

class InteractionPlayerNpc : public Interaction
{
public:
	InteractionPlayerNpc();
	~InteractionPlayerNpc();

	void update(Window& _window, PawnManager* _characterManager, DialogueManager* _dialogueManager);

private:

};
