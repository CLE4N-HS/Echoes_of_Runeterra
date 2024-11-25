#pragma once
#include "Dialogue.h"

class DialogueManager
{
public:
	DialogueManager();
	~DialogueManager();

	static void SetupDialogue(const std::string& _name);
	static bool IsInDialogue();

	static void Update();
	static void Display();

private:
	static Dialogue m_dialogue;

};

