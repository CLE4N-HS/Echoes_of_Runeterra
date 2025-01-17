#pragma once
#include "Tools.h"
#include <string_view>
#include "JsonEntity.h"

class Tile : public JsonEntity
{
public:
	static constexpr int SIZE = 32;


	enum Type : uint8_t
	{
		NO_TYPE = 0,
		GRASS,
		DIRT,
		WATER,
		WALL
	};
	//enum Direction : uint8_t
	//{
	//	VOID = 0 << 0,
	//	UP = 1 << 0,
	//	RIGHT = 1 << 1,
	//	DOWN = 1 << 2,
	//	LEFT = 1 << 3,
	//	/*
	//	UP_RIGHT = 1 << 4,
	//	DOWN_RIGHT = 1 << 5,
	//	DOWN_LEFT = 1 << 6,
	//	UP_LEFT = 1 << 7
	//	*/
	//};

	Tile() = default;
	Tile(sf::IntRect _rect, sf::Vector2f _pos, Tile::Type _type);
	~Tile() = default;

	inline uint8_t getType() const { return static_cast<uint8_t>(m_Type); }
	inline Type& GetType() { return m_Type; }

	inline std::string_view GetTextureName() const { return m_TextureName; }
	inline void SetTextureName(std::string_view _name) { m_TextureName = _name; }

	//inline sf::Vector2f GetPos() const { return m_Pos; }
	//inline void SetPos(sf::Vector2f _pos) { m_Pos = _pos; }

	inline sf::IntRect GetRect() const { return m_Rect; }
	inline void SetRect(sf::IntRect _rect) { m_Rect = _rect; }

	virtual nlohmann::json ToJson() = 0;
	virtual void FromJson(const nlohmann::json& _j) = 0;

protected:
	std::string m_TextureName = "";
	sf::IntRect m_Rect = sf::IntRect();
	//sf::Vector2f m_Pos = sf::Vector2f();
	Tile::Type m_Type = Tile::Type::NO_TYPE;
	//Tile::Direction m_Direction = Tile::Direction::VOID;


};
