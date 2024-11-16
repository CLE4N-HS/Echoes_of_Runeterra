#pragma once
#include "Window.h"
#include "Entity.h"

class Item : public Entity
{
public:
	typedef enum {
		IN_INVENTORY,
		ON_MAP
	}State;

	Item();
	Item(std::string _name);
	~Item();

	virtual void Update() = 0;
	virtual void Display() = 0;
	virtual void displayStats(Window& _window) = 0;
	void setState(Item::State _state);
	Item::State getState();
	bool isHovered();
	sf::FloatRect getRect();
	void setHover(bool _isHover);

	bool operator== (Item* _item);

protected:

	Item::State m_state;
	bool m_isHovered;

	sf::Vector2f m_size;
	sf::Vector2f m_origin;
	sf::Vector2f m_scale;

private:

};
