#pragma once
#include "Tools.h"
#include "Item.h"

class CraftManager
{
public:
	CraftManager();
	~CraftManager();

	static Item* Craft(std::vector<GameItem>& _item);
	static Item* Craft(std::vector<GameItem>& _item, const std::string& _profession);

	static bool IsCraftCorrect(const std::vector<GameItem>& _item);
	static bool IsCraftCorrect(const std::vector<GameItem>& _item, const std::string& _profession);

	Item* craft(std::vector<Item*> _item);
	Item* craft(std::vector<std::string> _itemName);

private:
	//CraftDataBase* m_craftDB;

};
