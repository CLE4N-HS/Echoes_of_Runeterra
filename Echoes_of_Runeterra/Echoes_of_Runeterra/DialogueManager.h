#pragma once
#include "DialogueDataBase.h"
#include "Dialogue.h"

class DialogueManager
{
public:
	DialogueManager();
	~DialogueManager();

	void setupDialogue(std::string _name);

	void update(Window& _window);
	void display(Window& _window);

private:
	DialogueDataBase* m_dialogueDB;
	Dialogue m_dialogue;

};

