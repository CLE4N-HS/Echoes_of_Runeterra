#pragma once
#include "MapItem.h"

class MapItemManager
{
public:
	MapItemManager();
	~MapItemManager();

	void Update();
	void Display();

private:
	std::list<MapItem*> m_mapItem = {};

};

