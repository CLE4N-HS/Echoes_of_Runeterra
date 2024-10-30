#pragma once
#include "Window.h"

class State
{
public:
	virtual ~State();
	virtual void update(Window& _window) = 0;
	virtual void display(Window& _window) = 0;

private:

};
