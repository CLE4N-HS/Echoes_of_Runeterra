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

	void update(Window& _window);
	virtual void display(Window& _window) = 0;
	virtual void displayStats(Window& _window, sf::Vector2f _pos) = 0;
	void setState(Item::State _state);
	Item::State getState();
	bool shouldDisplayStats();
	sf::FloatRect getRect();

protected:
	std::string m_name;
	Item::State m_state;
	bool m_displayStats;

private:

};
