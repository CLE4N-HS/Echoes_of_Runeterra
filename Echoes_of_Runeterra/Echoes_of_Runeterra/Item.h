#pragma once
#include "Window.h"

class Item
{
public:
	typedef enum {
		IN_INVENTORY,
		ON_GROUND
	}State;

	Item();
	Item(std::string _name);
	~Item();

	virtual void display(Window& _window) = 0;
	Item::State getState();

protected:
	std::string m_name;
	Item::State m_state;

private:

};
