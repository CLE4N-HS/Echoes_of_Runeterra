#include "Question.h"

Question::Question(std::string _question, sf::Vector2f _pos) : InteractionText(_question, _pos)
{
	m_isVisible = true;
}

void Question::update(Window& _window)
{
}

void Question::display(Window& _window)
{
	if (m_isVisible)
	{
		_window.text.setPosition(m_pos);
		_window.text.setString(m_text);

		_window.draw(_window.text);
	}
}
