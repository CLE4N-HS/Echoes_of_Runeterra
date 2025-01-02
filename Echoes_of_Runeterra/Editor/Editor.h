#pragma once
#include "State.h"
#include "AutoTileDatabase.h"
#include "Map.h"
#include "MapEdit.h"
#include <array>
#include "DayNightSystem.h"

class Editor : public State
{
public:
	Editor();
	~Editor();

	virtual void Update() override;
	bool UpdateImGui();
	virtual void Display() override;

	enum TextureId
	{
		NONE,
		TILE,
		OBJECT
	};

	enum Texture
	{
		NO,
		SIMPLE_TILE,
		TORCH
	};

private:
	AutoTileDatabase m_AutoTileDatabase;
	Map m_Map;
	MapEdit m_MapEdit;
	DayNightSystem m_DayNightSystem;

	std::string_view m_CurrentTextureName = "";
	sf::IntRect m_CurrentRect = sf::IntRect();
	std::array<bool, Map::Layer::COUNT> m_Layer{};
	Map::Layer m_CurrentLayer = Map::Layer::BACKGROUND;
	bool m_Grid = false;
	sf::Color m_GridColor = sf::Color(0, 0, 0, 255);
	float m_GridSize = 2.f;



	TextureId m_CurrentTextureId = NONE;
	Texture m_CurrentTexture = NO;
	Object* m_CurrentObject = nullptr;

};
