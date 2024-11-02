#pragma once
#include "Window.h"

class Interaction
{
public:
	Interaction();
	~Interaction();

	virtual void update(Window& _window) = 0;
	virtual void display(Window& _window) = 0;

private:

};
