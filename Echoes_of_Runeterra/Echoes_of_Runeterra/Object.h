#pragma once
#include "Tools.h"
#include "JsonEntity.h"

class Object : public JsonEntity
{
public:
	Object() = default;
	Object(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName);
	~Object();

	inline std::string_view GetTextureName() const { return m_TextureName; }
	inline sf::Vector2f GetPos() const { return m_Pos; }
	inline sf::Vector2f GetSize() const { return m_Size; }

	virtual void Display() = 0;

	virtual nlohmann::json ToJson() = 0;
	virtual void FromJson(const nlohmann::json& _j) = 0;

protected:
	sf::Vector2f m_Pos;
	sf::Vector2f m_Size;
	std::string m_TextureName;

	void SetupDraw();

};
