#include "Master.h"
#include "Window.h"
#include "StateManager.h"

Master::Master()
{
}

Master::~Master()
{
}

void Master::loop()
{
	while (!Window::IsDone())
	{
		Tools::Update();
		Window::Update();

		if (Window::HasFocus())
			StateManager::Update();

		StateManager::Display();
		Window::Display();
	}
}
