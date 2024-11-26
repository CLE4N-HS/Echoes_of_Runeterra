#include "EnemyDatabase.h"
#include "ComponentName.h"
#include "WildCorruptedBeast.h"

std::list<Enemy*> EnemyDatabase::m_enemy;

EnemyDatabase::EnemyDatabase()
{
	this->AddEnemy("wildCorruptedBeast", new WildCorruptedBeast());
}

EnemyDatabase::~EnemyDatabase()
{
	while (m_enemy.size() > 0)
	{
		m_enemy.erase(m_enemy.end());
	}
}

Enemy* EnemyDatabase::GetEnemy(const std::string& _name)
{
	for (std::list<Enemy*>::iterator it = m_enemy.begin(); it != m_enemy.end(); it++)
	{
		if ((*it)->GetComponent<ComponentName>()->GetName() == _name)
		{
			return (*it);
		}
	}

	return nullptr;
}

Enemy* EnemyDatabase::CreateNewEnemy(Enemy* _enemy)
{
	if (WildCorruptedBeast* e = dynamic_cast<WildCorruptedBeast*>(_enemy))
		return e;

	return nullptr;
}

Enemy* EnemyDatabase::CreateNewEnemy(const std::string& _name)
{
	return EnemyDatabase::CreateNewEnemy(EnemyDatabase::GetEnemy(_name));
}

void EnemyDatabase::AddEnemy(const std::string& _name, Enemy* _enemy)
{
	m_enemy.push_back(_enemy);
	m_enemy.back()->GetComponent<ComponentName>()->SetName(_name);
}
