#pragma once
#include "Tools.h"
#include "Tile.h"
#include "Object.h"
#include "Enemy.h"

class Map
{
public:
	enum Layer : size_t
	{
		BACKGROUND = 0,
		COLLISION,
		OBJECT,
		FOREGROUND,


		COUNT
	};

	Map();
	~Map();

	void Display();

	void Save(std::ostream& _file);
	void Load(std::ifstream& _file, std::vector<Enemy*>& _enemy);

	void DeinitMap();
	void DefaultMap();

	inline std::vector<std::vector<std::vector<Tile*>>>& getMap() { return m_Map; }
	inline std::vector<Object*>& getObject() { return m_Object; }

	void UpdateChest();

private:
	std::vector<std::vector<std::vector<Tile*>>> m_Map{};
	std::vector<Object*> m_Object{};

};

