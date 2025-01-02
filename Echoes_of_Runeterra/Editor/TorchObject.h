#pragma once
#include "Object.h"

class TorchObject : public Object
{
public:
	TorchObject();
	TorchObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName);
	~TorchObject();

	virtual void Display() override;

private:

};
