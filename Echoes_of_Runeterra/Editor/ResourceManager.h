#pragma once
#include <map>
#include <string_view>

template<typename T>
class ResourceManager
{
public:
	ResourceManager() = default;
	~ResourceManager() = default;

	bool AddResource();

private:
	std::map<std::string_view, T*> m_Resource{};

};

template<typename T>
inline bool ResourceManager<T>::AddResource()
{
	return false;
}
