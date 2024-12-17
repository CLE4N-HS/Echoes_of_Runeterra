#pragma once
#include "Tools.h"

class Tile
{
public:
	enum Type : uint8_t
	{
		VOID = 0,
		GRASS,
		DIRT
	};
	//enum Direction : uint8_t
	//{
	//	VOID = 0 << 0,
	//	UP = 1 << 0,
	//	RIGHT = 1 << 1,
	//	DOWN = 1 << 2,
	//	LEFT = 1 << 3,
	//	/*
	//	UP_RIGHT = 1 << 4,
	//	DOWN_RIGHT = 1 << 5,
	//	DOWN_LEFT = 1 << 6,
	//	UP_LEFT = 1 << 7
	//	*/
	//};

	Tile() = default;
	Tile(sf::IntRect _rect, sf::Vector2f _pos, Tile::Type _type);
	~Tile() = default;

	inline uint8_t GetType() const { return static_cast<uint8_t>(m_Type); }

protected:
	sf::IntRect m_Rect = sf::IntRect();
	sf::Vector2f m_Pos = sf::Vector2f();
	Tile::Type m_Type = Tile::Type::VOID;
	//Tile::Direction m_Direction = Tile::Direction::VOID;

};
