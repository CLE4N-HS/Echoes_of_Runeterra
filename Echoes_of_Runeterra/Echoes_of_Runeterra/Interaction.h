#pragma once
#include "Window.h"

class Interaction
{
public:
	Interaction();
	~Interaction();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};
