#pragma once
#include "Player.h"
#include "Enemy.h"

class Fight
{
public:
	Fight() = default;
	Fight(Player* _player, Enemy* _enemy); // TODO
	~Fight() = default;

	void Update();
	void Display();

	inline void SetPlayer(Player* _player) { m_player = _player; }
	inline void SetEnemy(Enemy* _enemy) { m_enemy = _enemy; }

private:
	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;

};
