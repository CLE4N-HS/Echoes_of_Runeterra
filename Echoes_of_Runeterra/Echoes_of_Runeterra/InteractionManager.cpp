#include "InteractionManager.h"

InteractionManager::InteractionManager() : m_interactionPlayerNpc(new InteractionPlayerNpc())
{
}

InteractionManager::~InteractionManager()
{
}

void InteractionManager::update(Window& _window, CharacterManager* _characterManager, DialogueManager* _dialogueManager)
{
	m_interactionPlayerNpc->update(_window, _characterManager, _dialogueManager);
}
