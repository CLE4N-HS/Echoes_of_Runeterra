#pragma once
#include "InteractionText.h"

class Answer : public InteractionText
{
public:
	Answer(std::string _answer, sf::Vector2f _pos);

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};
