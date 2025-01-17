#include "Character.h"
#include "MouseManager.h"
#include "textureManager.h"
#include "ComponentName.h"

Pawn::Pawn() : Pawn("Default Name")
{
}

Pawn::Pawn(std::string _name) : Pawn(_name, 1, 0, 100, 2, 1, 1, 1, ALIGNEMENT_NULL)
{
}

Pawn::Pawn(std::string _name, int _level, int _xp, int _hp, int _attack, int _defense, int _stamina, int _speed, Alignement _alignement) :
	Entity(Transform()),
	m_level(_level), m_xp(_xp),// m_hp(_hp), m_attack(_attack), m_defense(_defense), m_stamina(_stamina), m_speed(_speed), m_alignement(_alignement),
	m_specialization(),
	//m_race(Race::RACE_IONIAN, "Ionian", 0, 0, 20),
	//m_maxHp(m_hp),
	m_levelXp(100)
	//m_animState("idle"), m_frameX(0), m_animTimer(0.f), m_attackTimer(0.f),
	//m_takingAnItem(false), m_isHovered(false)
{
	//AddComponent<ComponentName>(_name);
	sf::FloatRect animRect = static_cast<sf::FloatRect>(sf::IntRect());
	//sf::IntRect animRect = tex_getAnimRect("viego", m_animState.c_str());
	transform->setSize(animRect.getSize());
	transform->setOrigin(transform->getSize() * 0.5f);
	//transform->setScale(sf::Vector2f(2.f, 2.f));
}

Pawn::~Pawn()
{
	delete m_weapon;
	delete m_armor;
	delete m_profession;
}

int Pawn::getLevel() const
{
	return m_level;
}

void Pawn::giveXp(int _xp)
{
	m_xp += _xp;

	if (m_xp >= m_levelXp)
		gainLevel();
}

void Pawn::attack(Pawn& _character)
{
	//if (m_attackTimer > 2.f) {
	//	m_attackTimer = 0.f;
	//	_character.m_hp -= m_attack;
	//	giveXp(100);
	//	_character.giveXp(50);
	//	m_race.displayStats();
	//	std::cout << std::endl << std::endl;
	//}
}

void Pawn::setHover(bool _isHovered)
{
	//m_isHovered = _isHovered;
}

void Pawn::AddSkill(Skills* _skill)
{
	m_skill.push_back(_skill);
}

void Pawn::gainLevel()
{
	m_level++;
	//m_skillPoint++;
	m_xp -= m_levelXp;
	upgradeLevelXp();

	//m_maxHp += 10;
	//m_hp = m_maxHp;
}

void Pawn::upgradeLevelXp()
{
	m_levelXp += (m_levelXp / 5 + 50) / 10 * 10;
}
