#pragma once
#include "Tools.h"

class MouseManager
{
public:
	enum ButtonState{
		RELEASED,
		JUST_BEEN_RELEASED,
		JUST_BEEN_PRESSED,
		ALREADY_PRESSED,
		PRESSED,

		COUNT // <- keep last
	};

	MouseManager();
	~MouseManager();

	static void Update();
	static bool HasJustPressed(const sf::Mouse::Button& _button);
	static bool HasJustReleased(const sf::Mouse::Button& _button);

	static bool OneTimePressed(const sf::Mouse::Button& _button = sf::Mouse::Button::Left);

private:
	static ButtonState m_buttonState[static_cast<int>(sf::Mouse::ButtonCount)];

};
