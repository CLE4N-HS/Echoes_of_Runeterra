#pragma once
#include "Window.h"
#include "Map.h"

class MapManager
{
public:
	MapManager();
	~MapManager();

	void update(Window& _window);
	void display(Window& _window);

	void addItem(Item* _item);
	void removeItem(Item* _item);
	Item* getClosestItem(sf::Vector2f _pos, float _minDistance);

private:
	std::map<std::string, Map*> m_map;
	std::string m_currentMap;

};
