#include "InteractionText.h"

InteractionText::InteractionText() : InteractionText("", sf::Vector2f())
{
}

InteractionText::InteractionText(std::string _text, sf::Vector2f _pos) : m_rect(), m_text(_text), Entity(_pos), m_isVisible(false), m_isHovered(), m_choosenAnswer(0)
{
}

InteractionText::~InteractionText()
{
}

int InteractionText::getChoosenAnswer()
{
	return m_choosenAnswer;
}
