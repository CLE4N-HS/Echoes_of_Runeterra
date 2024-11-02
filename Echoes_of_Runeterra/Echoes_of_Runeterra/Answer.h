#pragma once
#include "InteractionText.h"

class Answer : public InteractionText
{
public:
	Answer(std::string _answer);
	~Answer();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};
