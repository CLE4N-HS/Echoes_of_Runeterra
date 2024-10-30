#include "ItemDatabase.h"

ItemDataBase::ItemDataBase() : m_weaponDB()
{
	readWeaponDB("../Resources/Saves/weaponDB.txt");
}

ItemDataBase::~ItemDataBase()
{
}

void ItemDataBase::readWeaponDB(std::string _filePath)
{
	std::ifstream file(_filePath);

	if (file)
	{
		std::string tmpName;
		int tmpDamage(0);
		int tmpCriticalDamage(0);
		int tmpSpeed(0);

		while (file >> tmpName)
		{
			file >> tmpDamage;
			file >> tmpCriticalDamage;
			file >> tmpSpeed;

			m_weaponDB.insert({ tmpName, Weapon(tmpName, tmpDamage, tmpCriticalDamage, tmpSpeed) });
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}
