#pragma once
#include "Window.h"

class InteractionText
{
public:
	InteractionText();
	~InteractionText();

	virtual void update(Window& _window) = 0;
	virtual void display(Window& _window) = 0;

protected:
	// TODO sureley getSize
	std::string m_text;

};
