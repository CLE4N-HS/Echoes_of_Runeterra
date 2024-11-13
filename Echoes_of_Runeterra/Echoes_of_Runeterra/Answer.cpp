#include "Answer.h"

Answer::Answer(std::string _answer, sf::Vector2f _pos) : InteractionText(_answer, _pos)
{
	m_isVisible = true;
}

void Answer::setup()
{
	InteractionText::setup();
	m_isVisible = true;
}

void Answer::update(Window& _window)
{
	if (m_isVisible)
	{
		if (m_rect.contains(_window.getMousePos()))
		{
			m_isHovered = true;

			if (_window.mouseManager.hasJustPressed(sf::Mouse::Left))
			{
				m_hasChoosen = true;
			}
		}
		else
		{
			m_isHovered = false;
		}
	}
}

void Answer::display(Window& _window)
{
	if (m_isVisible)
	{
		//_window.text.setPosition(m_pos);
		//_window.text.setString(m_text);

		//_window.draw(_window.text);
		//m_rect = _window.text.getGlobalBounds();

		//if (m_isHovered)
		//{
		//	_window.rectangle.setPosition(m_rect.getPosition());
		//	_window.rectangle.setSize(m_rect.getSize());

		//	_window.draw(_window.rectangle);
		//}
	}
}
