#include "MapItemManager.h"
#include "Window.h"
#include "MouseManager.h"
#include "ItemDatabase.h"
#include "Player.h"
#include "CharacterManager.h"

MapItemManager::MapItemManager()
{
}

MapItemManager::~MapItemManager()
{
	// TODO clear
}

void MapItemManager::Update()
{
	const sf::Vector2f mousePos = Window::GetMousePos();

	for (std::list<MapItem*>::iterator it = m_mapItem.begin(); it != m_mapItem.end();)
	{
		if ((*it)->gameItem->item->transform->GetRect().contains(mousePos) && MouseManager::OneTimePressed())
		{
			if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
			{
				player->AddItem(GameItem(ItemDatabase::CreateNewItem((*it)->gameItem->item), (*it)->gameItem->quantity));

				delete (*it)->gameItem->item;
				it = m_item.erase(it);
				continue;
			}
		}

		it++;
	}
}

void MapItemManager::Display()
{
}
