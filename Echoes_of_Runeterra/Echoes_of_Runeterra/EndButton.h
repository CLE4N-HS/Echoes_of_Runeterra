#pragma once
#include "InteractionText.h"

class EndButton : public InteractionText
{
public:
	EndButton(std::string _button, sf::Vector2f _pos);

	virtual void setup();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};
