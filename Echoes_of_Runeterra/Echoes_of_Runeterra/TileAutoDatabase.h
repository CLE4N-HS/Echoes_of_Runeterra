#pragma once
#include "TileAuto.h"

class TileAutoDatabase
{
public:
	TileAutoDatabase();
	~TileAutoDatabase();

private:
	const uint16_t& GetId(const TileAuto* const& _tileAuto) const;
	void AddTileAuto(TileAuto* _tileAuto);

	std::map<uint16_t, TileAuto*> m_TileAuto{};

};
