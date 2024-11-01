#pragma once
#include "Window.h"
#include "ItemDatabase.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void update(Window& _window);
	void display(Window& _window);

	void setOpening(bool _shouldBeOpened);
	bool isOpen();

private:
	ItemDataBase* m_itemDB;
	bool m_isOpen;

};
