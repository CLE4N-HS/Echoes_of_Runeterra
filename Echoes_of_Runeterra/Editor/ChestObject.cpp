#include "ChestObject.h"
#include "Window.h"

ChestObject::ChestObject() : Object()
{
}

ChestObject::ChestObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName) : Object(_pos, _size, _textureName)
{
}

ChestObject::~ChestObject()
{
}

void ChestObject::Display()
{
	this->SetupDraw();

	Window::Draw();
}

nlohmann::json ChestObject::ToJson()
{
	nlohmann::json j;

	j["Position"] = { m_Pos.x, m_Pos.y };
	j["Size"] = { m_Size.x, m_Size.y };
	j["TextureName"] = m_TextureName;

	return j;
}

void ChestObject::FromJson(const nlohmann::json& _j)
{
	m_Pos = sf::Vector2f(_j["Position"][0], _j["Position"][1]);
	m_Size = sf::Vector2f(_j["Size"][0], _j["Size"][1]);
	m_TextureName = _j["TextureName"];
}
