#include "Armor.h"
#include "textureManager.h"

Armor::Armor() : Armor("Default Armor Name", 0, 0, 0)
{
}

Armor::Armor(std::string _name, int _defense, int _speed, int _durability) : Item(_name),
	m_name(_name), m_defense(_defense), m_speed(_speed), m_durability(_durability)
{
}

Armor::~Armor()
{
}

void Armor::update(Window& _window)
{
	Item::update(_window);
}

void Armor::display(Window& _window)
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
		_window.rectangle.setPosition(sf::Vector2f(800.f, 500.f)); // should not be that TODO Entity class
		_window.rectangle.setScale(sf::Vector2f(5.f, 5.f));
		break;
	case Item::State::ON_MAP:
		_window.rectangle.setPosition(sf::Vector2f((float)(tmpRect.left), (float)(tmpRect.top))); // should not be that TODO Entity class
		_window.rectangle.setScale(sf::Vector2f(5.f, 5.f));
		break;
	default:
		break;
	}

	_window.draw(_window.rectangle);
	_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));

	if (m_isHovered)
		displayStats(_window);
}

void Armor::displayStats(Window& _window)
{
	sf::Vector2f statsPos = sf::Vector2f(800.f, 500.f);

	_window.rectangle.setPosition(sf::Vector2f(statsPos));
	_window.rectangle.setOrigin(sf::Vector2f());
	_window.rectangle.setSize(sf::Vector2f(200.f, 200.f));
	_window.rectangle.setFillColor(sf::Color(128, 128, 128, 200));
	_window.rectangle.setTexture(nullptr);

	_window.draw(_window.rectangle);
	_window.rectangle.setFillColor(sf::Color(255, 255, 255));

	_window.text.setCharacterSize(20);
	_window.text.setFillColor(sf::Color::White);
	_window.text.setOrigin(sf::Vector2f());
	sf::Vector2f textPos(statsPos);
	char buffer[100]{};

	textPos.y += 30.f;
	_window.text.setPosition(textPos);
	sprintf(buffer, "Defense : %d", m_defense);
	_window.text.setString(buffer);
	_window.draw(_window.text);

	textPos.y += 30.f;
	_window.text.setPosition(textPos);
	sprintf(buffer, "Speed : %d", m_speed);
	_window.text.setString(buffer);
	_window.draw(_window.text);

	textPos.y += 30.f;
	_window.text.setPosition(textPos);
	sprintf(buffer, "Durability : %d", m_durability);
	_window.text.setString(buffer);
	_window.draw(_window.text);
}

int Armor::getDefense() const
{
	return m_defense;
}

int Armor::getSpeed() const
{
	return m_speed;
}

int Armor::getDurability() const
{
	return m_durability;
}
