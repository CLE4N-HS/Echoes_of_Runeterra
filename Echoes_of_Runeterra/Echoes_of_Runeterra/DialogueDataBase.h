#pragma once
#include "Window.h"
#include "InteractionText.h"

class DialogueDataBase
{
public:
	DialogueDataBase();
	~DialogueDataBase();

	void createText(std::vector<InteractionText*>& _text, std::string _name);

private:
	std::unordered_map<std::string, InteractionText*> m_interactionTextDB;

};
