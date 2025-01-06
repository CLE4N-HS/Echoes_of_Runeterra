#pragma once
#include "Tools.h"

// should be an abstract class ik but ain't got the time sry
class Particle
{
public:
	Particle() = default;
	~Particle() = default;

	bool Update();
	void Display();

	sf::Color startColor = sf::Color();
	sf::Color endColor = sf::Color();
	float timeToDie = 1.0f;

	sf::Vector2f pos = sf::Vector2f();
	sf::Vector2f size = sf::Vector2f();
	sf::Vector2f origin = sf::Vector2f();
	sf::Vector2f velocity = sf::Vector2f();
	sf::Color color = sf::Color();
	float lifeTime = 0.0f;

};
