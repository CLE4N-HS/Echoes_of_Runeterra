#pragma once
#include "Window.h"
#include "Item.h"

class ItemDataBase
{
public:
	ItemDataBase();
	~ItemDataBase();

	void displayItems(Window& _window);

private:
	void readWeaponDB(std::string _filePath);
	void readArmorDB(std::string _filePath);
	void readConsumableDB(std::string _filePath);

	std::list<Item*> m_item;

};
