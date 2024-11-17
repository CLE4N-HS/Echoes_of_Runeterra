#include "ProfessionCraftDatabase.h"
#include "ItemDatabase.h"

std::list<ProfessionCraft*> ProfessionCraftDatabase::m_professionCraft;

ProfessionCraftDatabase::ProfessionCraftDatabase()
{
	m_professionCraft.push_back(new ProfessionCraft("balcksmith", new CraftItem("goldenPickaxe", std::vector<std::pair<std::string, int>>({ {"sword", 2}, {"pickaxe", 1} }))));
	m_professionCraft.push_back(new ProfessionCraft("alchemist", new CraftItem("holyBook", std::vector<std::pair<std::string, int>>({ {"sword", 1}, {"pickaxe", 2} }))));
}

ProfessionCraftDatabase::~ProfessionCraftDatabase()
{
	for (std::list<ProfessionCraft*>::iterator it = m_professionCraft.begin(); it != m_professionCraft.end();)
	{
		delete (*it);
		it = m_professionCraft.erase(it);
	}
}

Item* ProfessionCraftDatabase::CreateProfessionCraft(const std::vector<GameItem>& _item, std::string _profession)
{
	Item* professionCraft = nullptr;
	for (std::list<ProfessionCraft*>::iterator it = m_professionCraft.begin(); it != m_professionCraft.end(); it++)
	{
		if ((*it)->profession == _profession)
		{
			// TODO call the algorithm not this
			//professionCraft = CraftDatabase::CreateCraftItem(_item);
		}
	}

	return professionCraft;
}
