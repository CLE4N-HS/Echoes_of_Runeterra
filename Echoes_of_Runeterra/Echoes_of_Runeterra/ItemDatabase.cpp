#include "ItemDatabase.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"
#include "Resource.h"
#include "ComponentName.h"

std::list<Item*> ItemDatabase::m_item;

ItemDatabase::ItemDatabase()
{
	ReadWeaponDB("../Resources/Saves/weaponDB.txt");
	ReadArmorDB("../Resources/Saves/armorDB.txt");
	ReadConsumableDB("../Resources/Saves/consumableDB.txt");

	// Resource Database
	m_item.push_back(new Resource("wood"));
	m_item.push_back(new Resource("chicken"));
	m_item.push_back(new Resource("rice"));
	m_item.push_back(new Resource("masterDish"));
}

ItemDatabase::~ItemDatabase()
{
	for (auto& item : m_item)
	{
		delete item;
		m_item.erase(m_item.begin());
	}
	//for (size_t i = 0; i < m_item.size();)
	//{
	//	delete m_item[i];
	//	m_item.erase(m_item.begin());
	//}
}

Item* ItemDatabase::GetItem(std::string _name)
{
	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		if ((*it)->GetComponent<ComponentName>()->GetName() == _name)
		{
			return (*it);
		}
	}

	//for (auto& item : m_item)
	//{
	//	if (item->GetComponent<ComponentName>()->GetName() == _name)
	//	{
	//		return ItemDatabase::CreateNewItem(item);

	//		//if (Weapon* weapon = dynamic_cast<Weapon*>(item))
	//		//	return new Weapon(*weapon);
	//		//else if (Armor* armor = dynamic_cast<Armor*>(item))
	//		//	return new Armor(*armor);
	//		//else if (Consumable* consumable = dynamic_cast<Consumable*>(item))
	//		//	return new Consumable(*consumable);
	//	}

	//}
	//for (size_t i = 0; i < m_item.size(); i++)
	//{
	//	if (m_item[i]->GetComponent<ComponentName>()->GetName() == _name)
	//	{
	//		if (Weapon* weapon = dynamic_cast<Weapon*>(m_item[i]))
	//			return new Weapon(*weapon);
	//		else if (Armor* armor = dynamic_cast<Armor*>(m_item[i]))
	//			return new Armor(*armor);
	//		else if (Consumable* consumable = dynamic_cast<Consumable*>(m_item[i]))
	//			return new Consumable(*consumable);
	//	}
	//}

	return nullptr;

	//return m_item[_name];
}

Item* ItemDatabase::CreateNewItem(Item* _item)
{
	if (Weapon* weapon = dynamic_cast<Weapon*>(_item))
		return new Weapon(*weapon);
	else if (Armor* armor = dynamic_cast<Armor*>(_item))
		return new Armor(*armor);
	else if (Consumable* consumable = dynamic_cast<Consumable*>(_item))
		return new Consumable(*consumable);
	else if (Resource* resource = dynamic_cast<Resource*>(_item))
		return new Resource(*resource);

	return nullptr;
}

Item* ItemDatabase::CreateNewItem(const std::string& _name)
{
	return ItemDatabase::CreateNewItem(ItemDatabase::GetItem(_name));
}

void ItemDatabase::ReadWeaponDB(std::string _filePath)
{
	std::ifstream file(_filePath);

	if (file)
	{
		std::string tmpName;
		int tmpDamage(0);
		int tmpCriticalDamage(0);
		int tmpSpeed(0);

		while (file >> tmpName)
		{
			file >> tmpDamage;
			file >> tmpCriticalDamage;
			file >> tmpSpeed;

			
			m_item.push_back(new Weapon(tmpName, tmpDamage, tmpCriticalDamage, tmpSpeed));
			//m_item.insert({ tmpName, new Weapon(tmpName, tmpDamage, tmpCriticalDamage, tmpSpeed) });
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}

void ItemDatabase::ReadArmorDB(std::string _filePath)
{
	std::ifstream file(_filePath);

	if (file)
	{
		std::string tmpName;
		int tmpDefense(0);
		int tmpSpeed(0);
		int tmpDurability(0);

		while (file >> tmpName)
		{
			file >> tmpDefense;
			file >> tmpSpeed;
			file >> tmpDurability;

			m_item.push_back(new Armor(tmpName, tmpDefense, tmpSpeed, tmpDurability));
			//m_item.insert({ tmpName, new Armor(tmpName, tmpDefense, tmpSpeed, tmpDurability) });
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}

void ItemDatabase::ReadConsumableDB(std::string _filePath)
{
	std::ifstream file(_filePath);

	if (file)
	{
		std::string tmpName;
		int tmpHp(0);
		int tmpDefense(0);
		int tmpSpeed(0);

		while (file >> tmpName)
		{
			file >> tmpHp;
			file >> tmpDefense;
			file >> tmpSpeed;

			m_item.push_back(new Consumable(tmpName, tmpHp, tmpDefense, tmpSpeed));
			//m_item.insert({ tmpName, new Consumable(tmpName, tmpHp, tmpDefense, tmpSpeed) });
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}
