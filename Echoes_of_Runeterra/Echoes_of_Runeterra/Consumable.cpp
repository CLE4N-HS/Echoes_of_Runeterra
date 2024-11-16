#include "Consumable.h"
#include "textureManager.h"

Consumable::Consumable() : Consumable("", 0, 0, 0)
{
}

Consumable::Consumable(std::string _name, int _hp, int _defense, int _speed) : Item(_name),
	m_name(_name), m_hp(_hp), m_defense(_defense), m_speed(_speed)
{
}

Consumable::~Consumable()
{
}

void Consumable::Update()
{
	Item::Update();
}

void Consumable::Display()
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

void Consumable::displayStats(Window& _window)
{
	//_window.rectangle.setPosition(Consumable::m_pos);
	//_window.rectangle.setOrigin(sf::Vector2f());
	//_window.rectangle.setSize(sf::Vector2f(200.f, 200.f));
	//_window.rectangle.setFillColor(sf::Color(128, 128, 128, 200));
	//_window.rectangle.setTexture(nullptr);

	//_window.draw(_window.rectangle);
	//_window.rectangle.setFillColor(sf::Color(255, 255, 255));

	//_window.text.setCharacterSize(20);
	//_window.text.setFillColor(sf::Color::White);
	//_window.text.setOrigin(sf::Vector2f());
	//sf::Vector2f textPos(Consumable::m_pos);
	//char buffer[100]{};

	//textPos.y += 30.f;
	//_window.text.setPosition(textPos);
	//sprintf(buffer, "Hp : %d", m_hp);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//textPos.y += 30.f;
	//_window.text.setPosition(textPos);
	//sprintf(buffer, "Defense : %d", m_defense);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//textPos.y += 30.f;
	//_window.text.setPosition(textPos);
	//sprintf(buffer, "Speed : %d", m_speed);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);
}

int Consumable::getHpBuff() const
{
	return m_hp;
}

int Consumable::getDefenseBuff() const
{
	return m_defense;
}

int Consumable::getSpeedBuff() const
{
	return m_speed;
}
