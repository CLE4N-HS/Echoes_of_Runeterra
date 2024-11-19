#pragma once
#include "InteractionText.h"

class Question : public InteractionText
{
public:
	Question(std::string _question, sf::Vector2f _pos);

	virtual void setup();

	virtual void Update();
	virtual void Display();

private:

};
