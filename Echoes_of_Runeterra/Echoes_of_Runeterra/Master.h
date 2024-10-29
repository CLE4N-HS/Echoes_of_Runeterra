#pragma once
#include "Window.h"
#include "State.h"

// Masterclass
class Master
{
public:
	Master();
	~Master();

	void loop();

private:
	Window m_window;
	State m_state;

};
