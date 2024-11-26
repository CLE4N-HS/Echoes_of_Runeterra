#pragma once
#include "Tools.h"
#include "MapItemManager.h"

class Map
{
public:
	Map();
	~Map();

	void Update();
	void Display();

	void AddItem(MapItem* _mapItem, Transform _transform);
	void removeItem(Item* _item);
	Item* getClosestItem(sf::Vector2f _pos, float _minDistance);

private:
	MapItemManager m_itemManager;

};
