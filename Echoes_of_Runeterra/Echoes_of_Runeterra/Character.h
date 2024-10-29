#pragma once
#include "Window.h"
#include "alignement.h"
#include "Race.h"

class Character
{
public:
	Character();
	Character(std::string _name);
	Character(std::string _name, int _level, int _hp, int _attack, int _defense, int _xp, int _stamina, int _speed, Alignement _alignement);
	~Character();

	void update(Window& _window);
	void display(Window& _window);

	int getLevel() const;
	void giveXp(int _xp);

	sf::Vector2f getPos() const;
	void setPos(sf::Vector2f _pos);
	void attack(Character& _character);

protected:
	void upgradeLevelXp();
	void gainLevel();

	Race m_race;

	std::string m_name;
	int m_level;
	int m_xp;
	int m_levelXp;
	int m_skillPoint;

	int m_hp, m_maxHp;
	int m_attack;
	int m_defense;
	int m_stamina;
	int m_speed;
	Alignement m_alignement;

	sf::Vector2f m_pos;
	sf::Vector2f m_targetPos;
	sf::Vector2f m_foward;
	float m_moveSpeed;

	int m_frameX;
	float m_animTimer;
	std::string m_animState;

	float m_attackTimer;


};
