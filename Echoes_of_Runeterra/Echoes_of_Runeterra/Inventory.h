#pragma once
#include "Tools.h"
#include "Item.h"
#include "Entity.h"

class Inventory : public Entity
{
public:
	Inventory();
	~Inventory();

	void Update();
	void Display();

	void AddItem(const GameItem& _item);

	void addItem(Item* _item);
	Item* getItem();
	void EraseItem(Item* _item);

	void setOpening(bool _shouldBeOpened);
	bool isOpen();

private:
	void repositionItems();

	std::vector<GameItem> m_item;
	bool m_isOpen;

};
