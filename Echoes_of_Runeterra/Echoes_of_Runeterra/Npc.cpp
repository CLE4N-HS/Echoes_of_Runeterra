#include "Npc.h"
#include "textureManager.h"

Npc::Npc() : Character("Npc")
{
}

Npc::Npc(std::string _name, std::string _dialogueKey) : Character(_name, _dialogueKey)
{
}

Npc::~Npc()
{
}

void Npc::update(Window& _window)
{
}

void Npc::display(Window& _window)
{
	_window.rectangle.setPosition(m_pos);
	_window.rectangle.setTexture(tex_getTexture("viego"));
	sf::IntRect tmpRect = texGetRectAnim(_window, "viego", m_animState.c_str(), &m_frameX, &m_animTimer);
	_window.rectangle.setSize(sf::Vector2f(sf::Vector2i(tmpRect.width, tmpRect.height)));
	_window.rectangle.setOrigin(sf::Vector2f(sf::Vector2i(tmpRect.width / 2, tmpRect.height / 2)));
	_window.rectangle.setTextureRect(tmpRect);
	if (m_animState == "walk" && m_foward.x < 0.f)
		_window.rectangle.setScale(sf::Vector2f(-2.f, 2.f));
	else
		_window.rectangle.setScale(sf::Vector2f(2.f, 2.f));

	_window.draw(_window.rectangle);
	_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));

	char buffer[100]{};
	_window.text.setCharacterSize(30);
	_window.text.setFillColor(sf::Color::White);

	_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 20.f));
	sprintf(buffer, "Level : %d", m_level);
	_window.text.setString(buffer);
	_window.draw(_window.text);

	_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 50.f));
	sprintf(buffer, "Xp : %d/%d", m_xp, m_levelXp);
	_window.text.setString(buffer);
	_window.draw(_window.text);

	if (m_isHovered)
	{
		_window.rectangle.setOrigin(sf::Vector2f());
		_window.rectangle.setPosition(m_pos);
		_window.rectangle.setSize(m_size);
		_window.rectangle.setTexture(nullptr);
		_window.rectangle.setFillColor(sf::Color(255, 255, 255, 100));

		_window.draw(_window.rectangle);

		_window.rectangle.setFillColor(sf::Color(255, 255, 255));
	}
}

sf::FloatRect Npc::getRect()
{
	sf::IntRect animRect = tex_getAnimRect("viego", m_animState.c_str());
	m_size = sf::Vector2f((float)animRect.width, (float)animRect.height);
	return sf::FloatRect(m_pos, m_size);
}
