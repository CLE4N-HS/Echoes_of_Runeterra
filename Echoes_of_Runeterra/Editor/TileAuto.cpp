#include "TileAuto.h"

TileAuto::TileAuto(Tile _tile, uint8_t _insideDirection, Tile::Type _outsideType) :
	Tile(_tile), m_Inside(_insideDirection), m_Outisde(_outsideType)
{
}
