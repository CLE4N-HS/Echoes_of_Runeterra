#pragma once
#include "Tools.h"
#include "Item.h"

class ItemDatabase
{
public:
	ItemDatabase();
	~ItemDatabase();

	static Item* GetItem(std::string _name);

	/// <summary>
	/// Creates a new Item without relation with the database
	/// </summary>
	static Item* CreateNewItem(Item* _item);

private:
	void ReadWeaponDB(std::string _filePath);
	void ReadArmorDB(std::string _filePath);
	void ReadConsumableDB(std::string _filePath);

	static std::list<Item*> m_item;

	//std::unordered_map<std::string, Item*> m_item;

};
