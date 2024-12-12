#include "TileAutoDatabase.h"
#include "TileAuto.h"

TileAutoDatabase::TileAutoDatabase()
{
}

TileAutoDatabase::~TileAutoDatabase()
{
}

const uint16_t& TileAutoDatabase::GetId(const TileAuto* const& _tileAuto) const
{
	return uint16_t((_tileAuto->GetInside() << 0) + (_tileAuto->GetOutside() << 8));
}

void TileAutoDatabase::AddTileAuto(TileAuto* _tileAuto)
{
	m_TileAuto.insert({ GetId(_tileAuto), _tileAuto});
}
