#pragma once
#include "InteractionText.h"

class Comment : public InteractionText
{
public:
	Comment(std::string _comment, sf::Vector2f _pos);

	virtual void setup();

	virtual void Update();
	virtual void Display();

private:

};

