#include "Object.h"
#include "Window.h"
#include "ObjectTextureManager.h"

Object::Object(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName) :
	m_Pos(_pos), m_Size(_size), m_TextureName(_textureName)
{
}

Object::~Object()
{
}

void Object::SetupDraw()
{
	Window::rectangle.setTexture(ObjectTextureManager::GetTexture(m_TextureName), true);
	Window::rectangle.setPosition(m_Pos);
	Window::rectangle.setSize(m_Size);
}
