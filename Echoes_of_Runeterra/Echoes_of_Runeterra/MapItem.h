#pragma once
#include "Item.h"

struct MapItem
{
	GameItem* gameItem;

	MapItem(GameItem* _gameItem);
	~MapItem();
};

