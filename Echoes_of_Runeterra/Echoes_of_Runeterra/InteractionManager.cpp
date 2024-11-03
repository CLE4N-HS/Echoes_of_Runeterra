#include "InteractionManager.h"

InteractionManager::InteractionManager() : m_interactionPlayerNpc(new InteractionPlayerNpc), m_interactionPlayerMap(new InteractionPlayerMap)
{
	//m_interaction.reserve(sizeof(Interaction) * 2);
	//m_interaction.push_back(new InteractionPlayerNpc());
	//m_interaction.push_back(new InteractionPlayerMap());
}

InteractionManager::~InteractionManager()
{
}

void InteractionManager::update(Window& _window, CharacterManager* _characterManager, DialogueManager* _dialogueManager, MapManager* _mapManager)
{
	m_interactionPlayerNpc->update(_window, _characterManager, _dialogueManager);
	m_interactionPlayerMap->update(_window, _characterManager, _mapManager);
	//for (int i = 0; i < m_interaction.size(); i++)
	//{
	//	m_interaction[i]->update(_window)
	//}
}
