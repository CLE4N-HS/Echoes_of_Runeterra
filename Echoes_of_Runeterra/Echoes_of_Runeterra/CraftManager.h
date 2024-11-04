#pragma once
#include "Window.h"
#include "ItemDatabase.h"
#include "CraftDataBase.h"
#include "Item.h"

class CraftManager
{
public:
	CraftManager(ItemDataBase* _itemDB);
	~CraftManager();

	bool isCraftCorrect(std::vector<Item*> _item);
	Item* craft(std::vector<Item*> _item);
	Item* craft(std::vector<std::string> _itemName);

private:
	CraftDataBase* m_craftDB;

};
