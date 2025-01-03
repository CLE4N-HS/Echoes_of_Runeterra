#pragma once
#include "Externals/json.hpp"

class JsonEntity
{
public:
	JsonEntity() = default;
	~JsonEntity() = default;

	virtual nlohmann::json ToJson() = 0;
	virtual void FromJson(const nlohmann::json& _j) = 0;

};
