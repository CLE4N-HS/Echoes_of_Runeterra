#pragma once
#include "Tools.h"
#include "Database.h"

class DatabaseManager
{
public:
	DatabaseManager() = default;
	~DatabaseManager() = default;

	/// <summary>
	/// Loads all static Database in the right order
	/// </summary>
	static void loadAllDatabase();

private:

};
