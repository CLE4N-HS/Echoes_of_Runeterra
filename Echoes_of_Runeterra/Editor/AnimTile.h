#pragma once
#include "Tile.h"

class AnimTile : public Tile
{
public:
	AnimTile();
	~AnimTile();

	virtual nlohmann::json ToJson() override;
	virtual void FromJson(const nlohmann::json& _j) override;

	inline int& GetMaxFrameX() { return m_MaxFrameX; }
	inline float& GetAnimSpeed() { return m_AnimSpeed; }
	inline float& GetAnimTime() { return m_AnimTime; }
	inline int& GetFrameX() { return m_FrameX; }

	void Anim(float _dt);

private:
	int m_MaxFrameX = 0;
	float m_AnimSpeed = 0.0f;

	int m_FrameX = 0;
	float m_AnimTime = 0.0f;
};
