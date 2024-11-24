#pragma once
#include "Tools.h"
#include "Item.h"
#include "Entity.h"

struct InventoryItem {
	GameItem gameItem;
	bool isSelected;
	inline InventoryItem(const GameItem& _gameItem) : gameItem(_gameItem), isSelected(false) {}
};

struct InventoryButton {
	Transform transform;
	sf::String string;
	bool isClickable;
	inline InventoryButton(const Transform& _transform, const sf::String& _string) : transform(_transform), string(_string), isClickable(false) {}
};

class Inventory : public Entity
{
public:
	Inventory();
	~Inventory();

	void Update();
	void Display();

	void AddItem(const GameItem& _item);

	Item* getItem();
	void RemoveItem(Item* _item, int _quantity = 1, bool _delete = false);
	void EraseItem(Item* _item);

	void setOpening(bool _shouldBeOpened);
	bool isOpen();

private:
	void RepositionItems();
	void UnselectItems();

	void UpdateButton();
	void DisplayButton();

	std::vector<InventoryItem> m_item;
	std::vector<InventoryButton> m_button;
	bool m_isOpen;
	bool m_isInDatabase = false;

};
