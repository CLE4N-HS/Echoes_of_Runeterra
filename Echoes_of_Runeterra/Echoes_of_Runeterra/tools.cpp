#include "tools.h"

float vec2fGetMagnitude(sf::Vector2f _vec)
{
    return sqrtf(_vec.x * _vec.x + _vec.y * _vec.y);
}

void vec2fNormalize(sf::Vector2f& _vec)
{
    float magnitude = vec2fGetMagnitude(_vec);
    if (magnitude >= EPSILON)
        _vec /= magnitude;
}
