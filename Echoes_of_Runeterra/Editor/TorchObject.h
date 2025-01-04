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

	virtual nlohmann::json ToJson() override;
	virtual void FromJson(const nlohmann::json& _j) override;

private:
	float m_ParticleTime = 0.f;
	float m_TimeToParticle = 0.2f;

};
