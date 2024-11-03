#include "InteractionText.h"

InteractionText::InteractionText() : InteractionText("", sf::Vector2f())
{
}

InteractionText::InteractionText(std::string _text, sf::Vector2f _pos) : m_rect(), m_text(_text), Entity(_pos), m_isVisible(false), m_isHovered(), m_hasChoosen(false)
{
}

InteractionText::~InteractionText()
{
}

void InteractionText::setup()
{
	m_isHovered = false;
	m_hasChoosen = false;
}

bool InteractionText::hasChoosen() const
{
	return m_hasChoosen;
}

void InteractionText::setVisibility(bool _isVisible)
{
	m_isVisible = _isVisible;
}

void InteractionText::resetChoice()
{
	m_hasChoosen = false;
}
