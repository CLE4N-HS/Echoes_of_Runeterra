#include "Player.h"
#include "textureManager.h"

Player::Player() : Character("Player")
{
}

Player::~Player()
{
}

void Player::update(Window& _window)
{
	float dt = _window.getDeltaTime();

	m_attackTimer += dt;

	if (!m_inventory->isOpen() && _window.mouseManager.hasJustPressed(sf::Mouse::Left))
	{
		m_targetPos = _window.getMousePos();
		m_foward = sf::Vector2f(m_targetPos - m_pos);
		vec2fNormalize(m_foward);
	}

	if (vec2fGetMagnitude(sf::Vector2f(m_targetPos - m_pos)) > 26.f)
	{
		m_pos += m_foward * m_moveSpeed * dt;
		m_animState = "walk";
	}
	else
	{
		m_animState = "idle";
	}

	m_inventory->update(_window);
}

void Player::display(Window& _window)
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

	m_inventory->display(_window);
}
