#include "Comment.h"

Comment::Comment(std::string _comment, sf::Vector2f _pos) : InteractionText(_comment, _pos)
{
	m_isVisible = false;
}

void Comment::setup()
{
	InteractionText::setup();
	m_isVisible = false;
}

void Comment::update(Window& _window)
{
}

void Comment::display(Window& _window)
{
	if (m_isVisible)
	{
		_window.text.setStyle(sf::Text::Style::Italic);
		_window.text.setPosition(m_pos);
		_window.text.setString(m_text);

		_window.draw(_window.text);
		_window.text.setStyle(sf::Text::Style::Regular);
	}
}
