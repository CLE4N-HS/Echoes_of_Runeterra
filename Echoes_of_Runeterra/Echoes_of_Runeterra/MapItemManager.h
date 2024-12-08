#pragma once
#include "MapItem.h"

class MapItemManager
{
public:
	MapItemManager();
	~MapItemManager();

	void Update();
	void Display();

	void AddItem(MapItem* _item, Transform _transform);

private:
	std::list<MapItem*> m_mapItem = {};

};

