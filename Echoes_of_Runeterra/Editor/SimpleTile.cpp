#include "SimpleTile.h"

SimpleTile::SimpleTile() : Tile()
{
}

SimpleTile::~SimpleTile()
{
}

nlohmann::json SimpleTile::ToJson()
{
	nlohmann::json j;

	j["Rect"] = { m_Rect.left, m_Rect.top, m_Rect.width, m_Rect.height };
	j["Type"] = m_Type;
	j["TextureName"] = m_TextureName;

	return j;
}

void SimpleTile::FromJson(const nlohmann::json& _j)
{
	m_Rect = sf::IntRect(_j["Rect"][0], _j["Rect"][1], _j["Rect"][2], _j["Rect"][3]);
	m_Type = _j["Type"];
	m_TextureName = _j["TextureName"];
}
