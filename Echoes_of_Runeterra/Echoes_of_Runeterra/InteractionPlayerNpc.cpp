#include "InteractionPlayerNpc.h"

InteractionPlayerNpc::InteractionPlayerNpc()
{
}

InteractionPlayerNpc::~InteractionPlayerNpc()
{
}

void InteractionPlayerNpc::update(Window& _window, PawnManager* _characterManager, DialogueManager* _dialogueManager)
{
	//sf::Vector2f playerPos = _characterManager->getCharacterPos("Player");
	//sf::Vector2f mousePos = _window.getMousePos();

	//Pawn* closestNpc = _characterManager->getClosestNpc(playerPos, 50000.f);

	//if (closestNpc != nullptr)
	//{
	//	if (closestNpc->getRect().contains(mousePos))
	//	{
	//		closestNpc->setHover(true);

	//		if (_window.mouseManager.hasJustPressed(sf::Mouse::Left))
	//		{
	//			_dialogueManager->setupDialogue(closestNpc->getDialogueKey());
	//		}
	//	}
	//}
}
