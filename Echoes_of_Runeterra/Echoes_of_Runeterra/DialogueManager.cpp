#include "DialogueManager.h"
#include "DialogueDataBase.h"

Dialogue DialogueManager::m_dialogue;

DialogueManager::DialogueManager()
{
}

DialogueManager::~DialogueManager()
{
}

void DialogueManager::SetupDialogue(const std::string& _name)
{
	std::map<std::string, InteractionText*> tmpText;
	DialogueDataBase::createText(tmpText, _name);
	m_dialogue.setup(tmpText);
}

bool DialogueManager::IsInDialogue()
{
	return m_dialogue.isInDialogue();
}

void DialogueManager::Update()
{
	m_dialogue.Update();
}

void DialogueManager::Display()
{
	m_dialogue.Display();
}
