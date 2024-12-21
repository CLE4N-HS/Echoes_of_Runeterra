#pragma once
#include "Tools.h"
#include "Tile.h"

class Map
{
public:
	Map();
	~Map();

	void Display();

private:
	std::vector<std::vector<Tile*>> m_Map;

};

