#include "Map.h"

Map::Map() : m_item()
{
}

Map::~Map()
{
}

void Map::update(Window& _window)
{
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
