#pragma once
#include "State.h"
#include "Map.h"

class Editor : public State
{
public:
	Editor();
	~Editor();

	virtual void Update() override;
	virtual void Display() override;

private:
	Map m_Map;

};
