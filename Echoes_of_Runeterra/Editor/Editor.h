#pragma once
#include "State.h"
#include "AutoTileDatabase.h"
#include "Map.h"
#include "MapEdit.h"

class Editor : public State
{
public:
	Editor();
	~Editor();

	virtual void Update() override;
	virtual void Display() override;

private:
	AutoTileDatabase m_AutoTileDatabase;
	Map m_Map;
	MapEdit m_MapEdit;

};
