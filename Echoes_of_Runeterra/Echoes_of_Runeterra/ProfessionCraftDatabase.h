#pragma once
#include "Tools.h"
#include "Profession.h"
#include "CraftDataBase.h"
#include "Item.h"

struct ProfessionCraft {
	// The profession name
	std::string profession;

	// The Craft Item
	CraftItem* craftItem;

	inline ProfessionCraft(const std::string& _profession, CraftItem* _craftItem) : profession(_profession), craftItem(_craftItem) {}
};

class ProfessionCraftDatabase
{
public:
	ProfessionCraftDatabase();
	~ProfessionCraftDatabase();

	static Item* CreateProfessionCraft(const std::vector<GameItem>& _item, const std::string& _profession);

private:
	static std::list<ProfessionCraft*> m_professionCraft;

};