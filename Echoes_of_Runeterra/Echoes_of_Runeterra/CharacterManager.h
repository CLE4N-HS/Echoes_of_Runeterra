#pragma once
#include "Character.h"

class PawnManager
{
public:
	PawnManager();
	~PawnManager();

	void Update();
	void Display();

	Pawn* getClosestNpc(sf::Vector2f _pos, float _minDistance);
	sf::Vector2f getCharacterPos(std::string _name);
	void addCharacterItem(std::string _name, Item* _item);

private:
	std::map<std::string, Pawn*> m_character;

};
