#pragma once
#include "Layer.h"

class Map
{
public:
	Map();
	~Map();

	void Display();

	inline std::vector<Layer*>& GetMap() { return m_Map; }

private:
	std::vector<Layer*> m_Map;

};

