#pragma once
#include "Window.h"
#include "InteractionText.h"

class DialogueDataBase
{
public:
	DialogueDataBase();
	~DialogueDataBase();

	void createText(std::map<std::string, InteractionText*>& _text, std::string _name);

private:
	std::map<std::string, InteractionText*> m_interactionTextDB;

};
