#pragma once
#include "InteractionText.h"

class EndButton : public InteractionText
{
public:
	EndButton(std::string _button, sf::Vector2f _pos);

	virtual void setup();

	virtual void Update();
	virtual void Display();

private:

};
