#include "Armor.h"
#include "textureManager.h"

Armor::Armor() : Armor("", 0, 0, 0)
{
}

Armor::Armor(std::string _name, int _defense, int _speed, int _durability) : Item(_name),
	m_name(_name), m_defense(_defense), m_speed(_speed), m_durability(_durability)
{
}

Armor::Armor(const Armor& _armor) : Armor(_armor.m_name, _armor.m_defense, _armor.m_speed, _armor.m_durability)
{
}

Armor::~Armor()
{
}

void Armor::Update()
{
	Item::Update();
}

void Armor::Display()
{
	/*_window.rectangle.setTexture(tex_getTexture("items"));
	_window.rectangle.setTextureRect(tex_getAnimRect("items", m_name.c_str()));
	_window.rectangle.setPosition(m_pos);
	_window.rectangle.setSize(m_size);
	_window.rectangle.setOrigin(m_origin);
	_window.rectangle.setScale(m_scale);


	_window.draw(_window.rectangle);
	_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));

	if (m_isHovered)
	{
		if (m_state == Item::State::IN_INVENTORY)
			displayStats(_window);
		else if (m_state == Item::State::ON_MAP)
		{
			_window.rectangle.setSize(m_size);
			_window.rectangle.setOrigin(m_origin);
			_window.rectangle.setScale(m_scale);
			_window.rectangle.setFillColor(sf::Color(255, 255, 255, 100));
			_window.rectangle.setTexture(nullptr);

			_window.draw(_window.rectangle);
			_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));
			_window.rectangle.setFillColor(sf::Color(255, 255, 255));
		}
	}*/
}

//void Armor::displayStats(Window& _window)
//{
	//_window.rectangle.setPosition(Armor::m_pos);
	//_window.rectangle.setOrigin(sf::Vector2f());
	//_window.rectangle.setSize(sf::Vector2f(200.f, 200.f));
	//_window.rectangle.setFillColor(sf::Color(128, 128, 128, 200));
	//_window.rectangle.setTexture(nullptr);

	//_window.draw(_window.rectangle);
	//_window.rectangle.setFillColor(sf::Color(255, 255, 255));

	//_window.text.setCharacterSize(20);
	//_window.text.setFillColor(sf::Color::White);
	//_window.text.setOrigin(sf::Vector2f());
	//sf::Vector2f textPos(Armor::m_pos);
	//char buffer[100]{};

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

	//textPos.y += 30.f;
	//_window.text.setPosition(textPos);
	//sprintf(buffer, "Durability : %d", m_durability);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);
//}

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
