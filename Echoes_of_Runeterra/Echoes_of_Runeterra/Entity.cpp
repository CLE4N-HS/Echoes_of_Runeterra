#include "Entity.h"

Entity::Entity() : Entity(Transform())
{
}

Entity::Entity(const Transform& _transform, unsigned char _id, Entity* _instigator, Entity* _owner) :
	m_component(), m_id(_id), m_instigator(_instigator), m_owner(_owner)
{
	this->transform = AddComponent<Transform>(_transform);
}

Entity::Entity(const Entity& _entity) : Entity(*_entity.transform, _entity.m_id, _entity.m_instigator, _entity.m_owner)
{
}

Entity::~Entity()
{
	this->RemoveAllComponent();
}
