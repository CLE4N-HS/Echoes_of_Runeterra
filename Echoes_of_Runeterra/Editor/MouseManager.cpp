#include "MouseManager.h"

MouseManager::ButtonState MouseManager::m_buttonState[];

MouseManager mouseManager;

MouseManager::MouseManager()
{
	for (int button = 0; button < sf::Mouse::ButtonCount; button++)
	{
		m_buttonState[button] = MouseManager::RELEASED;
	}
}

MouseManager::~MouseManager()
{
}

void MouseManager::Update()
{
	for (int button = 0; button < sf::Mouse::ButtonCount; button++)
	{
		if (sf::Mouse::isButtonPressed((sf::Mouse::Button)button)) {
			m_buttonState[button] = (m_buttonState[button] < MouseManager::JUST_BEEN_PRESSED ? MouseManager::JUST_BEEN_PRESSED : MouseManager::PRESSED);
		}
		else {
			m_buttonState[button] = (m_buttonState[button] > MouseManager::JUST_BEEN_RELEASED ? MouseManager::JUST_BEEN_RELEASED : MouseManager::RELEASED);
		}
	}
}

bool MouseManager::HasJustPressed(const sf::Mouse::Button& _button)
{
	return (m_buttonState[static_cast<int>(_button)] == MouseManager::JUST_BEEN_PRESSED);
}

bool MouseManager::HasJustReleased(const sf::Mouse::Button& _button)
{
	return (m_buttonState[static_cast<int>(_button)] == MouseManager::JUST_BEEN_RELEASED);
}

bool MouseManager::OneTimePressed(const sf::Mouse::Button& _button)
{
	if (m_buttonState[static_cast<int>(_button)] == MouseManager::JUST_BEEN_PRESSED)
	{
		m_buttonState[static_cast<int>(_button)] = MouseManager::ALREADY_PRESSED;
		return true;
	}

	return false;
}
