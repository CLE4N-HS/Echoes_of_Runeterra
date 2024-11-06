#pragma once
#include "Profession.h"

class Blacksmith : public Profession
{
public:
	Blacksmith();
	~Blacksmith() = default;

	virtual void update(Window& _window) override;
	virtual void display(Window& _window) override;

private:

};
