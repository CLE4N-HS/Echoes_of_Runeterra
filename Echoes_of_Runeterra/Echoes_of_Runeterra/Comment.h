#pragma once
#include "InteractionText.h"

class Comment : public InteractionText
{
public:
	Comment(std::string _comment, sf::Vector2f _pos);

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};

