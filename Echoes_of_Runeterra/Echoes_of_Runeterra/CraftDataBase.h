#pragma once
#include "tools.h"
#include "Item.h"

class CraftDataBase
{
public:
	CraftDataBase();
	~CraftDataBase();

	Item* getItem(std::string _name);
	Item* getItem(std::vector<Item*> _item);

private:
	std::list<std::pair<Item*, std::vector<Item*>>> m_database;

};
