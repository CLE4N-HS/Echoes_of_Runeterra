#include "Entity.h"

Entity::Entity() : Entity(Transform())
{
}

Entity::Entity(const Transform& _transform, unsigned char _id, Entity* _instigator, Entity* _owner) :
	m_component(), m_id(_id), m_instigator(_instigator), m_owner(_owner)
{
	this->transform = AddComponent<Transform>(_transform);
}

Entity::~Entity()
{
	this->RemoveAllComponent();
}
