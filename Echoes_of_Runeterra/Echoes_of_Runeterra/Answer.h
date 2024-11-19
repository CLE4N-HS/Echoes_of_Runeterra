#pragma once
#include "InteractionText.h"

class Answer : public InteractionText
{
public:
	Answer(std::string _answer, sf::Vector2f _pos);

	virtual void setup();

	virtual void Update();
	virtual void Display();

private:

};
