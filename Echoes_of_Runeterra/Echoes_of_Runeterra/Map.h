#pragma once
#include "Tools.h"
#include "Item.h"

class Map
{
public:
	struct MapItem {
		GameItem* gameItem;
		inline MapItem(GameItem* _gameItem) : gameItem(_gameItem) {}
	};

	Map();
	~Map();

	void Update();
	void Display();

	void AddItem(MapItem* _mapItem, Transform _transform);
	void removeItem(Item* _item);
	Item* getClosestItem(sf::Vector2f _pos, float _minDistance);

private:
	std::list<MapItem*> m_item;

};
