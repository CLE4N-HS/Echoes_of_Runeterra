#pragma once
#include "Component.h"

class ComponentName : public Component
{
public:
	ComponentName();
	ComponentName(std::string _name);
	~ComponentName() = default;

	inline std::string GetName() { return m_name; }
	inline void SetName(const std::string& _name) { m_name = _name; }

private:
	std::string m_name;

};
