#pragma once
#include "Window.h"

class Item
{
public:
	typedef enum {
		IN_INVENTORY,
		ON_MAP
	}State;

	Item();
	Item(std::string _name);
	~Item();

	virtual void display(Window& _window) = 0;
	void setState(Item::State _state);
	Item::State getState();

protected:
	std::string m_name;
	Item::State m_state;

private:

};
