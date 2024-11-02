#pragma once
#include "Character.h"

class Npc : public Character
{
public:
	Npc();
	~Npc();

	virtual void update(Window& _window);
	virtual void display(Window& _window);

private:

};
