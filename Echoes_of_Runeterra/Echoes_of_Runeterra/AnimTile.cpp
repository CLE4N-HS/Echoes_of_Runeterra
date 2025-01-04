#include "AnimTile.h"
#include "Window.h"

AnimTile::AnimTile() : Tile()
{
	m_AnimSpeed = 0.f;
}

AnimTile::~AnimTile()
{
}

nlohmann::json AnimTile::ToJson()
{
	nlohmann::json j;

	j["Rect"] = { m_Rect.left, m_Rect.top, m_Rect.width, m_Rect.height };
	j["Type"] = m_Type;
	j["TextureName"] = m_TextureName;
	
	j["MaxFrameX"] = m_MaxFrameX;
	j["AnimSpeed"] = m_AnimSpeed;

	return j;
}

void AnimTile::FromJson(const nlohmann::json& _j)
{
	m_Rect = sf::IntRect(_j["Rect"][0], _j["Rect"][1], _j["Rect"][2], _j["Rect"][3]);
	m_Type = _j["Type"];
	m_TextureName = _j["TextureName"];

	m_MaxFrameX = _j["MaxFrameX"];
	m_AnimSpeed = _j["AnimSpeed"];
}

void AnimTile::Anim(float _dt)
{
	m_AnimTime += _dt;

	if (m_AnimTime >= m_AnimSpeed)
	{
		m_AnimTime -= m_AnimSpeed;

		m_FrameX++;

		if (m_FrameX >= m_MaxFrameX)
		{
			m_FrameX = 0;
		}

		m_Rect.left = m_Rect.width * m_FrameX;
	}
}
