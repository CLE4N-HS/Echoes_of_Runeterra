#include "DialogueManager.h"

DialogueManager::DialogueManager() : m_dialogueDB(new DialogueDataBase), m_dialogue()
{
}

DialogueManager::~DialogueManager()
{
}

void DialogueManager::setupDialogue(std::string _name)
{
	std::vector<InteractionText*> tmpText;
	m_dialogueDB->createText(tmpText, _name);
	m_dialogue.setup(tmpText);
}

void DialogueManager::update(Window& _window)
{
	m_dialogue.update(_window);
}

void DialogueManager::display(Window& _window)
{
	m_dialogue.display(_window);
}
