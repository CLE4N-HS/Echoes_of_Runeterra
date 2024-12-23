#pragma once
#include "Map.h"

class MapEdit
{
public:
	MapEdit(std::vector<std::vector<Tile*>>* _map);
	~MapEdit();



private:
	std::vector<std::vector<Tile*>>* m_Map;

};

