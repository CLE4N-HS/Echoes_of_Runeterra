#pragma once
#include "Window.h"
#include "Item.h"
#include <unordered_map>

class ItemDataBase
{
public:
	ItemDataBase();
	~ItemDataBase();

	// This function removes the item from the DataBase
	Item* takeItem(std::string _name);

private:
	void readWeaponDB(std::string _filePath);
	void readArmorDB(std::string _filePath);
	void readConsumableDB(std::string _filePath);

	std::unordered_map<std::string, Item*> m_item;

};
