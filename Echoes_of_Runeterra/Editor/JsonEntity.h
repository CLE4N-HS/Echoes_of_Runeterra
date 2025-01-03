#pragma once

//#pragma warning(push)
//#pragma warning(disable : 26819)
#include "Externals/json.hpp"
//#pragma warning(pop)

class JsonEntity
{
public:
	JsonEntity() = default;
	~JsonEntity() = default;

	virtual nlohmann::json ToJson() = 0;
	virtual void FromJson(const nlohmann::json& _j) = 0;

};
