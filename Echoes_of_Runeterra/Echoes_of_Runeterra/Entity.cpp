#include "Entity.h"

Entity::Entity() : Entity(sf::Vector2f())
{
}

Entity::Entity(sf::Vector2f _pos) : m_pos(_pos)
{
}

Entity::~Entity()
{
}

sf::Vector2f Entity::getPos()
{
    return m_pos;
}

void Entity::setPos(sf::Vector2f _pos)
{
    m_pos = _pos;
}
