#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <fstream>
#include <map>
#include <list>
#include <unordered_map>

#define EPSILON ((float)1e-6)
#define DEG2RAD ((float)0.01745329f)

class Tools
{
public:
	Tools();
	~Tools() = default;

	/// <summary>
	/// Call this at the start of every frame in order to update correctly the delta time
	/// </summary>
	static void Update();

	static inline float GetDeltaTime() { return m_deltaTime; }

private:
	static sf::Clock m_clock;
	static sf::Time m_time;	
	static float m_deltaTime;

};

/*
*
* The following code is left there to not damage any previous C code
*
*/
float vec2fGetMagnitude(sf::Vector2f _vec);
float vec2fGetSqrMagnitude(sf::Vector2f _vec);
void vec2fNormalize(sf::Vector2f& _vec);
sf::Vector2f vec2fMultiply(sf::Vector2f _v1, sf::Vector2f _v2);
sf::Vector2f polarCoord(sf::Vector2f const& _a, float const& _r, float const& _teta);
int randomInt(int min, int max);
float randomFloat(float min, float max);
float lerp(float v0, float v1, float t);
