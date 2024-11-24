#include "CraftManager.h"
#include "CraftDataBase.h"
#include "ProfessionCraftDatabase.h"

CraftManager::CraftManager()
{
	//m_craftDB = new CraftDataBase(_itemDB);

	//Item* goldenPickaxe = m_craftDB->getItem(std::vector<std::string>({ "sword", "pickaxe" }));
}

CraftManager::~CraftManager()
{
}

Item* CraftManager::Craft(std::vector<GameItem>& _item)
{
	if (CraftItem* craftItem = CraftDatabase::IsCraftCorrect(_item))
		return CraftDatabase::CreateCraftItem(_item, craftItem);

	return nullptr;
	//return CraftDatabase::CreateCraftItem(_item);
}

Item* CraftManager::Craft(std::vector<GameItem>& _item, const std::string& _profession)
{
	if (Item* item = Craft(_item))
		return item;

	if (ProfessionCraft* professionCraft = ProfessionCraftDatabase::IsCraftCorrect(_item, _profession))
		return ProfessionCraftDatabase::CreateProfessionCraft(_item, _profession, professionCraft);

	return nullptr;
	//if (CraftItem* craftItem = CraftDatabase::IsCraftCorrect(_item))
	//	return CraftDatabase::CreateCraftItem(_item, craftItem);

	//return nullptr;

	//Item* item = nullptr;
	//item = ProfessionCraftDatabase::CreateProfessionCraft(_item, _profession);

	////if (item == nullptr) // if the craft wasn't link to a profession
	////	item = Craft(_item);

	//return item;
}

bool CraftManager::IsCraftCorrect(const std::vector<GameItem>& _item)
{
	return (CraftDatabase::IsCraftCorrect(_item));
	//return (m_craftDB->getItem(_item) != nullptr);
}

bool CraftManager::IsCraftCorrect(const std::vector<GameItem>& _item, const std::string& _profession)
{
	return (CraftDatabase::IsCraftCorrect(_item) || ProfessionCraftDatabase::IsCraftCorrect(_item, _profession));
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
