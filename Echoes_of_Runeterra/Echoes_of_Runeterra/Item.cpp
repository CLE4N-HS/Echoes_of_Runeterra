#include "Item.h"
#include "textureManager.h"

Item::Item() : Item("")
{
}

Item::Item(std::string _name) :/* Entity(sf::Vector2f(randomFloat(100.f, 1700.f), randomFloat(100.f, 800.f))), */m_name(_name), m_state(Item::State::ON_MAP), m_isHovered(false)
{
	if (_name != "")
	{
		sf::IntRect animRect = tex_getAnimRect("items", m_name.c_str());
		m_size = sf::Vector2f((float)animRect.width, (float)animRect.height);
		m_origin = m_size * 0.5f;
		m_scale = sf::Vector2f(5.f, 5.f);
	}
}

Item::~Item()
{
}

void Item::update(Window& _window)
{
	sf::Vector2f mousePos = _window.getMousePos();

	sf::FloatRect itemRect = Item::getRect();

	if (m_state == Item::State::IN_INVENTORY)
	{
		if (itemRect.contains(mousePos))
		{
			m_isHovered = true;
		}
		else
		{
			m_isHovered = false;
		}
	}
	else if (m_state == Item::State::ON_MAP)
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

bool Item::isHovered()
{
	return m_isHovered;
}

Item* Item::getItem()
{
	return this;
}

std::string Item::getName()
{
	return m_name;
}

sf::FloatRect Item::getRect()
{
	return sf::FloatRect();
	//return sf::FloatRect(m_pos - vec2fMultiply(m_origin, m_scale), vec2fMultiply(m_size, m_scale));
}

void Item::setHover(bool _isHover)
{
	m_isHovered = _isHover;
}
