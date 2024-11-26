#include "MapItem.h"

MapItem::MapItem(GameItem* _gameItem) : gameItem(_gameItem)
{
}

MapItem::~MapItem()
{
	// ?
	delete gameItem;
}
