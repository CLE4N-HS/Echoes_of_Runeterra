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

	template<typename T>
	inline sf::Vector2<T> GetSize() const
	{
		return sf::Vector2<T>(sf::Vector2<size_t>((*m_Map)[0].size(), (*m_Map).size()));
	}

	void Resize(sf::Vector2<size_t> _size);

private:
	std::vector<std::vector<Tile*>>* m_Map;

};

