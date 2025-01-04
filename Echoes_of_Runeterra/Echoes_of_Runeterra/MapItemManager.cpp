#include "MapItemManager.h"
#include "Window.h"
#include "MouseManager.h"
#include "ItemDatabase.h"
#include "Player.h"
#include "CharacterManager.h"
#include "ComponentName.h"

MapItemManager::MapItemManager()
{
}

MapItemManager::~MapItemManager()
{
	// TODO clear
}

void MapItemManager::Update()
{
	const sf::Vector2f mousePos = Window::GetMouseViewPos();

	for (std::list<MapItem*>::iterator it = m_mapItem.begin(); it != m_mapItem.end();)
	{
		if ((*it)->gameItem->item->transform->GetRect().contains(mousePos) && MouseManager::OneTimePressed())
		{
			if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
			{
				player->AddItem(GameItem(ItemDatabase::CreateNewItem((*it)->gameItem->item), (*it)->gameItem->quantity));

				delete (*it)->gameItem->item;
				it = m_mapItem.erase(it);
				continue;
			}
		}

		it++;
	}
}

void MapItemManager::Display()
{
	Window::text.setCharacterSize(20);
	Window::text.setFillColor(sf::Color(255, 255, 255));
	for (std::list<MapItem*>::iterator it = m_mapItem.begin(); it != m_mapItem.end(); it++)
	{
		// item
		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
		(*it)->gameItem->item->transform->CorrectWindowRectangle();
		Window::Draw();

		Window::text.setPosition((*it)->gameItem->item->transform->getPos() + sf::Vector2f(0.f, -50.f));
		Window::text.setString((*it)->gameItem->item->GetComponent<ComponentName>()->GetName());
		Tools::CenterTextOrigin(Window::text);
		Window::Draw(Window::text);

		Window::text.setPosition((*it)->gameItem->item->transform->getPos() + sf::Vector2f(0.f, 50.f));
		Window::text.setString(std::to_string((*it)->gameItem->quantity));
		Tools::CenterTextOrigin(Window::text);
		Window::Draw(Window::text);
	}
}

void MapItemManager::AddItem(MapItem* _item, Transform _transform)
{
	if (_item)
	{
		m_mapItem.push_back(_item);
		*m_mapItem.back()->gameItem->item->transform = _transform;
	}
}
