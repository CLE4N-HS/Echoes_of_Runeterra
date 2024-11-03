#pragma once
#include "Window.h"
#include "Item.h"
#include "Entity.h"

class Inventory : public Entity
{
public:
	Inventory();
	~Inventory();

	void update(Window& _window);
	void display(Window& _window);

	void addItem(Item* _item);
	Item* takeItem();

	void setOpening(bool _shouldBeOpened);
	bool isOpen();

private:
	std::list<Item*> m_item;
	bool m_isOpen;

};
