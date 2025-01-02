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
}
