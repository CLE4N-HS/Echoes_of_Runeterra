#pragma once
#include "Component.h"

class Transform : public Component
{
public:
	enum Origin {
		TOP_LEFT = 0,
		MIDDLE
	};

	Transform();
	Transform(const sf::Vector2f& _pos, const sf::Vector2f& _size, const Origin& _origin = Origin::MIDDLE, const sf::Vector2f _scale = sf::Vector2f(1.f, 1.f));
	Transform(const sf::Vector2f& _pos, const sf::Vector2f& _size, const sf::Vector2f& _origin, const sf::Vector2f _scale = sf::Vector2f(1.f, 1.f));
	~Transform() = default;

	inline sf::Vector2f getPos() const { return m_pos; }
	inline void setPos(const sf::Vector2f& _pos) { m_pos = _pos; }
	inline void Move(const sf::Vector2f& _v) { m_pos += _v; }

	inline sf::Vector2f getSize() const { return m_size; }
	inline void setSize(const sf::Vector2f& _size) { m_size = _size; }

	inline sf::Vector2f getOrigin() const { return m_origin; }
	inline void setOrigin(const sf::Vector2f& _origin) { m_origin = _origin; }

	inline sf::Vector2f getScale() const { return m_scale; }
	inline void setScale(const sf::Vector2f& _scale) { m_scale = _scale; }

	inline sf::FloatRect GetRect() const { return sf::FloatRect(m_pos - Tools::Multiply(m_origin, m_scale), Tools::Multiply(m_size, m_scale)); }

	void CorrectWindowRectangle() const;

protected:
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
	sf::Vector2f m_origin;
	sf::Vector2f m_scale;

};
