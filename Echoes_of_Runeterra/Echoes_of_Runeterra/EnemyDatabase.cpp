#include "EnemyDatabase.h"
#include "ComponentName.h"
#include "WildCorruptedBeast.h"
#include "SpiritWolf.h"
#include "RiverSerpent.h"

std::list<Enemy*> EnemyDatabase::m_enemy;

EnemyDatabase::EnemyDatabase()
{
	this->AddEnemy("wildCorruptedBeast", new WildCorruptedBeast());
	this->AddEnemy("spiritWolf", new SpiritWolf());
	this->AddEnemy("riverSerpent", new RiverSerpent());
}

EnemyDatabase::~EnemyDatabase()
{
	while (m_enemy.size() > 0)
	{
		m_enemy.erase(m_enemy.begin());
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
		return new WildCorruptedBeast(*e);
	if (SpiritWolf* e = dynamic_cast<SpiritWolf*>(_enemy))
		return new SpiritWolf(*e);
	if (RiverSerpent* e = dynamic_cast<RiverSerpent*>(_enemy))
		return new RiverSerpent(*e);

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
