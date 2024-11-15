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

	void addItem(Item* _item);
	Item* getItem();
	void eraseItem(Item* _item);

	void setOpening(bool _shouldBeOpened);
	bool isOpen();

private:
	void repositionItems();

	std::list<Item*> m_item;
	bool m_isOpen;

};
