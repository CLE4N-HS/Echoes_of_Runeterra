#include "Npc.h"
#include "textureManager.h"


Npc::Npc() : Npc("Default Npc")
{
}

Npc::Npc(std::string _name) : Pawn(_name)
{
	this->transform->setSize(sf::Vector2f(20.f, 20.f));
	this->transform->setOrigin(this->transform->getSize() * 0.5f);
}

Npc::~Npc()
{
}

void Npc::Update()
{

}

void Npc::Display()
{
	

	//_window.rectangle.setPosition(sf::Vector2f());
	//_window.rectangle.setTexture(tex_getTexture("viego"));
	//_window.rectangle.setSize(m_size);
	//_window.rectangle.setOrigin(m_origin);
	//_window.rectangle.setTextureRect(texGetRectAnim(_window, "viego", m_animState.c_str(), &m_frameX, &m_animTimer));
	//if (m_animState == "walk" && m_foward.x < 0.f)
	//	_window.rectangle.setScale(sf::Vector2f(m_scale.x * -1.f, m_scale.y));
	//else
	//	_window.rectangle.setScale(m_scale);

	//_window.draw(_window.rectangle);

	//char buffer[100]{};
	//_window.text.setCharacterSize(30);
	//_window.text.setFillColor(sf::Color::White);

	//_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 20.f));
	//sprintf(buffer, "Level : %d", m_level);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 50.f));
	//sprintf(buffer, "Xp : %d/%d", m_xp, m_levelXp);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//if (m_isHovered)
	//{
	//	_window.rectangle.setOrigin(m_origin);
	//	_window.rectangle.setPosition(m_pos);
	//	_window.rectangle.setSize(m_size);
	//	_window.rectangle.setScale(m_scale);
	//	_window.rectangle.setTexture(nullptr);
	//	_window.rectangle.setFillColor(sf::Color(255, 255, 255, 100));

	//	_window.draw(_window.rectangle);
	//}

	//_window.rectangle.setFillColor(sf::Color(255, 255, 255));
	//_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));
}
;