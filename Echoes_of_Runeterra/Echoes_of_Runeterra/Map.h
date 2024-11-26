#pragma once
#include "Tools.h"
#include "Item.h"
#include "Fighter.h"
#include "MapItem.h"

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

};
