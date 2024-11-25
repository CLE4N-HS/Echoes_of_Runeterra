#pragma once
#include "Tools.h"
#include "Item.h"

class ItemDatabase
{
public:
	ItemDatabase();
	~ItemDatabase();

	/// <summary>
	/// Gets a pointer to the Item if founded
	/// Use this only for a Database in order to not change the Item values
	/// </summary>
	static Item* GetItem(std::string _name);

	/// <summary>
	/// Creates a new Item without relation with the database
	/// </summary>
	static Item* CreateNewItem(Item* _item);
	static Item* CreateNewItem(const std::string& _name);

private:
	void ReadWeaponDB(std::string _filePath);
	void ReadArmorDB(std::string _filePath);
	void ReadConsumableDB(std::string _filePath);

	static std::list<Item*> m_item;

	//std::unordered_map<std::string, Item*> m_item;

};
