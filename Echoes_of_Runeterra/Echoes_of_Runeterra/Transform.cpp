#include "Transform.h"
#include "Window.h"

Transform::Transform() :
	Transform(sf::Vector2f(), sf::Vector2f())
{
}

Transform::Transform(const sf::Vector2f& _pos, const sf::Vector2f& _size, const Origin& _origin, const sf::Vector2f _scale) :
	Transform(_pos, _size, (_origin == Origin::MIDDLE ? _size * 0.5f : sf::Vector2f(0.f, 0.f)), _scale)
{
}

Transform::Transform(const sf::Vector2f& _pos, const sf::Vector2f& _size, const sf::Vector2f& _origin, const sf::Vector2f _scale) :
	m_pos(_pos), m_size(_size), m_origin(_origin), m_scale(_scale)
{
}

void Transform::CorrectWindowRectangle() const
{
	Window::rectangle.setPosition(m_pos);
	Window::rectangle.setSize(m_size);
	Window::rectangle.setOrigin(m_origin);
	Window::rectangle.setScale(m_scale);
}

