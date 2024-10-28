#pragma once
#include "windowManager.h"
#include "alignement.h"

class Character
{
public:
	Character();
	Character(std::string _name);
	Character(std::string _name, int _level, int _hp, int _defense, int _xp, int _stamina, int _speed, Alignement _alignement);
	~Character();

	void update();

	int getLevel() const;
	void giveXp(int _xp);

protected:
	void upgradeLevelXp();
	void gainLevel();

	std::string m_name;
	int m_level;
	int m_xp;
	int m_levelXp;
	int m_skillPoint;

	int m_hp, m_maxHp;
	int m_defense;
	int m_stamina;
	int m_speed;
	Alignement m_alignement;

	sf::Vector2f m_pos;
	sf::Vector2f m_foward;
	sf::Vector2f m_velocity;

};
