#pragma once
#include "Map.h"

class MapEdit
{
public:
	MapEdit(std::vector<std::vector<Tile*>>* _map);
	~MapEdit();

	sf::Vector2i TilePos(sf::Vector2f _pos);
	bool IsInMap(sf::Vector2i _pos);
	bool EditTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect);

private:
	std::vector<std::vector<Tile*>>* m_Map;

};

