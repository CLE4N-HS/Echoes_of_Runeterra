#include "AutoTile.h"

//AutoTile::AutoTile(Tile _tile, uint8_t _insideDirection, Tile::Type _outsideType) :
//	Tile(_tile), m_Inside(_insideDirection), m_Outisde(_outsideType)
//{
//}

nlohmann::json AutoTile::ToJson()
{
	return nlohmann::json();
}

void AutoTile::FromJson(const nlohmann::json& _j)
{
}
