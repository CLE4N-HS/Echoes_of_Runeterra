#pragma once
#include "Tools.h"
#include "Tile.h"
#include "Object.h"
#include "NpcObject.h"
#include "EnemyObject.h"

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
	void Load(std::ifstream& _file);

	void DeinitMap();
	void DefaultMap();

	inline std::vector<std::vector<std::vector<Tile*>>>& getMap() { return m_Map; }
	inline std::vector<Object*>& getObject() { return m_Object; }
	inline std::vector<NpcObject*>& getNpcObject() { return m_NpcObject; }
	inline std::vector<EnemyObject*>& getEnemyObject() { return m_EnemyObject; }

private:
	std::vector<std::vector<std::vector<Tile*>>> m_Map{};
	std::vector<Object*> m_Object{};
	std::vector<NpcObject*> m_NpcObject{};
	std::vector<EnemyObject*> m_EnemyObject{};

};

