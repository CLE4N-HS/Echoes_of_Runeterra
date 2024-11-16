#include "DatabaseManager.h"
#include "ItemDatabase.h"
#include "CraftDataBase.h"

DatabaseManager databaseManager;

void DatabaseManager::loadAllDatabase()
{
	new ItemDatabase();
	new CraftDatabase();
	//ItemDatabase* itemDatabase = new ItemDatabase();
	//CraftDatabase* craftDatabase = new CraftDatabase();
}
