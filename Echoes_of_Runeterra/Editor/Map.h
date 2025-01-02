#pragma once
#include "Tools.h"
#include "Tile.h"
#include "Object.h"

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

	void Save(std::ostream& _file);
	void Load(std::ifstream& _file);

	inline std::vector<std::vector<std::vector<Tile*>>>& getMap() { return m_Map; }
	inline std::vector<Object*>& getObject() { return m_Object; }

private:
	std::vector<std::vector<std::vector<Tile*>>> m_Map{};
	std::vector<Object*> m_Object{};

};

