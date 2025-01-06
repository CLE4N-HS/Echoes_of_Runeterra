#pragma once
#include "Object.h"

class NpcObject : public JsonEntity
{
public:
	NpcObject();
	NpcObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName);
	~NpcObject();

	void Display();

	virtual nlohmann::json ToJson() override;
	virtual void FromJson(const nlohmann::json& _j) override;

private:
	sf::Vector2f m_Pos;
	sf::Vector2f m_Size;
	std::string m_TextureName;

};
