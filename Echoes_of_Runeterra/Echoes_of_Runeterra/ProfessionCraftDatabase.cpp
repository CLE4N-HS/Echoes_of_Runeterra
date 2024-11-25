#include "ProfessionCraftDatabase.h"
#include "ItemDatabase.h"

std::list<ProfessionCraft*> ProfessionCraftDatabase::m_professionCraft;

ProfessionCraftDatabase::ProfessionCraftDatabase()
{
	m_professionCraft.push_back(new ProfessionCraft("blacksmith", new CraftItem("goldenPickaxe", std::vector<std::pair<std::string, int>>({ {"sword", 2}, {"pickaxe", 1} }))));
	m_professionCraft.push_back(new ProfessionCraft("alchemist", new CraftItem("chicken", std::vector<std::pair<std::string, int>>({ {"wood", 1}, {"metalArmor", 2} }))));
	m_professionCraft.push_back(new ProfessionCraft("alchemist", new CraftItem("wood", std::vector<std::pair<std::string, int>>({ {"pickaxe", 1}, {"chicken", 2} }))));
}

ProfessionCraftDatabase::~ProfessionCraftDatabase()
{
	for (std::list<ProfessionCraft*>::iterator it = m_professionCraft.begin(); it != m_professionCraft.end();)
	{
		delete (*it);
		it = m_professionCraft.erase(it);
	}
}

ProfessionCraft* ProfessionCraftDatabase::IsCraftCorrect(const std::vector<GameItem>& _item, const std::string& _profession)
{
	Item* professionCraft = nullptr;
	for (std::list<ProfessionCraft*>::iterator it = m_professionCraft.begin(); it != m_professionCraft.end(); it++)
	{
		if ((*it)->profession == _profession)
		{

			if (_item.size() < (*it)->craftItem->requiredItem.size()) // not enough item for sure
			{
				continue;
			}

			size_t correctItemsNumber(0);
			for (size_t reqItem = 0; reqItem < _item.size(); reqItem++)
			{
				for (size_t item = 0; item < (*it)->craftItem->requiredItem.size(); item++)
				{
					if (_item[reqItem].item->operator==((*it)->craftItem->requiredItem[item]->item) &&	/* correct name     */
						_item[reqItem].quantity >= (*it)->craftItem->requiredItem[item]->quantity)		/* correct quantity */
					{
						correctItemsNumber++;
						break;
					}
				}
			}

			if (correctItemsNumber == (*it)->craftItem->requiredItem.size())
			{
				return (*it);
			}
		}
	}

	return nullptr;
}

Item* ProfessionCraftDatabase::CreateProfessionCraft(std::vector<GameItem>& _item, const std::string& _profession, ProfessionCraft* _professionCraft)
{
	for (size_t reqItem = 0; reqItem < _item.size(); reqItem++)
	{
		for (size_t item = 0; item < _professionCraft->craftItem->requiredItem.size(); item++)
		{
			if (_item[reqItem].item->operator==(_professionCraft->craftItem->requiredItem[item]->item))
			{
				_item[reqItem].quantity -= _professionCraft->craftItem->requiredItem[item]->quantity;
			}
		}
	}
	return ItemDatabase::CreateNewItem(_professionCraft->craftItem->item);
}

//bool ProfessionCraftDatabase::IsCraftCorrect(const std::vector<GameItem>& _item, const std::string& _profession)
//{
//	for (std::list<ProfessionCraft*>::iterator it = m_professionCraft.begin(); it != m_professionCraft.end(); it++)
//	{
//		if ((*it)->profession == _profession)
//		{
//
//			if (_item.size() < (*it)->craftItem->requiredItem.size()) // not enough item for sure
//			{
//				continue;
//			}
//
//			size_t correctItemsNumber(0);
//			for (size_t reqItem = 0; reqItem < _item.size(); reqItem++)
//			{
//				for (size_t item = 0; item < (*it)->craftItem->requiredItem.size(); item++)
//				{
//					if (_item[reqItem].item->operator==((*it)->craftItem->requiredItem[item]->item) &&	/* correct name     */
//						_item[reqItem].quantity >= (*it)->craftItem->requiredItem[item]->quantity)		/* correct quantity */
//					{
//						correctItemsNumber++;
//						break;
//					}
//				}
//			}
//
//			if (correctItemsNumber == (*it)->craftItem->requiredItem.size())
//			{
//				return true;
//			}
//		}
//	}
//
//	return false;
//}
