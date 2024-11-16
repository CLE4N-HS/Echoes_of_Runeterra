#pragma once
#include "tools.h"
#include "ItemDatabase.h"
#include "Item.h"

class CraftDatabase
{
public:
	CraftDatabase();
	~CraftDatabase();

	Item* getItem(std::string _name);
	Item* getItem(std::vector<Item*> _item);
	Item* getItem(std::vector<std::string> _names);

private:
	//std::list<std::pair<Item*, std::vector<Item*>>> m_database;

};
