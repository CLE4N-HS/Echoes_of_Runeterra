#include "Inventory.h"

Inventory::Inventory() : Entity(sf::Vector2f(100.f, 100.f)), m_item(), m_isOpen(false)
{
}

Inventory::~Inventory()
{
}

void Inventory::update(Window& _window)
{
	if (_window.keyboardManager.hasJustPressed(sf::Keyboard::I)) {
		m_isOpen = !m_isOpen;
	}

	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		(*it)->setHover(false);
		if (m_isOpen)
		{
			(*it)->update(_window);
		}
	}
}

void Inventory::display(Window& _window)
{
	if (m_isOpen)
	{
		_window.rectangle.setPosition(Inventory::m_pos);
		_window.rectangle.setOrigin(sf::Vector2f());
		_window.rectangle.setSize(sf::Vector2f(1720.f, 880.f));
		_window.rectangle.setFillColor(sf::Color(123, 63, 0, 200));
		_window.rectangle.setTexture(nullptr);

		_window.draw(_window.rectangle);

		_window.rectangle.setFillColor(sf::Color(255, 255, 255));
	}

	_window.text.setFillColor(sf::Color::White);
	_window.text.setCharacterSize(30);
	_window.text.setString((m_isOpen ? "I -> to close the Inventory" : "I -> to open the Inventory"));
	_window.text.setPosition(sf::Vector2f(10.f, 5.f));
	_window.draw(_window.text);


	if (m_isOpen)
	{
		for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
		{
			(*it)->display(_window);
		}
	}

}

void Inventory::addItem(Item* _item)
{
	_item->setState(Item::State::IN_INVENTORY);
	_item->setHover(false);
	_item->setPos(sf::Vector2f(Inventory::m_pos.x + 100.f + 200.f * m_item.size(), Inventory::m_pos.y + 500.f));
	m_item.push_back(_item);
}

Item* Inventory::takeItem()
{
	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		if ((*it)->isHovered())
		{
			Item* item = (*it)->getItem();
			it = m_item.erase(it);
			return item;
		}
	}

	return nullptr;
}

void Inventory::setOpening(bool _shouldBeOpened)
{
	m_isOpen = _shouldBeOpened;
}

bool Inventory::isOpen()
{
	return m_isOpen;
}
