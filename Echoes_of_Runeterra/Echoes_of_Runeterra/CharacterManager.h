#pragma once
#include "Character.h"

class PawnManager
{
public:
	PawnManager();
	~PawnManager();

	/// <summary>
	/// Updates all Pawn
	/// </summary>
	static void Update();

	/// <summary>
	/// Displays all Pawn
	/// </summary>
	static void Display();

	static Pawn* GetPawn(const std::string& _name);

	static Pawn* getClosestNpc(sf::Vector2f _pos, float _minDistance);
	static sf::Vector2f getCharacterPos(std::string _name);
	static void addCharacterItem(std::string _name, Item* _item);

private:
	static std::vector<Pawn*> m_pawn;

};
