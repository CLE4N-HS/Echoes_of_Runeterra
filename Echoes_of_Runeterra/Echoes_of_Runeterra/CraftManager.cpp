#include "CraftManager.h"

CraftManager::CraftManager()
{
	//m_craftDB = new CraftDataBase(_itemDB);

	//Item* goldenPickaxe = m_craftDB->getItem(std::vector<std::string>({ "sword", "pickaxe" }));
}

CraftManager::~CraftManager()
{
}

bool CraftManager::isCraftCorrect(std::vector<Item*> _item)
{
	return false;
	//return (m_craftDB->getItem(_item) != nullptr);
}

Item* CraftManager::craft(std::vector<Item*> _item)
{
	return nullptr;
	//return m_craftDB->getItem(_item);
}

Item* CraftManager::craft(std::vector<std::string> _itemName)
{
	return nullptr;
	//return m_craftDB->getItem(_itemName);
}
