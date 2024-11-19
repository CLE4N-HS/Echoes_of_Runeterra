#include "DatabaseManager.h"
#include "ItemDatabase.h"
#include "CraftDataBase.h"
#include "ProfessionCraftDatabase.h"
#include "SkillsDataBase.h"
#include "TreeDataBase.h"
#include "DialogueDataBase.h"

DatabaseManager databaseManager;

void DatabaseManager::loadAllDatabase()
{
	new ItemDatabase();
	new CraftDatabase();
	new ProfessionCraftDatabase();
	new SkillsDataBase();
	new TreeDataBase();
	new DialogueDataBase();
}
