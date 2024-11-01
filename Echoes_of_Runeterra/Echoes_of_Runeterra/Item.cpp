#include "Item.h"

Item::Item() : Item("Default Item Name")
{
}

Item::Item(std::string _name) : m_name(_name), m_state(Item::State::ON_MAP)
{
}

Item::~Item()
{
}

void Item::setState(Item::State _state)
{
	m_state = _state;
}

Item::State Item::getState()
{
	return m_state;
}
