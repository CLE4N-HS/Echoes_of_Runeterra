#pragma once
#include "Interaction.h"

class Dialogue : public Interaction
{
public:
	Dialogue();
	~Dialogue();

	void update(Window& _window);
	void display(Window& _window);

private:

};
