#pragma once
#include "Window.h"
#include "Map.h"

class MapManager
{
public:
	MapManager();
	~MapManager();

	static void Update();
	static void Display();

	void addItem(Item* _item);
	void removeItem(Item* _item);
	Item* getClosestItem(sf::Vector2f _pos, float _minDistance);

private:
	static std::map<std::string, Map*> m_map;
	static std::string m_currentMap;

};
