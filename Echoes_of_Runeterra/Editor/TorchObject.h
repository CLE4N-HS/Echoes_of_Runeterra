#pragma once
#include "Object.h"
#include "DayNightSystem.h"

class TorchObject : public Object
{
public:
	TorchObject();
	TorchObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName);
	~TorchObject();

	virtual void Display() override;

	void DisplayShader(DayNightSystem& _system);
	void DisplayParticles();

private:

};
