#pragma once
#include "tools.h"
#include "Component.h"

class Entity
{
public:
	Entity();
	~Entity();

	template<typename T, typename ...Args, typename = std::enable_if_t<std::is_base_of_v<Component, T>>>
	void addComponent(Args... _args)
	{
		T* component = new T(_args...);
		m_component.push_back(component);
	}

	template<typename T>
	T* getComponent() const
	{
		for (Component* comp : m_component)
		{
			T* castedComp = dynamic_cast<T*>(comp);
			
			if (castedComp != nullptr)
				return castedComp;
		}

		return nullptr;
	}

private:
	std::vector<Component*> m_component;

};
