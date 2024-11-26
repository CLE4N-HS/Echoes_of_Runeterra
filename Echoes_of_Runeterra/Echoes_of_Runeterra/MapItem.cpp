#include "MapItem.h"

MapItem::MapItem(GameItem* _gameItem) : m_gameItem(_gameItem)
{
}

MapItem::~MapItem()
{
	// ?
	delete m_gameItem;
}
