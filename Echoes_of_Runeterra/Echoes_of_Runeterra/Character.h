#pragma once
#include "Tools.h"
#include "Entity.h"
#include "alignement.h"
#include "Race.h"
#include "Weapon.h"
#include "Armor.h"
#include "Profession.h"
#include "Specialization.h"
#include "Skills.h"

class Pawn : public Entity
{
public:
	Pawn();
	Pawn(std::string _name);
	Pawn(std::string _name, std::string _dialogueKey);
	Pawn(std::string _name, std::string _dialogueKey, int _level, int _hp, int _attack, int _defense, int _xp, int _stamina, int _speed, Alignement _alignement);
	~Pawn();

	virtual void Update() = 0;

	virtual void Display() = 0;

	void setDialogueKey(std::string _dialogueKey);
	std::string getDialogueKey();

	int getLevel() const;
	void giveXp(int _xp);

	void attack(Pawn& _character);

	void setHover(bool _isHovered);
	virtual sf::FloatRect getRect() = 0;

protected:
	Weapon* m_weapon = nullptr;
	Armor* m_armor = nullptr;
	
	Profession* m_profession = nullptr;

	Specialization m_specialization;

	std::vector<Skills*> m_skill = {};




	void upgradeLevelXp();
	void gainLevel();



	Race m_race;

	// npc
	std::string m_dialogueKey;

	int m_level;
	int m_xp;
	int m_levelXp;

	int m_hp, m_maxHp;
	int m_attack;
	int m_defense;
	int m_stamina;
	int m_speed;
	Alignement m_alignement;

	int m_frameX;
	float m_animTimer;
	std::string m_animState;

	float m_attackTimer;

	bool m_takingAnItem;

	bool m_isHovered;


};
