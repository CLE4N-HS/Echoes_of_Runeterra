#pragma once
#include "Window.h"
#include "MouseManager.h"
#include "Character.h"

class State
{
public:
	State();
	~State();

	void update(Window& _window);
	void display(Window& _window);

private:
	MouseManager m_mouseManager;
	Character m_character;
	Character m_character2;

};
