#pragma once
#include "InteractionText.h"

class Question : public InteractionText
{
public:
	Question(std::string _question, sf::Vector2f _pos);

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};
