#include "CharacterManager.h"
#include "Player.h"
#include "Npc.h"

CharacterManager::CharacterManager() : m_character()
{
	m_character.insert({ "Player", new Player("Player")});
	m_character.insert({ "Npc", new Npc("Npc", "npcHello")});
	m_character.insert({ "Npc2", new Npc("Npc", "murloc")});
}

CharacterManager::~CharacterManager()
{
	m_character.clear();
}

void CharacterManager::update(Window& _window)
{
	for (std::map<std::string, Character*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	{
		it->second->setHover(false);
		it->second->update(_window);
	}
}

void CharacterManager::display(Window& _window)
{
	for (std::map<std::string, Character*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	{
		it->second->display(_window);
	}
}

Character* CharacterManager::getClosestNpc(sf::Vector2f _pos, float _minDistance)
{
	float closestDistance(_minDistance);
	Character* closestNpc(nullptr);
	for (std::map<std::string, Character*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	{
		if (it->first != "Player")
		{
			float magnitude = vec2fGetSqrMagnitude(_pos - it->second->getPos());
			if (magnitude < _minDistance)
			{
				closestDistance = magnitude;
				closestNpc = it->second;
			}
		}
	}

	return closestNpc;
}

sf::Vector2f CharacterManager::getCharacterPos(std::string _name)
{
	return m_character[_name]->getPos();
}

void CharacterManager::addCharacterItem(std::string _name, Item* _item)
{
	m_character[_name]->addItem(_item);
}
