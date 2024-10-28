#include "Character.h"
#include "Ionian.h"

Character::Character() : Character("Default Name")
{
}

Character::Character(std::string _name) : Character(_name, 1, 0, 1, 1, 1, 1, ALIGNEMENT_NULL)
{
}

Character::Character(std::string _name, int _level, int _xp, int _hp, int _defense, int _stamina, int _speed, Alignement _alignement) :
	m_name(_name), m_level(_level), m_xp(_xp), m_hp(_hp), m_defense(_defense), m_stamina(_stamina), m_speed(_speed), m_alignement(_alignement),

	m_maxHp(m_hp),
	m_levelXp(100), m_skillPoint(0),
	m_pos(), m_foward(), m_velocity()
{
	m_race = Ionian("Ionian Name", 5, 2, 20, 20);
}

Character::~Character()
{
}

void Character::update()
{
	if (m_xp >= m_levelXp)
	{
		gainLevel();
	}
	m_race.displayStats();
}

int Character::getLevel() const
{
	return m_level;
}

void Character::giveXp(int _xp)
{
	m_xp += _xp;
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
