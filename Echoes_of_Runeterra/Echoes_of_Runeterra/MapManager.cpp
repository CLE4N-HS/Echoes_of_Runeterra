#include "MapManager.h"
#include "ItemDatabase.h"

std::map<std::string, Map*> MapManager::m_map;
std::string MapManager::m_currentMap = "outside";

MapManager::MapManager()
{
	m_currentMap = "outside";
	m_map.insert({ m_currentMap, new Map() });
	Map* tmpCurrentMap = m_map["outside"];
	//tmpCurrentMap->AddItem(new Map::MapItem(new GameItem(ItemDatabase::CreateNewItem("chicken"), 5)), Transform(sf::Vector2f(100.f, 400.f), sf::Vector2f(50.f, 50.f), Transform::Origin::TOP_LEFT));
	//tmpCurrentMap->AddItem(new Map::MapItem(new GameItem(ItemDatabase::CreateNewItem("rice"), 100)), Transform(sf::Vector2f(300.f, 500.f), sf::Vector2f(10.f, 10.f), Transform::Origin::TOP_LEFT));
	//tmpCurrentMap->AddItem(new Map::MapItem(new GameItem(ItemDatabase::CreateNewItem("wood"), 70)), Transform(sf::Vector2f(700.f, 700.f), sf::Vector2f(50.f, 50.f), Transform::Origin::TOP_LEFT));
	//tmpCurrentMap->AddItem(new Map::MapItem(new GameItem(ItemDatabase::CreateNewItem("metalArmor"), 1)), Transform(sf::Vector2f(800.f, 700.f), sf::Vector2f(50.f, 50.f), Transform::Origin::TOP_LEFT));
}

MapManager::~MapManager()
{
}

void MapManager::Update()
{
	for (std::map<std::string, Map*>::iterator it = m_map.begin(); it != m_map.end(); it++)
	{
		it->second->Update();
	}
}

void MapManager::Display()
{
	for (std::map<std::string, Map*>::iterator it = m_map.begin(); it != m_map.end(); it++)
	{
		it->second->Display();
	}
}

void MapManager::addItem(Item* _item)
{
	//m_map[m_currentMap]->addItem(_item);
}

void MapManager::removeItem(Item* _item)
{
	m_map[m_currentMap]->removeItem(_item);
}

Item* MapManager::getClosestItem(sf::Vector2f _pos, float _minDistance)
{
	return m_map[m_currentMap]->getClosestItem(_pos, _minDistance);
}
