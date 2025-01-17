#include "Weapon.h"
#include "textureManager.h"

Weapon::Weapon() : Weapon("", 0, 0, 0)
{
}

Weapon::Weapon(std::string _name, int _damage, int _criticalDamage, int _speed) : Item(_name),
	m_name(_name), m_damage(_damage), m_critcalDamage(_criticalDamage), m_speed(_speed)
{
}

Weapon::Weapon(const Weapon& _weapon) : Weapon(_weapon.m_name, _weapon.m_damage, _weapon.m_critcalDamage, _weapon.m_speed)
{
}

Weapon::~Weapon()
{
}

void Weapon::Update()
{
	Item::Update();
}

void Weapon::Display()
{
	//_window.rectangle.setTexture(tex_getTexture("items"));
	//_window.rectangle.setTextureRect(tex_getAnimRect("items", m_name.c_str()));
	//_window.rectangle.setPosition(m_pos);
	//_window.rectangle.setSize(m_size);
	//_window.rectangle.setOrigin(m_origin);
	//_window.rectangle.setScale(m_scale);


	//_window.draw(_window.rectangle);
	//_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));

	//if (m_isHovered)
	//{
	//	if (m_state == Item::State::IN_INVENTORY)
	//		displayStats(_window);
	//	else if (m_state == Item::State::ON_MAP)
	//	{
	//		_window.rectangle.setSize(m_size);
	//		_window.rectangle.setOrigin(m_origin);
	//		_window.rectangle.setScale(m_scale);
	//		_window.rectangle.setFillColor(sf::Color(255, 255, 255, 100));
	//		_window.rectangle.setTexture(nullptr);

	//		_window.draw(_window.rectangle);
	//		_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));
	//		_window.rectangle.setFillColor(sf::Color(255, 255, 255));
	//	}
	//}

}

//void Weapon::displayStats(Window& _window)
//{
	//_window.rectangle.setPosition(Weapon::m_pos);
	//_window.rectangle.setOrigin(sf::Vector2f());
	//_window.rectangle.setSize(sf::Vector2f(200.f, 200.f));
	//_window.rectangle.setFillColor(sf::Color(128, 128, 128, 200));
	//_window.rectangle.setTexture(nullptr);

	//_window.draw(_window.rectangle);
	//_window.rectangle.setFillColor(sf::Color(255, 255, 255));

	//_window.text.setCharacterSize(20);
	//_window.text.setFillColor(sf::Color::White);
	//_window.text.setOrigin(sf::Vector2f());
	//sf::Vector2f textPos(Weapon::m_pos);
	//char buffer[100]{};

	//textPos.y += 30.f;
	//_window.text.setPosition(textPos);
	//sprintf(buffer, "Damage : %d", m_damage);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//textPos.y += 30.f;
	//_window.text.setPosition(textPos);
	//sprintf(buffer, "Critical Damage : %d", m_critcalDamage);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//textPos.y += 30.f;
	//_window.text.setPosition(textPos);
	//sprintf(buffer, "Speed : %d", m_speed);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);
//}

int Weapon::getDamage() const
{
	//if (isAttackCritical())
	//	return (m_damage + m_critcalDamage);

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
