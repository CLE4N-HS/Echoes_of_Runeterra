#include "EnemyObject.h"
#include "Window.h"
#include "EnemyTextureManager.h"

EnemyObject::EnemyObject()/* : Object()*/
{
}

EnemyObject::EnemyObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName)/* : Object(_pos, _size, _textureName)*/
	: m_Pos(_pos), m_Size(_size), m_TextureName(_textureName)
{
}

EnemyObject::~EnemyObject()
{
}

void EnemyObject::Display()
{
	//this->SetupDraw();
	Window::rectangle.setTexture(EnemyTextureManager::GetTexture(m_TextureName), true);
	Window::rectangle.setPosition(m_Pos);
	Window::rectangle.setSize(m_Size);

	Window::Draw();
}

nlohmann::json EnemyObject::ToJson()
{
	nlohmann::json j;

	j["Position"] = { m_Pos.x, m_Pos.y };
	j["Size"] = { m_Size.x, m_Size.y };
	j["TextureName"] = m_TextureName;

	return j;
}

void EnemyObject::FromJson(const nlohmann::json& _j)
{
	m_Pos = sf::Vector2f(_j["Position"][0], _j["Position"][1]);
	m_Size = sf::Vector2f(_j["Size"][0], _j["Size"][1]);
	m_TextureName = _j["TextureName"];
}