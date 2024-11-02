#pragma once
#include "Window.h"
#include "InteractionText.h"

class Dialogue
{
public:
	Dialogue();
	~Dialogue();

	void setup(std::map<std::string, InteractionText*>& _text);

	void update(Window& _window);
	void display(Window& _window);

private:
	std::map<std::string, InteractionText*> m_text;

};
