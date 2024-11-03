#pragma once
#include "Character.h"

class CharacterManager
{
public:
	CharacterManager();
	~CharacterManager();

	void update(Window& _window);
	void display(Window& _window);

	Character* getClosestNpc(sf::Vector2f _pos, float _minDistance);
	sf::Vector2f getCharacterPos(std::string _name);

private:
	std::map<std::string, Character*> m_character;

};
