#pragma once
#include "tools.h"
#include "Item.h"

struct CraftItem {

	// The Item obtained by the craft
	Item* item;

	// The list of required Item
	std::vector<GameItem> requiredItem;

	inline CraftItem(Item* _item, const std::vector<GameItem>& _requiredItem = {}) : item(_item), requiredItem(_requiredItem) {}
	CraftItem(const std::string& _itemName, const std::vector<std::pair<std::string, int>>& _requiredItem);
};

class CraftDatabase
{
public:
	CraftDatabase();
	~CraftDatabase();

	static void AddCraftItem(const CraftItem& _craftItem);
	static void AddCraftItem(Item* _item, const std::vector<GameItem>& _requiredItem);
	static void AddCraftItem(std::string _itemName, const std::vector<std::pair<std::string, int>>& _requiredItem);

	static Item* GetCraftItem(const std::vector<GameItem>& _requiredItem);

	Item* getItem(std::string _name);
	Item* getItem(std::vector<Item*> _item);
	Item* getItem(std::vector<std::string> _names);

private:
	static std::list<CraftItem> m_craftItem;

	//std::list<std::pair<Item*, std::vector<Item*>>> m_database;

};
