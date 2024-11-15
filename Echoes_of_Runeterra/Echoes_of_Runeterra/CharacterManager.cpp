#include "CharacterManager.h"
#include "Player.h"
#include "Npc.h"

PawnManager::PawnManager() : m_character()
{
	m_character.insert({ "Player", new Player("Player")});
	m_character.insert({ "Npc", new Npc("Npc", "npcHello")});
	m_character.insert({ "Npc2", new Npc("Npc", "murloc")});
}

PawnManager::~PawnManager()
{
	m_character.clear();
}

void PawnManager::Update()
{
	for (std::map<std::string, Pawn*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	{
		it->second->setHover(false);
		it->second->Update();
	}
}

void PawnManager::Display()
{
	for (std::map<std::string, Pawn*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	{
		it->second->Display();
	}
}

Pawn* PawnManager::getClosestNpc(sf::Vector2f _pos, float _minDistance)
{
	//float closestDistance(_minDistance);
	//Pawn* closestNpc(nullptr);
	//for (std::map<std::string, Pawn*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	//{
	//	if (it->first != "Player")
	//	{
	//		float magnitude = vec2fGetSqrMagnitude(_pos - it->second->getPos());
	//		if (magnitude < _minDistance)
	//		{
	//			closestDistance = magnitude;
	//			closestNpc = it->second;
	//		}
	//	}
	//}

	//return closestNpc;
	return nullptr;
}

sf::Vector2f PawnManager::getCharacterPos(std::string _name)
{
	return sf::Vector2f();
	//return m_character[_name]->getPos();
}

void PawnManager::addCharacterItem(std::string _name, Item* _item)
{
	m_character[_name]->addItem(_item);
}
