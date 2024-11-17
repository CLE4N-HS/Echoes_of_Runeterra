#include "CraftDataBase.h"
#include "ItemDatabase.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"
#include "ComponentName.h"

std::list<CraftItem*> CraftDatabase::m_craftItem;

CraftDatabase::CraftDatabase() // : m_database()
{
	this->AddCraftItem(
		ItemDatabase::GetItem("goldenPickaxe"),
		std::vector<GameItem*>({
			{ new GameItem(ItemDatabase::GetItem("sword"), 1) },
			{ new GameItem(ItemDatabase::GetItem("pickaxe"), 2) }
		}));
	// same thing
	this->AddCraftItem("goldenPickaxe", std::vector<std::pair<std::string, int>>({ { "sword", 1 }, { "pickaxe", 2 } }));


	//m_database.push_back({_itemDB->getItem("goldenPickaxe"), std::vector<Item*>({_itemDB->getItem("sword"), _itemDB->getItem("pickaxe")}) });
}

CraftDatabase::~CraftDatabase()
{
	// TODO

	//for (auto& craftItem : m_craftItem)
	//{
	//	delete craftItem.item;
	//	for (size_t i = 0; i < craftItem.requiredItem.size();)
	//	{
	//		delete craftItem.requiredItem.begin()->item;
	//		craftItem.requiredItem.erase(craftItem.requiredItem.begin());
	//	}
	//	m_craftItem.erase(m_craftItem.begin());
	//}
}

void CraftDatabase::AddCraftItem(const CraftItem& _craftItem)
{
	m_craftItem.push_back(new CraftItem(_craftItem));
	//m_craftItem.push_back(_craftItem);
}

void CraftDatabase::AddCraftItem(Item* _item, const std::vector<GameItem*>& _requiredItem)
{
	m_craftItem.push_back(new CraftItem(_item, _requiredItem));
	//CraftItem craftItem{ _item, _requiredItem };
	//m_craftItem.push_back(craftItem);
}

void CraftDatabase::AddCraftItem(std::string _itemName, const std::vector<std::pair<std::string, int>>& _requiredItem)
{
	CraftItem craftItem(ItemDatabase::GetItem(_itemName));
	for (size_t i = 0; i < _requiredItem.size(); i++)
	{
		craftItem.requiredItem.push_back({new GameItem( ItemDatabase::GetItem(_requiredItem[i].first), _requiredItem[i].second) });
	}
	m_craftItem.push_back(new CraftItem(craftItem));
}

Item* CraftDatabase::CreateCraftItem(const std::vector<GameItem>& _requiredItem)
{
	Item* craftItem = nullptr;
	for (std::list<CraftItem*>::iterator it = m_craftItem.begin(); it != m_craftItem.end(); it++)
	{
		if (_requiredItem.size() < (*it)->requiredItem.size()) // not enough item for sure
		{
			continue;
		}

		size_t correctItemsNumber(0);
		for (size_t reqItem = 0; reqItem < _requiredItem.size(); reqItem++)
		{
			for (size_t item = 0; item < (*it)->requiredItem.size(); item++)
			{
				if (_requiredItem[reqItem].item->operator==((*it)->requiredItem[item]->item) &&	/* correct name     */
					_requiredItem[reqItem].quantity >= (*it)->requiredItem[item]->quantity)		/* correct quantity */
				{
					correctItemsNumber++;
					break;
				}
			}
		}

		if (correctItemsNumber == (*it)->requiredItem.size())
		{
			// TODO don't we have this already ??
			craftItem = ItemDatabase::CreateNewItem((*it)->item);
			break;
		}

	}

	return craftItem;
}

Item* CraftDatabase::getItem(std::string _name)
{
	//for (std::list<std::pair<Item*, std::vector<Item*>>>::iterator it = m_database.begin(); it != m_database.end(); it++)
	//{
	//	if (_name == it->first->getName())
	//	{
	//		return it->first;
	//	}
	//}
	return nullptr;
}

Item* CraftDatabase::getItem(std::vector<Item*> _item)
{
	//for (std::list<std::pair<Item*, std::vector<Item*>>>::iterator it = m_database.begin(); it != m_database.end(); it++)
	//{
	//	int correctItem(0);
	//	for (int i = 0; i < _item.size(); i++)
	//	{
	//		if (_item[i] != it->second[i])
	//			break;

	//		correctItem++;
	//	}

	//	if (correctItem > 0 && correctItem == _item.size())
	//	{
	//		return it->first;
	//	}
	//}

	return nullptr;
}

Item* CraftDatabase::getItem(std::vector<std::string> _names)
{
	//for (std::list<std::pair<Item*, std::vector<Item*>>>::iterator it = m_database.begin(); it != m_database.end(); it++)
	//{
	//	int correctItem(0);
	//	for (int i = 0; i < _names.size(); i++)
	//	{
	//		if (_names[i] != it->second[i]->getName())
	//			break;

	//		correctItem++;
	//	}

	//	if (correctItem > 0 && correctItem == _names.size())
	//	{
	//		return it->first;
	//	}
	//}

	return nullptr;
}

CraftItem::CraftItem(const std::string& _itemName, const std::vector<std::pair<std::string, int>>& _requiredItem) : item(ItemDatabase::GetItem(_itemName))
{
	for (size_t i = 0; i < _requiredItem.size(); i++)
	{
		requiredItem.push_back(new GameItem(ItemDatabase::GetItem(_requiredItem[i].first), _requiredItem[i].second));
	}
}
