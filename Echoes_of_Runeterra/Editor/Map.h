#pragma once
#include "Tools.h"
#include "Tile.h"

class Map
{
public:
	Map();
	~Map();

	void Display();

	inline std::vector<std::vector<Tile*>>& getMap() { return m_Map; }

private:
	std::vector<std::vector<Tile*>> m_Map;

};

