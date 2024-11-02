#pragma once
#include "DialogueDataBase.h"
#include "Dialogue.h"

class DialogueManager
{
public:
	DialogueManager();
	~DialogueManager();

	void createDialogue(std::string _name);

private:
	DialogueDataBase* m_dialogueDB;
	Dialogue m_dialogue;

};

