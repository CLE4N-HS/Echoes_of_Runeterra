#pragma once
#include "MapFighter.h"

class MapFighterManager
{
public:
	MapFighterManager(Player* _player);
	~MapFighterManager();

	void Update();
	void Display();

	void AddFighter(MapFighter* _fighter, Transform _transform);

private:
	std::list<MapFighter*> m_mapFighter = {};
	Player* m_player = nullptr;

};

