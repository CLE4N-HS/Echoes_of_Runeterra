#include "Map.h"
#include "Window.h"
#include "MouseManager.h"
#include "CharacterManager.h"
#include "Player.h"
#include "ItemDatabase.h"
#include "ComponentName.h"

Map::Map() : m_itemManager()
{
	m_itemManager.AddItem(new MapItem(new GameItem(ItemDatabase::CreateNewItem("wood"), 20)), Transform(sf::Vector2f(500.f, 100.f), sf::Vector2f(50.f, 50.f)));
	m_itemManager.AddItem(new MapItem(new GameItem(ItemDatabase::CreateNewItem("rice"), 55)), Transform(sf::Vector2f(800.f, 200.f), sf::Vector2f(20.f, 20.f)));
	m_itemManager.AddItem(new MapItem(new GameItem(ItemDatabase::CreateNewItem("chicken"), 2)), Transform(sf::Vector2f(1200.f, 400.f), sf::Vector2f(60.f, 60.f)));
}

Map::~Map()
{
}

void Map::Update()
{
	//const sf::Vector2f mousePos = Window::GetMousePos();

	//for (std::list<MapItem*>::iterator it = m_item.begin(); it != m_item.end();)
	//{
	//	if ((*it)->gameItem->item->transform->GetRect().contains(mousePos) && MouseManager::OneTimePressed())
	//	{
	//		if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
	//		{
	//			player->AddItem(GameItem(ItemDatabase::CreateNewItem((*it)->gameItem->item), (*it)->gameItem->quantity));

	//			delete (*it)->gameItem->item;
	//			it = m_item.erase(it);
	//			continue;
	//		}
	//	}

	//	it++;
	//}

	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	(*it)->Update();
	//}
}

void Map::Display()
{
	//Window::text.setCharacterSize(20);
	//Window::text.setFillColor(sf::Color(255, 255, 255));
	//for (std::list<MapItem*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	// item
	//	Window::rectangle.setFillColor(sf::Color(255, 255, 255));
	//	(*it)->gameItem->item->transform->CorrectWindowRectangle();
	//	Window::Draw();

	//	Window::text.setPosition((*it)->gameItem->item->transform->getPos() + (*it)->gameItem->item->transform->getSize() * 0.5f + sf::Vector2f(0.f, -50.f));
	//	Window::text.setString((*it)->gameItem->item->GetComponent<ComponentName>()->GetName());
	//	Tools::CenterTextOrigin(Window::text);
	//	Window::Draw(Window::text);

	//	Window::text.setPosition((*it)->gameItem->item->transform->getPos() + (*it)->gameItem->item->transform->getSize() * 0.5f + sf::Vector2f(0.f, 50.f));
	//	Window::text.setString(std::to_string((*it)->gameItem->quantity));
	//	Tools::CenterTextOrigin(Window::text);
	//	Window::Draw(Window::text);
	//}

	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	(*it)->Display();
	//}
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
