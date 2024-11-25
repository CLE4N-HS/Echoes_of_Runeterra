#pragma once
#include "Tools.h"

class KeyboardManager
{
public:
	enum KeyState {
		RELEASED,
		JUST_BEEN_RELEASED,
		JUST_BEEN_PRESSED,
		ALREADY_PRESSED,
		PRESSED,

		COUNT // <- keep last
	};

	KeyboardManager();
	~KeyboardManager();

	static void Update();
	static bool HasJustPressed(const sf::Keyboard::Key& _key);
	static bool HasJustReleased(const sf::Keyboard::Key& _key);

	static bool OneTimePressed(const sf::Keyboard::Key& _key);

private:
	static KeyState m_keyState[static_cast<int>(sf::Keyboard::KeyCount)];

};

