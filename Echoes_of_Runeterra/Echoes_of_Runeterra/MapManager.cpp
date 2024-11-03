#include "MapManager.h"

MapManager::MapManager() : m_map()
{
	m_currentMap = "outside";
	m_map.insert({ m_currentMap, new Map() });
}

MapManager::~MapManager()
{
}

void MapManager::update(Window& _window)
{
	for (std::map<std::string, Map*>::iterator it = m_map.begin(); it != m_map.end(); it++)
	{
		it->second->update(_window);
	}
}

void MapManager::display(Window& _window)
{
	for (std::map<std::string, Map*>::iterator it = m_map.begin(); it != m_map.end(); it++)
	{
		it->second->display(_window);
	}
}

void MapManager::addItem(Item* _item)
{
	m_map[m_currentMap]->addItem(_item);
}

void MapManager::removeItem(Item* _item)
{
	m_map[m_currentMap]->removeItem(_item);
}

Item* MapManager::getClosestItem(sf::Vector2f _pos, float _minDistance)
{
	return m_map[m_currentMap]->getClosestItem(_pos, _minDistance);
}
