#pragma once
#include "Tools.h"
#include "Item.h"

class ItemDatabase
{
public:
	ItemDatabase();
	~ItemDatabase();

	static Item* GetItem(std::string _name);

private:
	void ReadWeaponDB(std::string _filePath);
	void ReadArmorDB(std::string _filePath);
	void ReadConsumableDB(std::string _filePath);

	static std::vector<Item*> m_item;

	//std::unordered_map<std::string, Item*> m_item;

};
