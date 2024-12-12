#pragma once
#include "Tile.h"

class TileAuto : public Tile
{
public:
	enum Direction : uint8_t
	{
		VOID = 0,

		UP    = 1 << 0,
		RIGHT = 1 << 1,
		DOWN  = 1 << 2,
		LEFT  = 1 << 3,
		
		UP_RIGHT   = UP   | RIGHT,
		DOWN_RIGHT = DOWN | RIGHT,
		DOWN_LEFT  = DOWN | LEFT ,
		UP_LEFT    = UP   | LEFT
	};

	TileAuto() = default;
	TileAuto(Tile _tile, uint8_t _insideDirection = 0, uint8_t _outsideDirection = 0);
	~TileAuto() = default;

	inline const uint8_t& GetInside()  const { return m_Inside; }
	inline const uint8_t& GetOutside() const { return m_Outisde; }

private:
	uint8_t m_Inside  = 0;
	uint8_t m_Outisde = 0;

};
