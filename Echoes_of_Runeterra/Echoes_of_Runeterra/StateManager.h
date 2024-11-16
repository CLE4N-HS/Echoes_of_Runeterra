#pragma once
#include "State.h"

class StateManager
{
public:
	StateManager();
	~StateManager();

	static void Update();

	static void Display();

	static void changeState(State* _state);

private:
	static State* m_state;

};
