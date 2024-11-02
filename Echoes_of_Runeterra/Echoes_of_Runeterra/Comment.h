#pragma once
#include "InteractionText.h"

class Comment : public InteractionText
{
public:
	Comment(std::string _comment);
	~Comment();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};

