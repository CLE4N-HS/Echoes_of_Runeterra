#pragma once
#include "Tools.h"
#include "Tile.h"

class Map
{
public:
	enum Layer : size_t
	{
		BACKGROUND = 0,
		COLLISION,
		FOREGROUND,

		COUNT
	};

	Map();
	~Map();

	void Display();

	inline std::vector<std::vector<std::vector<Tile*>>>& getMap() { return m_Map; }

private:
	std::vector<std::vector<std::vector<Tile*>>> m_Map;

};

