#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Companion.h"

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

protected:
	Inventory m_inventory;

	std::vector<Companion*> m_companion;


	int m_skillPoint = 0;
	float m_moveSpeed = 500.f;

	sf::Vector2f m_targetPos = sf::Vector2f();
	sf::Vector2f m_forward = sf::Vector2f();



	void UpdateMovement();
	void UpdateInventoryInteractions();

};
