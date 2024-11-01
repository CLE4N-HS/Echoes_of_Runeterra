#include "Weapon.h"
#include "textureManager.h"

Weapon::Weapon() : Weapon("Default Weapon Name", 0, 0, 0)
{
}

Weapon::Weapon(std::string _name, int _damage, int _criticalDamage, int _speed) : Item(_name),
	m_name(_name), m_damage(_damage), m_critcalDamage(_criticalDamage), m_speed(_speed)
{
}

Weapon::~Weapon()
{
}

void Weapon::display(Window& _window)
{
	_window.rectangle.setTexture(tex_getTexture("items"));
	sf::IntRect tmpRect = tex_getAnimRect("items", m_name.c_str());
	_window.rectangle.setTextureRect(tmpRect);
	_window.rectangle.setSize(sf::Vector2f((float)(tmpRect.width), (float)(tmpRect.height)));
	_window.rectangle.setOrigin(sf::Vector2f((float)(tmpRect.width / 2), (float)(tmpRect.height / 2)));

	switch (m_state)
	{
	case Item::State::IN_INVENTORY:
		_window.rectangle.setPosition(sf::Vector2f((float)(tmpRect.left), (float)(tmpRect.top))); // should not be that TODO Entity class
		_window.rectangle.setScale(sf::Vector2f(5.f, 5.f));
		break;
	case Item::State::ON_GROUND:
		_window.rectangle.setPosition(sf::Vector2f((float)(tmpRect.left), (float)(tmpRect.top))); // should not be that TODO Entity class
		_window.rectangle.setScale(sf::Vector2f(5.f, 5.f));
		break;
	default:
		break;
	}

	_window.draw(_window.rectangle);
	_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));
}

int Weapon::getDamage() const
{
	if (isAttackCritical())
		return (m_damage + m_critcalDamage);

	return m_damage;
}

int Weapon::getSpeed() const
{
	return m_speed;
}

bool Weapon::isAttackCritical() const
{
	return (rand() % 100 < 20);  // 20% chance to get critical damage
}
