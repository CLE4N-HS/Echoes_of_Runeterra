#include "DatabaseManager.h"
#include "ItemDatabase.h"
#include "CraftDataBase.h"
#include "ProfessionCraftDatabase.h"

DatabaseManager databaseManager;

void DatabaseManager::loadAllDatabase()
{
	new ItemDatabase();
	new CraftDatabase();
	new ProfessionCraftDatabase();
	//ItemDatabase* itemDatabase = new ItemDatabase();
	//CraftDatabase* craftDatabase = new CraftDatabase();
}
