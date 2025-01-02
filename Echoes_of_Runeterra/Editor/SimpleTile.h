#pragma once
#include "Tile.h"

class SimpleTile : public Tile
{
public:
	SimpleTile();
	~SimpleTile();

	virtual nlohmann::json ToJson() override;
	virtual void FromJson(const nlohmann::json& _j) override;

private:

};

