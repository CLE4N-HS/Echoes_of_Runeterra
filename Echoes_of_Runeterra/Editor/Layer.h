#pragma once
#include "Tile.h"
#include <vector>

class Layer
{
public:
	Layer();
	~Layer();

	std::vector<std::vector<Tile*>> layer{};

};
