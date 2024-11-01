#include "Item.h"

Item::Item() : Item("Default Item Name")
{
}

Item::Item(std::string _name) : m_name(_name), m_state(Item::State::ON_GROUND)
{
}

Item::~Item()
{
}

Item::State Item::getState()
{
	return m_state;
}
