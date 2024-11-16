#include "ProfessionCraftDatabase.h"
#include "ItemDatabase.h"

std::list<ProfessionCraft> ProfessionCraftDatabase::m_professionCraft;

ProfessionCraftDatabase::ProfessionCraftDatabase()
{
	m_professionCraft.push_back(ProfessionCraft("balcksmith", CraftItem("goldenPickaxe", std::vector<std::pair<std::string, int>>({ {"sword", 2}, {"pickaxe", 1} }))));
}

ProfessionCraftDatabase::~ProfessionCraftDatabase()
{
	for (std::list<ProfessionCraft>::iterator it = m_professionCraft.begin(); it != m_professionCraft.end();)
	{
		it = m_professionCraft.erase(it);
	}
}
