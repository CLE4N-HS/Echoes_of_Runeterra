#pragma once
#include "Profession.h"

class Alchemist : public Profession
{
public:
	Alchemist();
	~Alchemist() = default;

	virtual void update(Window& _window) override;
	virtual void display(Window& _window) override;

private:

};
