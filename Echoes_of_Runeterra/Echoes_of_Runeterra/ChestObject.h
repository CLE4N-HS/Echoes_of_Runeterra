#pragma once
#include "Object.h"

class ChestObject : public Object
{
public:
	ChestObject();
	ChestObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName);
	~ChestObject();

	virtual void Display() override;

	virtual nlohmann::json ToJson() override;
	virtual void FromJson(const nlohmann::json& _j) override;

private:

};
