#pragma once
#include "TileAuto.h"

class TileAutoDatabase
{
public:
	TileAutoDatabase();
	~TileAutoDatabase();

private:
	uint32_t GetId(const TileAuto* const& _tileAuto);
	void AddTileAuto(TileAuto* _tileAuto);

	std::map<uint32_t, TileAuto*> m_TileAuto;

};
