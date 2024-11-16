#include "CharacterManager.h"
#include "Player.h"
#include "Npc.h"

std::vector<Pawn*> PawnManager::m_pawn;

PawnManager::PawnManager()
{
	m_pawn.reserve(sizeof(Pawn*) * 3);

	m_pawn.push_back(new Player("Player"));
	m_pawn.push_back(new Npc("Npc", "npcHello"));
	m_pawn.push_back(new Npc("Npc", "murloc"));
}

PawnManager::~PawnManager()
{
}

void PawnManager::Update()
{
	for (size_t i = 0; i < m_pawn.size(); i++)
	{
		// PREVIOUSLY : setHover(false)
		m_pawn[i]->Update();
	}
}

void PawnManager::Display()
{
	for (size_t i = 0; i < m_pawn.size(); i++)
	{
		m_pawn[i]->Display();
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
	//m_character[_name]->addItem(_item);
}
