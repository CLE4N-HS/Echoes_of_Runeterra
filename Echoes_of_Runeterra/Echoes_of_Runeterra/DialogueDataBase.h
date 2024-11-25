#pragma once
#include "Window.h"
#include "InteractionText.h"

class DialogueDataBase
{
public:
	DialogueDataBase();
	~DialogueDataBase();

	static void createText(std::map<std::string, InteractionText*>& _text, std::string _name);

private:
	static std::map<std::string, InteractionText*> m_interactionTextDB;

};
