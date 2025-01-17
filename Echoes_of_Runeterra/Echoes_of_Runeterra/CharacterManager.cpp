#include "CharacterManager.h"
#include "Player.h"
#include "Talker.h"
#include "ComponentName.h"

std::vector<Pawn*> PawnManager::m_pawn;

PawnManager::PawnManager()
{
	//m_pawn.reserve(3);
	size_t i(0);

	//m_pawn.push_back(new Talker("Npc1", "default"));
	//m_pawn[i]->transform->setPos(sf::Vector2f(100.f, 100.f));
	//
	//m_pawn.push_back(new Talker("Npc2", "default")); i++;
	//m_pawn[i]->transform->setPos(sf::Vector2f(500.f, 300.f));

	m_pawn.push_back(new Player("Player")); i++;
}

PawnManager::~PawnManager()
{
	for (size_t i = 0; i < m_pawn.size();)
	{
		delete m_pawn[i];
		m_pawn.erase(m_pawn.begin());
	}
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

Pawn* PawnManager::GetPawn(const std::string& _name)
{
	for (size_t i = 0; i < m_pawn.size(); i++)
	{
		if (m_pawn[i]->GetComponent<ComponentName>()->GetName() == _name)
		{
			return m_pawn[i];
		}
	}

	return nullptr;
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

void PawnManager::AddPawn(Pawn* _pawn)
{
	if (_pawn)
	{
		m_pawn.push_back(_pawn);
	}
}
