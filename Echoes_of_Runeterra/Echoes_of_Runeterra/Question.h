#pragma once
#include "InteractionText.h"

class Question : public InteractionText
{
public:
	Question(std::string _question);
	~Question();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};
