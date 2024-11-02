#pragma once
#include "Window.h"
#include "InteractionText.h"

class Dialogue
{
public:
	Dialogue();
	~Dialogue();

	void setup(std::vector<InteractionText*>& _text);

	void update(Window& _window);
	void display(Window& _window);

private:
	std::vector<InteractionText*> m_text;

};
