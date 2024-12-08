#pragma once
#include "Character.h"

class Npc : public Pawn
{
public:
	Npc();
	Npc(std::string _name);
	~Npc();

	virtual void Update() = 0;

	virtual void Display() = 0;

protected:

};
