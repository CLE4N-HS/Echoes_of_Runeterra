#pragma once
#include "tools.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"

class ItemDataBase
{
public:
	ItemDataBase();
	~ItemDataBase();

private:
	void readWeaponDB(std::string _filePath);

	std::map<std::string, Weapon> m_weaponDB;
	std::map<std::string, Armor> m_armorDB;
	std::map<std::string, Consumable> m_consumableDB;

};
