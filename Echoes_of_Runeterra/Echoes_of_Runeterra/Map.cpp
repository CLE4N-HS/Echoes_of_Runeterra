#include "Map.h"

Map::Map() : m_item()
{
}

Map::~Map()
{
}

void Map::update(Window& _window)
{
	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		(*it)->update(_window);
	}
}

void Map::display(Window& _window)
{
	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		(*it)->display(_window);
	}
}

void Map::addItem(Item* _item)
{
	_item->setState(Item::State::ON_MAP);
	m_item.push_back(_item);
}

void Map::removeItem(Item* _item)
{
	m_item.remove(_item);
}

Item* Map::getClosestItem(sf::Vector2f _pos, float _minDistance)
{
	float closestDistance(_minDistance);
	Item* closestItem(nullptr);
	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		//float magnitude = vec2fGetSqrMagnitude(_pos - (*it)->getPos());
		//if (magnitude < _minDistance)
		//{
		//	closestDistance = magnitude;
		//	closestItem = (*it);
		//}
	}

	return closestItem;
}
