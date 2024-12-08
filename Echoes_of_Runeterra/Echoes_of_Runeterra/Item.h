#pragma once
#include "Tools.h"
#include "Entity.h"

class Item : public Entity
{
public:
	enum State {
		IN_INVENTORY,
		ON_MAP
	};

	Item();
	Item(std::string _name);
	~Item();

	virtual void Update() = 0;
	virtual void Display() = 0;

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

struct GameItem {
	Item* item;
	int quantity;
	inline GameItem(Item* _item, int _quantity = 1) : item(_item), quantity(_quantity) {}
	inline GameItem(GameItem* _gameItem) : GameItem(_gameItem->item, _gameItem->quantity) {}
};
