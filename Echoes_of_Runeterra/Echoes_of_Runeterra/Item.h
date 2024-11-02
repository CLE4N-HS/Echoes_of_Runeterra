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

	virtual void update(Window& _window) = 0;
	virtual void display(Window& _window) = 0;
	virtual void displayStats(Window& _window) = 0;
	void setState(Item::State _state);
	Item::State getState();

protected:
	sf::FloatRect getRect();

	std::string m_name;
	Item::State m_state;
	bool m_isHovered;

private:

};
