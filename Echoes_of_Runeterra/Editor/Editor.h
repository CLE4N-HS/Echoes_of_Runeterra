#pragma once
#include "State.h"
#include "AutoTileDatabase.h"
#include "Map.h"
#include "MapEdit.h"

class Editor : public State
{
public:
	Editor();
	~Editor();

	virtual void Update() override;
	void UpdateImGui();
	virtual void Display() override;


private:
	AutoTileDatabase m_AutoTileDatabase;
	Map m_Map;
	MapEdit m_MapEdit;

	std::string_view m_CurrentTextureName = "";
	sf::IntRect m_CurrentRect = sf::IntRect();

};
