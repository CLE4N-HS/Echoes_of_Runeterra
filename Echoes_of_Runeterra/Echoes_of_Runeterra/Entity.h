#pragma once
#include "Tools.h"
#include "Transform.h"

#define COMPONENT_TEMPLATE \
template<typename T, typename ...Args, typename = std::enable_if_t<std::is_base_of_v<Component, T>>>

class Entity
{
public:
	Entity();
	Entity(const Transform& _transform, unsigned char _id = '\0', Entity* _instigator = nullptr, Entity* _owner = nullptr);
	~Entity();

	COMPONENT_TEMPLATE
	T* AddComponent(Args... _args)
	{
		T* component = new T(_args...);
		m_component.push_back(component);
		return component;
	}

	COMPONENT_TEMPLATE
	T* GetComponent() const
	{
		for (Component* comp : m_component)
		{
			T* castedComp = dynamic_cast<T*>(comp);
			
			if (castedComp != nullptr)
				return castedComp;
		}

		return nullptr;
	}

	void RemoveAllComponent()
	{
		for (size_t i = 0; i < m_component.size();)
		{
			delete m_component[i];
			m_component.erase(m_component.begin());
		}
	}

	inline unsigned char GetId() { return m_id; }
	inline Entity* GetParent() { return m_instigator; }
	inline Entity* GetOwner() { return m_owner; }

	Transform* transform;

private:
	unsigned char m_id;
	Entity* m_instigator;
	Entity* m_owner;

	std::vector<Component*> m_component;

};
