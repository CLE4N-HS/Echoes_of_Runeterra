#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <fstream>

#define EPSILON ((float)1e-6)

float vec2fGetMagnitude(sf::Vector2f _vec);
void vec2fNormalize(sf::Vector2f& _vec);
