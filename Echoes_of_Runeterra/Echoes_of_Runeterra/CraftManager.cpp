#include "CraftManager.h"

CraftManager::CraftManager()
{
}

CraftManager::~CraftManager()
{
}

bool CraftManager::isCraftCorrect(std::vector<Item*> _item)
{
	return (m_craftDB->getItem(_item) != nullptr);
}

Item* CraftManager::craft(std::vector<Item*> _item)
{
	return m_craftDB->getItem(_item);
}
