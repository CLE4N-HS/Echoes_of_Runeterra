#include "Map.h"
#include "Window.h"
#include "MouseManager.h"
#include "CharacterManager.h"
#include "Player.h"
#include "ItemDatabase.h"
#include "ComponentName.h"
#include "EnemyDatabase.h"

Map::Map(Player* _player) : m_itemManager(), m_fighterManager(_player)
{
	m_itemManager.AddItem(new MapItem(new GameItem(ItemDatabase::CreateNewItem("wood"), 20)), Transform(sf::Vector2f(500.f, 100.f), sf::Vector2f(50.f, 50.f)));
	m_itemManager.AddItem(new MapItem(new GameItem(ItemDatabase::CreateNewItem("rice"), 55)), Transform(sf::Vector2f(800.f, 200.f), sf::Vector2f(20.f, 20.f)));
	m_itemManager.AddItem(new MapItem(new GameItem(ItemDatabase::CreateNewItem("chicken"), 2)), Transform(sf::Vector2f(1200.f, 400.f), sf::Vector2f(60.f, 60.f)));

	m_fighterManager.AddFighter(new MapFighter(EnemyDatabase::CreateNewEnemy("spiritWolf")), Transform(sf::Vector2f(200.f, 500.f), sf::Vector2f(30.f, 30.f)));
	m_fighterManager.AddFighter(new MapFighter(EnemyDatabase::CreateNewEnemy("wildCorruptedBeast")), Transform(sf::Vector2f(1700.f, 800.f), sf::Vector2f(50.f, 50.f)));
	m_fighterManager.AddFighter(new MapFighter(EnemyDatabase::CreateNewEnemy("riverSerpent")), Transform(sf::Vector2f(600.f, 700.f), sf::Vector2f(20.f, 20.f)));
}

Map::~Map()
{
}

void Map::Update()
{
	m_itemManager.Update();
	m_fighterManager.Update();
}

void Map::Display()
{
	m_itemManager.Display();
	m_fighterManager.Display();
}

void Map::AddItem(MapItem* _mapItem, Transform _transform)
{
	//m_item.push_back(_mapItem);
	//*_mapItem->gameItem->item->transform = _transform;
}

void Map::removeItem(Item* _item)
{
	//m_item.remove(_item);
}

Item* Map::getClosestItem(sf::Vector2f _pos, float _minDistance)
{
	//float closestDistance(_minDistance);
	//Item* closestItem(nullptr);
	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	//float magnitude = vec2fGetSqrMagnitude(_pos - (*it)->getPos());
	//	//if (magnitude < _minDistance)
	//	//{
	//	//	closestDistance = magnitude;
	//	//	closestItem = (*it);
	//	//}
	//}

	//return closestItem;
	return nullptr;
}
