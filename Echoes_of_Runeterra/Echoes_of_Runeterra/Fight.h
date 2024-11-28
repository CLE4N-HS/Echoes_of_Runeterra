#pragma once
#include "Player.h"
#include "Enemy.h"
#include "FightState.h"

class Fight
{
public:
	Fight() = default;
	Fight(Player* _player, const std::vector<Enemy*>& _enemy);
	~Fight();

	void Update();
	void Display();

	void ChangeState(FightState* _state);

	inline void SetPlayer(Player* _player) { m_player = _player; }
	inline void SetEnemy(const std::vector<Enemy*>& _enemy) { m_enemy = _enemy; }

private:
	FightState* m_state = nullptr;

	Player* m_player = nullptr;
	std::vector<Enemy*> m_enemy = {};

	void DisplayPlayer();
	void DisplayStats(const sf::Vector2f& _pos, const sf::Vector2f& _size, const FightStats& _fightStats);
	void DisplayEnemies();

	void RepositionEnemies();

};
