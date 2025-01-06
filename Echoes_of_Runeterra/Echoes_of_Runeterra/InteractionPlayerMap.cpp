#include "InteractionPlayerMap.h"

InteractionPlayerMap::InteractionPlayerMap()
{
}

InteractionPlayerMap::~InteractionPlayerMap()
{
}

void InteractionPlayerMap::Update(PawnManager* _characterManager/*, MapManager* _mapManager*/)
{
	//sf::Vector2f playerPos = _characterManager->getCharacterPos("Player");
	//sf::Vector2f mousePos = _window.getMousePos();

	//Item* closestItem = _mapManager->getClosestItem(playerPos, 50000.f);

	//if (closestItem != nullptr)
	//{
	//	if (closestItem->getRect().contains(mousePos))
	//	{
	//		closestItem->setHover(true);

	//		if (_window.mouseManager.hasJustPressed(sf::Mouse::Left))
	//		{
	//			_characterManager->addCharacterItem("Player", closestItem);
	//			_mapManager->removeItem(closestItem);
	//		}
	//	}
	//}
}
