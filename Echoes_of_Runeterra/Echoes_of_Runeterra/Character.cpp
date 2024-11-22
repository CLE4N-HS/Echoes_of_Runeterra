#include "Character.h"
#include "MouseManager.h"
#include "textureManager.h"

Pawn::Pawn() : Pawn("Default Name")
{
}

Pawn::Pawn(std::string _name) : Pawn(_name, "")
{
}

Pawn::Pawn(std::string _name, std::string _dialogueKey) : Pawn(_name, _dialogueKey, 1, 0, 100, 2, 1, 1, 1, ALIGNEMENT_NULL)
{
}

Pawn::Pawn(std::string _name, std::string _dialogueKey, int _level, int _xp, int _hp, int _attack, int _defense, int _stamina, int _speed, Alignement _alignement) :
	Entity(Transform()),
	m_name(_name), m_dialogueKey(_dialogueKey), m_level(_level), m_xp(_xp), m_hp(_hp), m_attack(_attack), m_defense(_defense), m_stamina(_stamina), m_speed(_speed), m_alignement(_alignement),

	m_inventory(Inventory()),
	m_race(Race::RACE_IONIAN, "Ionian", 0, 0, 20),
	m_maxHp(m_hp),
	m_levelXp(100), m_skillPoint(0),
	m_targetPos(sf::Vector2f()), m_foward(), m_moveSpeed(200.f),
	m_animState("idle"), m_frameX(0), m_animTimer(0.f), m_attackTimer(0.f),
	m_takingAnItem(false), m_isHovered(false)
{
	sf::IntRect animRect = sf::IntRect();
	//sf::IntRect animRect = tex_getAnimRect("viego", m_animState.c_str());
	m_size = sf::Vector2f((float)animRect.width, (float)animRect.height);
	m_origin = m_size * 0.5f;
	m_scale = sf::Vector2f(2.f, 2.f);
}

Pawn::~Pawn()
{
}

void Pawn::setDialogueKey(std::string _dialogueKey)
{
	m_dialogueKey = _dialogueKey;
}

std::string Pawn::getDialogueKey()
{
	return m_dialogueKey;
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
	if (m_attackTimer > 2.f) {
		m_attackTimer = 0.f;
		_character.m_hp -= m_attack;
		giveXp(100);
		_character.giveXp(50);
		m_race.displayStats();
		std::cout << std::endl << std::endl;
	}
}

void Pawn::inventorySetOpening(bool _shouldBeOpened)
{
	m_inventory.setOpening(_shouldBeOpened);
}

bool Pawn::isInventoryOpen()
{
	return m_inventory.isOpen();
}

void Pawn::addItem(Item* _item)
{
	if (_item != nullptr)
		m_inventory.addItem(_item);
}

void Pawn::setHover(bool _isHovered)
{
	m_isHovered = _isHovered;
}

void Pawn::gainLevel()
{
	m_level++;
	m_skillPoint++;
	m_xp -= m_levelXp;
	upgradeLevelXp();

	m_maxHp += 10;
	m_hp = m_maxHp;
}

void Pawn::upgradeLevelXp()
{
	m_levelXp += (m_levelXp / 5 + 50) / 10 * 10;
}
