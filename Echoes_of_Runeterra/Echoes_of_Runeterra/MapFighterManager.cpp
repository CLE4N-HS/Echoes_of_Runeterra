#include "MapFighterManager.h"

MapFighterManager::MapFighterManager()
{
}

MapFighterManager::~MapFighterManager()
{
	// TODO clear
}

void MapFighterManager::Update()
{
}

void MapFighterManager::Display()
{
}

void MapFighterManager::AddFighter(MapFighter* _fighter, Transform _transform)
{
	if (_fighter)
	{
		m_mapFighter.push_back(_fighter);
		*m_mapFighter.back()->m_fighter->transform = _transform;
	}
}
