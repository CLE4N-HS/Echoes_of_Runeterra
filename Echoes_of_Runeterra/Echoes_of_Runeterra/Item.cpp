#include "Item.h"
#include "textureManager.h"

Item::Item() : Item("Default Item Name")
{
}

Item::Item(std::string _name) : m_name(_name), m_state(Item::State::ON_MAP), m_isHovered(false)
{
}

Item::~Item()
{
}

void Item::update(Window& _window)
{
	sf::Vector2f mousePos = _window.getMousePos();

	sf::FloatRect itemRect = Item::getRect();

	if (itemRect.contains(mousePos))
	{
		m_isHovered = true;
	}
	else
	{
		m_isHovered = false;
	}
}

void Item::setState(Item::State _state)
{
	m_state = _state;
}

Item::State Item::getState()
{
	return m_state;
}

sf::FloatRect Item::getRect()
{
	// TODO ENTITY
	sf::IntRect tmpRect = tex_getAnimRect("items", m_name.c_str());
	return sf::FloatRect(sf::Vector2f(500.f, 700.f), sf::Vector2f((float)(tmpRect.width), (float)(tmpRect.height)));
}
