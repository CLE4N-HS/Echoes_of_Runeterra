#pragma once
#include "Tile.h"

class AutoTile : public Tile
{
public:
	enum Direction : uint8_t
	{
		VOID = 0,

		UP = 1 << 0,
		RIGHT = 1 << 1,
		DOWN = 1 << 2,
		LEFT = 1 << 3,

		UP_RIGHT = UP | RIGHT,
		DOWN_RIGHT = DOWN | RIGHT,
		DOWN_LEFT = DOWN | LEFT,
		UP_LEFT = UP | LEFT
	};

	AutoTile() = default;
	AutoTile(Tile _tile, uint8_t _insideDirection = 0, Tile::Type _outsideType = Tile::Type::VOID);
	~AutoTile() = default;

	inline uint8_t GetInside()  const { return m_Inside; }
	inline uint8_t GetOutside() const { return static_cast<uint8_t>(m_Outisde); }

private:
	uint8_t m_Inside = 0;
	Tile::Type m_Outisde = Tile::Type::VOID;

};
