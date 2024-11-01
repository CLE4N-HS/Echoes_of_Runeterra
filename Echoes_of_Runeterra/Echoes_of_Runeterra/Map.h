#pragma once
#include "Window.h"
#include "Item.h"

class Map
{
public:
	Map();
	~Map();

	void update(Window& _window);
	void display(Window& _window);

	void addItem(Item* _item);

private:
	std::list<Item*> m_item;

};
