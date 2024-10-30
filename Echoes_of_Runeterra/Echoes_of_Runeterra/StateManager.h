#pragma once
#include "State.h"

class StateManager
{
public:
	StateManager();
	~StateManager();

	void update(Window& _window);
	void display(Window& _window);

private:
	State* m_state;

};
