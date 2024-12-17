#pragma once
#include "State.h"
#include "TileAutoDatabase.h"
#include "Map.h"

class Editor : public State
{
public:
	Editor();
	~Editor();

	virtual void Update() override;
	virtual void Display() override;

private:
	TileAutoDatabase m_tileAutoDatabase;
	Map m_Map;

};
