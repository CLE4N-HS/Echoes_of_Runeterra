#include "ItemDatabase.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"

ItemDataBase::ItemDataBase() : m_item()
{
	readWeaponDB("../Resources/Saves/weaponDB.txt");
	readArmorDB("../Resources/Saves/armorDB.txt");
	readConsumableDB("../Resources/Saves/consumableDB.txt");
}

ItemDataBase::~ItemDataBase()
{
}

void ItemDataBase::displayItems(Window& _window)
{
	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		(*it)->display(_window);
	}
}

void ItemDataBase::readWeaponDB(std::string _filePath)
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
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}

void ItemDataBase::readArmorDB(std::string _filePath)
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
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}

void ItemDataBase::readConsumableDB(std::string _filePath)
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
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}
