#pragma once
#include "Enemy.h"

class EnemyDatabase
{
public:
	EnemyDatabase();
	~EnemyDatabase();

	Enemy* GetEnemy(const std::string& _name);

	Enemy* CreateNewEnemy(Enemy* _enemy);
	Enemy* CreateNewEnemy(const std::string& _name);

	void AddEnemy(const std::string& _name, Enemy* _enemy);

private:
	std::list<Enemy*> m_enemy;

};

