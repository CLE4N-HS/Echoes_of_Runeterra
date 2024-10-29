#pragma once
#include "Window.h"
#include "alignement.h"
#include "Race.h"

class Character
{
public:
	Character();
	Character(std::string _name);
	Character(std::string _name, int _level, int _hp, int _defense, int _xp, int _stamina, int _speed, Alignement _alignement);
	~Character();

	void update(Window& _window);
	void display(Window& _window);

	int getLevel() const;
	void giveXp(int _xp);
	void setPos(sf::Vector2f _pos);

private:
	void upgradeLevelXp();
	void gainLevel();

	Race m_race;

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
	sf::Vector2f m_targetPos;
	sf::Vector2f m_foward;
	float m_moveSpeed;

};
