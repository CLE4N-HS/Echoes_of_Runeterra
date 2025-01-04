#pragma once
#include "AutoTile.h"

class AutoTileDatabase
{
public:
	AutoTileDatabase();
	~AutoTileDatabase();

private:
	uint32_t GetId(const AutoTile* const& _autoTile);
	void AddAutoTile(AutoTile* _autoTile);

	std::map<uint32_t, AutoTile*> m_AutoTile;

};
