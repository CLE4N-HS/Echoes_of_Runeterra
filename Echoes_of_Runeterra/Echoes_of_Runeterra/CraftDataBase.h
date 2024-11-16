#pragma once
#include "tools.h"
#include "Item.h"

class CraftDatabase
{
public:
	struct CraftItem {

		// The Item obtained by the craft
		Item* item;

		// The list of required Item and their numbers
		std::vector<std::pair<Item*, int>> requiredItem;
	};

	CraftDatabase();
	~CraftDatabase();

	static void AddCraftItem(Item* _item, const std::vector<std::pair<Item*, int>>& _requiredItem);
	static void AddCraftItem(std::string _itemName, const std::vector<std::pair<std::string, int>>& _requiredItem);

	static Item* GetCraftItem(const std::vector<std::pair<Item*, int>>& _requiredItem);

	Item* getItem(std::string _name);
	Item* getItem(std::vector<Item*> _item);
	Item* getItem(std::vector<std::string> _names);

private:
	static std::list<CraftItem> m_craftItem;

	//std::list<std::pair<Item*, std::vector<Item*>>> m_database;

};
