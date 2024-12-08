#pragma once
#include "Item.h"

struct MapItem
{
	MapItem(GameItem* _gameItem);
	~MapItem();

	GameItem* gameItem;
};

