#include "Character.h"
#include "MouseManager.h"
#include "textureManager.h"

Character::Character() : Character("Default Name")
{
}

Character::Character(std::string _name) : Character(_name, 1, 0, 1, 1, 1, 1, ALIGNEMENT_NULL)
{
}

Character::Character(std::string _name, int _level, int _xp, int _hp, int _defense, int _stamina, int _speed, Alignement _alignement) :
	m_name(_name), m_level(_level), m_xp(_xp), m_hp(_hp), m_defense(_defense), m_stamina(_stamina), m_speed(_speed), m_alignement(_alignement),

	m_maxHp(m_hp),
	m_race(Race::RACE_IONIAN, "Ionian", 0, 0, 20),
	m_levelXp(100), m_skillPoint(0),
	m_pos(), m_targetPos(m_pos), m_foward(), m_moveSpeed(100.f)
{
}

Character::~Character()
{
}

void Character::update(Window& _window)
{
	float dt = _window.getDeltaTime();

	if (m_xp >= m_levelXp)
	{
		gainLevel();
		m_race.displayStats();
	}

	//if (MouseManager::hasJustPressed(sf::Mouse::Left))
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_targetPos = _window.getMousePos();
		m_foward = sf::Vector2f(m_targetPos - m_pos);
		vec2fNormalize(m_foward);
	}

	if (vec2fGetMagnitude(sf::Vector2f(m_targetPos - m_pos)) > 26.f)
	{
		m_pos += m_foward * m_moveSpeed * dt;
	}
}

void Character::display(Window& _window)
{
	_window.rectangle.setPosition(m_pos);
	_window.rectangle.setSize(sf::Vector2f(52.f, 44.f));
	_window.rectangle.setOrigin(sf::Vector2f(26.f, 22.f));
	_window.rectangle.setFillColor(sf::Color::Cyan);
	//_window.rectangle.setTexture(tex_getTexture("viego"));
	//_window.rectangle.setTextureRect(tex_getAnimRect("viego", "idle"));
	_window.draw(_window.rectangle);
}

int Character::getLevel() const
{
	return m_level;
}

void Character::giveXp(int _xp)
{
	m_xp += _xp;
}

void Character::setPos(sf::Vector2f _pos)
{
	m_pos = _pos;
	m_targetPos = _pos;
}

void Character::gainLevel()
{
	m_level++;
	m_skillPoint++;
	m_xp -= m_levelXp;
	upgradeLevelXp();

	m_maxHp += 10;
	m_hp = m_maxHp;
}

void Character::upgradeLevelXp()
{
	m_levelXp += (m_levelXp / 5 + 50) / 10 * 10;
}
