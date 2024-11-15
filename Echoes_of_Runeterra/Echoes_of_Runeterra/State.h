#pragma once
#include "tools.h"

class State
{
public:
	virtual ~State();

	virtual void Update() = 0;

	virtual void Display() = 0;

private:

};
