#pragma once
#include "Map.h"

class MapEdit
{
public:
	constexpr static int MIN_SIZE = 1;
	constexpr static int MAX_SIZE = 100;

	MapEdit(std::vector<std::vector<std::vector<Tile*>>>* _map, std::vector<Object*>* _object, std::vector<NpcObject*>* _npc, std::vector<EnemyObject*>* _enemy);
	~MapEdit();

	sf::Vector2i TilePos(sf::Vector2f _pos);
	bool IsInMap(sf::Vector2i _pos);
	bool EditTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect, Tile::Type _type);
	bool EditAnimTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect, Tile::Type _type, int _frameX, float _animSpeed);
	bool EditObject(sf::Vector2f _pos, std::string_view _textureName, sf::Vector2f _size, int _texture);
	bool EditNpc(sf::Vector2f _pos, std::string_view _textureName, sf::Vector2f _size, int _texture);
	bool EditEnemy(sf::Vector2f _pos, std::string_view _textureName, sf::Vector2f _size, int _texture);

	bool EraseTile(sf::Vector2f _pos);
	bool EraseObject(sf::Vector2f _pos);

	template<typename T>
	inline sf::Vector2<T> GetSize() const
	{
		return sf::Vector2<T>(sf::Vector2<size_t>((*m_Map)[0][0].size(), (*m_Map)[0].size()));
	}

	inline size_t GetNbLayer() const { return (*m_Map).size(); }

	void Resize(sf::Vector2<size_t> _size);

	inline Map::Layer GetLayer() const { return m_Layer; }
	void SetLayer(Map::Layer _layer);

	bool PlaceCollision(sf::Vector2f _pos);

private:
	std::vector<std::vector<std::vector<Tile*>>>* m_Map;
	Map::Layer m_Layer = Map::Layer::BACKGROUND;

	std::vector<Object*>* m_Object;
	std::vector<NpcObject*>* m_NpcObject;
	std::vector<EnemyObject*>* m_EnemyObject;

};

