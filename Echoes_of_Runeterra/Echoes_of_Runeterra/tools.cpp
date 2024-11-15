#include "tools.h"

sf::Clock Tools::m_clock = sf::Clock();
sf::Time Tools::m_time = sf::Time();
float Tools::m_deltaTime = 0.f;

Tools::Tools()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

Tools::~Tools()
{
}

void Tools::Update()
{
    m_time = m_clock.restart();
    m_deltaTime = m_time.asSeconds();
}

/*
*
* The following code is left there to not damage any previous C code
*
*/
float vec2fGetMagnitude(sf::Vector2f _vec)
{
    return sqrtf(_vec.x * _vec.x + _vec.y * _vec.y);
}

float vec2fGetSqrMagnitude(sf::Vector2f _vec)
{
    return _vec.x * _vec.x + _vec.y * _vec.y;
}

void vec2fNormalize(sf::Vector2f& _vec)
{
    float magnitude = vec2fGetMagnitude(_vec);
    if (magnitude >= EPSILON)
        _vec /= magnitude;
}

sf::Vector2f vec2fMultiply(sf::Vector2f _v1, sf::Vector2f _v2)
{
    return sf::Vector2f(_v1.x * _v2.x, _v1.y * _v2.y);
}

sf::Vector2f polarCoord(sf::Vector2f const& _a, float const& _r, float const& _teta)
{
    return sf::Vector2f(_a.x + (_r * cosf(_teta)), _a.y + (_r * sinf(_teta)));
}

int randomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

float randomFloat(float min, float max)
{
    return (float)randomInt((int)min, (int)max);
}

float lerp(float v0, float v1, float t)
{
    return (1.f - t) * v0 + t * v1;
}
