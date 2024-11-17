#include "DatabaseManager.h"
#include "ItemDatabase.h"
#include "CraftDataBase.h"
#include "ProfessionCraftDatabase.h"

#include "TreeDataBase.h"

DatabaseManager databaseManager;

void DatabaseManager::loadAllDatabase()
{
	new ItemDatabase();
	new CraftDatabase();
	new ProfessionCraftDatabase();
	// TODO Skills
	new TreeDataBase();
}
