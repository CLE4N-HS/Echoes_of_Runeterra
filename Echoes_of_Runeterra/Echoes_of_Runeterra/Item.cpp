#include "Item.h"
#include "textureManager.h"

Item::Item() : Item("Default Item Name")
{
}

Item::Item(std::string _name) : m_name(_name), m_state(Item::State::ON_MAP), m_displayStats(false)
{
}

Item::~Item()
{
}

void Item::update(Window& _window)
{
	if (_window.getMousePos().x > 960.f)
	{
		m_displayStats = true;
	}
	else
		m_displayStats = false;
}

void Item::setState(Item::State _state)
{
	m_state = _state;
}

Item::State Item::getState()
{
	return m_state;
}

bool Item::shouldDisplayStats()
{
	return m_displayStats;
}

sf::FloatRect Item::getRect()
{
	// TODO ENTITY
	sf::IntRect tmpRect = tex_getAnimRect("items", m_name.c_str());
	return sf::FloatRect(sf::Vector2f(500.f, 700.f), sf::Vector2f((float)(tmpRect.width), (float)(tmpRect.height)));
}
