#pragma once
#include "Enemy.h"

class EnemyDatabase
{
public:
	EnemyDatabase();
	~EnemyDatabase();

	static Enemy* GetEnemy(const std::string& _name);

	static Enemy* CreateNewEnemy(Enemy* _enemy);
	static Enemy* CreateNewEnemy(const std::string& _name);

	static void AddEnemy(const std::string& _name, Enemy* _enemy);

private:
	static std::list<Enemy*> m_enemy;

};

