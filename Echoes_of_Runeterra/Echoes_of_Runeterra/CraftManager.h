#pragma once
#include "Window.h"
#include "CraftDataBase.h"
#include "Item.h"

class CraftManager
{
public:
	CraftManager();
	~CraftManager();

	bool isCraftCorrect(std::vector<Item*> _item);
	Item* craft(std::vector<Item*> _item);

private:
	CraftDataBase* m_craftDB;

};