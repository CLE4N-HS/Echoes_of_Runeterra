#include "Master.h"
#include "Tools.h"
#include "Window.h"

Master::Master() : m_stateManager(), m_newState(nullptr)
{
}

Master::~Master()
{
}

void Master::loop()
{
	while (!Window::IsDone())
	{
		if (m_newState)
		{
			m_stateManager.changeState(m_newState);
			m_newState = nullptr;
		}

		Tools::Update();
		Window::Update();

		if (Window::HasFocus())
			StateManager::Update();

		StateManager::Display();
		Window::Display();
	}
}
