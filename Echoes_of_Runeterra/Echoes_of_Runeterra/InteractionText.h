#pragma once
#include "Entity.h"

// TODO add a button to end the dialog
class InteractionText : public Entity
{
public:
	InteractionText();
	InteractionText(std::string _text, sf::Vector2f _pos);
	~InteractionText();

	int getChoosenAnswer();

	virtual void update(Window& _window) = 0;
	virtual void display(Window& _window) = 0;

protected:
	sf::FloatRect m_rect;
	std::string m_text;
	bool m_isVisible;
	bool m_isHovered;
	int m_choosenAnswer;

};
