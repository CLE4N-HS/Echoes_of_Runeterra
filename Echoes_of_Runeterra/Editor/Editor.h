#pragma once
#include "State.h"
#include "AutoTileDatabase.h"
#include "Map.h"
#include "MapEdit.h"

#include <array>

class Editor : public State
{
public:
	Editor();
	~Editor();

	virtual void Update() override;
	bool UpdateImGui();
	virtual void Display() override;


private:
	AutoTileDatabase m_AutoTileDatabase;
	Map m_Map;
	MapEdit m_MapEdit;

	std::string_view m_CurrentTextureName = "";
	sf::IntRect m_CurrentRect = sf::IntRect();
	std::array<bool, Map::Layer::COUNT> m_Layer{};
	Map::Layer m_CurrentLayer = Map::Layer::FOREGROUND;

};
