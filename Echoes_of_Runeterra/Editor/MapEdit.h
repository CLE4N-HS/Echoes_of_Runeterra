#pragma once
#include "Map.h"

class MapEdit
{
public:
	constexpr static int MIN_SIZE = 1;
	constexpr static int MAX_SIZE = 100;

	MapEdit(std::vector<std::vector<std::vector<Tile*>>>* _map, std::vector<Object*>* _object);
	~MapEdit();

	sf::Vector2i TilePos(sf::Vector2f _pos);
	bool IsInMap(sf::Vector2i _pos);
	bool EditTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect, Tile::Type _type);
	bool EditAnimTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect, Tile::Type _type, int _frameX, float _animSpeed);
	bool EditObject(sf::Vector2f _pos, std::string_view _textureName, sf::Vector2f _size, int _texture);

	template<typename T>
	inline sf::Vector2<T> GetSize() const
	{
		return sf::Vector2<T>(sf::Vector2<size_t>((*m_Map)[m_Layer][0].size(), (*m_Map)[m_Layer].size()));
	}

	inline size_t GetNbLayer() const { return (*m_Map).size(); }

	void Resize(sf::Vector2<size_t> _size);

	inline Map::Layer GetLayer() const { return m_Layer; }
	inline void SetLayer(Map::Layer _layer) { m_Layer = _layer; }

private:
	std::vector<std::vector<std::vector<Tile*>>>* m_Map;
	Map::Layer m_Layer = Map::Layer::BACKGROUND;

	std::vector<Object*>* m_Object;

};

