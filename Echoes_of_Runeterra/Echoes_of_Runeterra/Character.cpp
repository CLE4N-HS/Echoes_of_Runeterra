#include "Character.h"
#include "MouseManager.h"
#include "textureManager.h"

Character::Character() : Character("Default Name")
{
}

Character::Character(std::string _name) : Character(_name, 1, 0, 100, 2, 1, 1, 1, ALIGNEMENT_NULL)
{
}

Character::Character(std::string _name, int _level, int _xp, int _hp, int _attack, int _defense, int _stamina, int _speed, Alignement _alignement) :
	m_name(_name), m_level(_level), m_xp(_xp), m_hp(_hp), m_attack(_attack), m_defense(_defense), m_stamina(_stamina), m_speed(_speed), m_alignement(_alignement),

	m_maxHp(m_hp),
	m_race(Race::RACE_IONIAN, "Ionian", 0, 0, 20),
	m_levelXp(100), m_skillPoint(0),
	m_pos(), m_targetPos(m_pos), m_foward(), m_moveSpeed(100.f),
	m_attackTimer(0.f)
{
}

Character::~Character()
{
}

void Character::update(Window& _window)
{
	float dt = _window.getDeltaTime();

	m_attackTimer += dt;

	if (m_xp >= m_levelXp)
	{
		gainLevel();
		m_race.displayStats();
	}
	
	//if (MouseManager::hasJustPressed(sf::Mouse::Button::Left))
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_targetPos = _window.getMousePos();
		m_foward = sf::Vector2f(m_targetPos - m_pos);
		vec2fNormalize(m_foward);
	}

	if (m_name == "Player" && vec2fGetMagnitude(sf::Vector2f(m_targetPos - m_pos)) > 26.f)
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

}

int Character::getLevel() const
{
	return m_level;
}

void Character::giveXp(int _xp)
{
	m_xp += _xp;
}

sf::Vector2f Character::getPos() const
{
	return m_pos;
}

void Character::setPos(sf::Vector2f _pos)
{
	m_pos = _pos;
	m_targetPos = _pos;
}

void Character::attack(Character& _character)
{
	if (m_attackTimer > 2.f) {
		m_attackTimer = 0.f;
		_character.m_hp -= m_attack;
		giveXp(100);
		_character.giveXp(50);
		m_race.displayStats();
		std::cout << std::endl << std::endl;
	}
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
