#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Companion.h"
#include "Consumable.h"
#include "FightStats.h"

class Player : public Pawn
{
public:
	Player();
	Player(std::string _name);
	~Player();

	virtual void Update() override;
	virtual void Display() override;

	inline void AddItem(const GameItem& _gameItem) { m_inventory.AddItem(_gameItem); }

	void AddCompanion(Companion* _companion);

	inline Inventory& GetInventory() { return m_inventory; }

	void Consume(Consumable* _consumable);

	inline FightStats& GetFightStats() { return m_fightStats; }

protected:
	Inventory m_inventory;

	std::vector<Companion*> m_companion;

	FightStats m_fightStats;

	int m_skillPoint = 0;
	float m_moveSpeed = 500.f;

	sf::Vector2f m_targetPos = sf::Vector2f();
	sf::Vector2f m_forward = sf::Vector2f();



	void UpdateMovement();
	void UpdateInventoryInteractions();

};
