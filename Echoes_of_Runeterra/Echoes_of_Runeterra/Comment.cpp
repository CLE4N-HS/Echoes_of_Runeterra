#include "Comment.h"
#include "Window.h"

Comment::Comment(std::string _comment, sf::Vector2f _pos) : InteractionText(_comment, _pos)
{
	m_isVisible = false;
}

void Comment::setup()
{
	InteractionText::setup();
	m_isVisible = false;
}

void Comment::Update()
{
}

void Comment::Display()
{
	if (m_isVisible)
	{
		Window::text.setStyle(sf::Text::Style::Italic);
		Window::text.setPosition(transform->getPos());
		Window::text.setString(m_text);
		Window::Draw(Window::text);

		Window::text.setStyle(sf::Text::Style::Regular);

		//_window.text.setStyle(sf::Text::Style::Italic);
		//_window.text.setPosition(m_pos);
		//_window.text.setString(m_text);

		//_window.draw(_window.text);
		//_window.text.setStyle(sf::Text::Style::Regular);
	}
}
