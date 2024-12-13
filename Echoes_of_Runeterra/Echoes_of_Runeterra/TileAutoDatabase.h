#pragma once
#include "TileAuto.h"

class TileAutoDatabase
{
public:
	TileAutoDatabase();
	~TileAutoDatabase();

private:
	static uint32_t GetId(const TileAuto* const& _tileAuto);
	static void AddTileAuto(TileAuto* _tileAuto);

	static std::map<uint32_t, TileAuto*> m_TileAuto;

};
