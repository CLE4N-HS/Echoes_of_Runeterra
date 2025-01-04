#include "Tools.h"

sf::Clock Tools::m_clock = sf::Clock();
sf::Time Tools::m_time = sf::Time();
float Tools::m_deltaTime = 0.f;

Tools tool = Tools::Tools();

Tools::Tools()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Tools::Update()
{
    m_time = m_clock.restart();
    m_deltaTime = m_time.asSeconds();
}

float Tools::Magnitude(const sf::Vector2f& _v)
{
    return std::sqrtf(_v.x * _v.x + _v.y * _v.y);
}

float Tools::Magnitude(const sf::Vector2f& _v1, const sf::Vector2f& _v2)
{
    return Tools::Magnitude(sf::Vector2f(_v1 - _v2));
}

float Tools::SqrMagnitude(const sf::Vector2f& _v)
{
    return (_v.x * _v.x + _v.y * _v.y);
}

float Tools::SqrMagnitude(const sf::Vector2f& _v1, const sf::Vector2f& _v2)
{
    return Tools::SqrMagnitude(sf::Vector2f(_v1 - _v2));
}

sf::Vector2f Tools::Multiply(const sf::Vector2f& _v1, const sf::Vector2f& _v2)
{
    return sf::Vector2f(_v1.x * _v2.x, _v1.y * _v2.y);
}

sf::Vector2f Tools::Normalize(const sf::Vector2f& _v)
{
    float magnitude = vec2fGetMagnitude(_v);
    if (magnitude >= EPSILON)
        return _v / magnitude;

    return sf::Vector2f();
}

float Tools::Lerp(const float& _a, const float& _b, const float& _t)
{
    return ((_b - _a) * _t + _a);
}

sf::Vector2f Tools::Lerp(const sf::Vector2f& _v1, const sf::Vector2f& _v2, const float& _t)
{
    return sf::Vector2f(Tools::Lerp(_v1.x, _v2.x, _t), Tools::Lerp(_v1.y, _v2.y, _t));
}

sf::Color Lerp(const sf::Color& _c1, const sf::Color& _c2, const float& _t)
{
    sf::Color c;
    c.r = static_cast<sf::Uint8>(Tools::Lerp(static_cast<float>(_c1.r), static_cast<float>(_c2.r), _t));
    c.g = static_cast<sf::Uint8>(Tools::Lerp(static_cast<float>(_c1.g), static_cast<float>(_c2.g), _t));
    c.b = static_cast<sf::Uint8>(Tools::Lerp(static_cast<float>(_c1.b), static_cast<float>(_c2.b), _t));
    c.a = static_cast<sf::Uint8>(Tools::Lerp(static_cast<float>(_c1.a), static_cast<float>(_c2.a), _t));
    return c;
}

void Tools::CenterTextOrigin(sf::Text& _text)
{
    sf::FloatRect tmpRect = _text.getGlobalBounds();
    _text.setOrigin(sf::Vector2f(tmpRect.getSize().x * 0.5f, tmpRect.getSize().y));
}

void Tools::CenterTextOriginString(sf::Text& _text)
{
    sf::FloatRect tmpRect = _text.getGlobalBounds();
    _text.setOrigin(sf::Vector2f(tmpRect.getSize().x * 0.5f, 0.f));
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

sf::Vector2f lerpVector(sf::Vector2f v0, sf::Vector2f v1, float t)
{
    return sf::Vector2f(lerp(v0.x, v1.x, t), lerp(v0.y, v1.y, t));
}

float getAngleBetweenVectors(sf::Vector2f a, sf::Vector2f b)
{
    return atan2f(b.y, b.x) - atan2f(a.y, a.x);
}
