#include "KeyboardManager.h"

KeyboardManager::KeyState KeyboardManager::m_keyState[];

KeyboardManager keyboardManager;

KeyboardManager::KeyboardManager()
{
	for (int key = 0; key < sf::Keyboard::KeyCount; key++)
	{
		m_keyState[key] = KeyboardManager::RELEASED;
	}
}

KeyboardManager::~KeyboardManager()
{
}

void KeyboardManager::Update()
{
	for (int key = 0; key < sf::Keyboard::KeyCount; key++)
	{
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key)) {
			m_keyState[key] = (m_keyState[key] < KeyboardManager::JUST_BEEN_PRESSED ? KeyboardManager::JUST_BEEN_PRESSED : KeyboardManager::PRESSED);
		}
		else {
			m_keyState[key] = (m_keyState[key] > KeyboardManager::JUST_BEEN_RELEASED ? KeyboardManager::JUST_BEEN_RELEASED: KeyboardManager::RELEASED);
		}
	}
}

bool KeyboardManager::HasJustPressed(const sf::Keyboard::Key& _key)
{
	return (m_keyState[(int)_key] == KeyboardManager::JUST_BEEN_PRESSED);
}

bool KeyboardManager::HasJustReleased(const sf::Keyboard::Key& _key)
{
	return (m_keyState[(int)_key] == KeyboardManager::JUST_BEEN_RELEASED);
}

bool KeyboardManager::OneTimePressed(const sf::Keyboard::Key& _key)
{
	if (m_keyState[static_cast<int>(_key)] == KeyboardManager::JUST_BEEN_PRESSED)
	{
		m_keyState[static_cast<int>(_key)] = KeyboardManager::ALREADY_PRESSED;
		return true;
	}

	return false;
}
