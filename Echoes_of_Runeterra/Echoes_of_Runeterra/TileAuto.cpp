#include "TileAuto.h"

TileAuto::TileAuto(Tile _tile, uint8_t _insideDirection, uint8_t _outsideDirection) :
	Tile(_tile)
{
	m_Inside  = static_cast<TileAuto::Direction>(_insideDirection);
	m_Outisde = static_cast<TileAuto::Direction>(_outsideDirection);
}
