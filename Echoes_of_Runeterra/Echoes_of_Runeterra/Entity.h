#pragma once
#include "Window.h"

class Entity
{
public:
	Entity();
	Entity(sf::Vector2f _pos);
	~Entity();

protected:
	sf::Vector2f m_pos;

};
