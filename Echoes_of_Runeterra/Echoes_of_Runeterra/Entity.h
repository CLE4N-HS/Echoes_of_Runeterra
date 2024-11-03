#pragma once
#include "Window.h"

class Entity
{
public:
	Entity();
	Entity(sf::Vector2f _pos);
	~Entity();

	sf::Vector2f getPos();
	void setPos(sf::Vector2f _pos);

protected:
	sf::Vector2f m_pos;

};
