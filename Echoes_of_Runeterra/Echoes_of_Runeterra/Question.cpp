#include "Question.h"

Question::Question(std::string _question, sf::Vector2f _pos) : InteractionText(_question, _pos)
{
	m_isVisible = true;
}

void Question::setup()
{
	InteractionText::setup();
	m_isVisible = true;
}

void Question::Update()
{
}

void Question::Display()
{
	if (m_isVisible)
	{
		//_window.text.setStyle(sf::Text::Style::Underlined);
		//_window.text.setPosition(m_pos);
		//_window.text.setString(m_text);

		//_window.draw(_window.text);
		//_window.text.setStyle(sf::Text::Style::Regular);
	}
}
