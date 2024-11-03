#include "CraftDataBase.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"

CraftDataBase::CraftDataBase() : m_database()
{
	m_database.push_back({new Weapon("Hammer", 5, 5, 5), std::vector<Item*>({ new Weapon(), new Weapon() }) });
}

CraftDataBase::~CraftDataBase()
{
}

Item* CraftDataBase::getItem(std::string _name)
{
	for (std::list<std::pair<Item*, std::vector<Item*>>>::iterator it = m_database.begin(); it != m_database.end(); it++)
	{
		if (_name == it->first->getName())
		{
			return it->first;
		}
	}
	return nullptr;
}

Item* CraftDataBase::getItem(std::vector<Item*> _item)
{
	for (std::list<std::pair<Item*, std::vector<Item*>>>::iterator it = m_database.begin(); it != m_database.end(); it++)
	{
		int correctItem(0);
		for (int i = 0; i < _item.size(); i++)
		{
			if (_item[i] != it->second[i])
				break;

			correctItem++;
		}

		if (correctItem > 0 && correctItem == _item.size())
		{
			return it->first;
		}
	}

	return nullptr;
}
