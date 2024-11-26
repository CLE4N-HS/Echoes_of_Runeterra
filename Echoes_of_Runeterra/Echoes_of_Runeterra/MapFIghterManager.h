#pragma once
#include "MapFighter.h"

class MapFighterManager
{
public:
	MapFighterManager();
	~MapFighterManager();

	void Update();
	void Display();

private:
	std::list<MapFighter*> m_mapFighter = {};

};

