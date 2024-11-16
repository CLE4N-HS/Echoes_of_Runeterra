#include "craftdbtest.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"


craftdbtest::craftdbtest() : m_database()
{
	//m_database.push_back({ _itemDB->getItem("goldenPickaxe"), std::vector<Item*>({_itemDB->getItem("sword"), _itemDB->getItem("pickaxe")}) });
}

craftdbtest::~craftdbtest()
{
}

Item* craftdbtest::getItem(std::string _name)
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

Item* craftdbtest::getItem(std::vector<Item*> _item)
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

Item* craftdbtest::getItem(std::vector<std::string> _names)
{
	for (std::list<std::pair<Item*, std::vector<Item*>>>::iterator it = m_database.begin(); it != m_database.end(); it++)
	{
		int correctItem(0);
		for (int i = 0; i < _names.size(); i++)
		{
			if (_names[i] != it->second[i]->getName())
				break;

			correctItem++;
		}

		if (correctItem > 0 && correctItem == _names.size())
		{
			return it->first;
		}
	}

	return nullptr;
}
