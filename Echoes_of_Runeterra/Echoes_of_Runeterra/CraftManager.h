#pragma once
#include "Tools.h"
#include "Item.h"

class CraftManager
{
public:
	CraftManager();
	~CraftManager();

	static Item* Craft(std::vector<GameItem>& _item);
	// TODO Craft with Profession

	bool isCraftCorrect(std::vector<Item*> _item);
	Item* craft(std::vector<Item*> _item);
	Item* craft(std::vector<std::string> _itemName);

private:
	//CraftDataBase* m_craftDB;

};
