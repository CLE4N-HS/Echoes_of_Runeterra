#pragma once
#include "Window.h"
#include "InteractionText.h"

class DialogueDataBase
{
public:
	DialogueDataBase();
	~DialogueDataBase();

private:
	std::unordered_map<std::string, InteractionText*> m_interactionTextDB;

};
