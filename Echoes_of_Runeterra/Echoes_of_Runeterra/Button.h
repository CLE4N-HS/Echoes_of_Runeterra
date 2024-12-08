#pragma once
#include "Entity.h"

struct Button : public Entity
{
	Button(const std::string& _string, Entity _entity);
	~Button() = default;

	void Display();

};

