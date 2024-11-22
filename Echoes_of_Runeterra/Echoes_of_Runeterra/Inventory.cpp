#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "CraftManager.h"
#include "Window.h"
#include "KeyboardManager.h"

Inventory::Inventory() : Entity(Transform(sf::Vector2f(100.f, 100.f), sf::Vector2f(1720.f, 880.f), Transform::Origin::TOP_LEFT)), m_item(), m_isOpen(false)
{
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	if (KeyboardManager::OneTimePressed(sf::Keyboard::I))
	{
		m_isOpen = !m_isOpen;
	}

	for (std::vector<GameItem>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		it->item->setHover(false);
		if (m_isOpen)
		{
			it->item->Update();
		}
	}

	//Item* craftedItem = CraftManager::Craft(m_item);
	//Item* professionCraft = CraftManager::Craft(m_item, "blacksmith");
	//Item* professionCraft2 = CraftManager::Craft(m_item, "alchemist");

	//if (_window.keyboardManager.hasJustPressed(sf::Keyboard::I)) {
	//	m_isOpen = !m_isOpen;
	//}

	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	(*it)->setHover(false);
	//	if (m_isOpen)
	//	{
	//		(*it)->update(_window);
	//	}
	//}
}

void Inventory::Display()
{
	if (m_isOpen)
	{
		transform->CorrectWindowRectangle();
		Window::rectangle.setFillColor(sf::Color(123, 63, 0, 200));
		Window::Draw();

		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
	}

	Window::text.setFillColor(sf::Color::White);
	Window::text.setCharacterSize(30);
	Window::text.setString((m_isOpen ? "I -> to close the Inventory" : "I -> to open the Inventory"));
	Window::text.setPosition(sf::Vector2f(10.f, 5.f));
	Window::Draw(Window::text);

	if (m_isOpen)
	{
		for (std::vector<GameItem>::iterator it = m_item.begin(); it != m_item.end(); it++)
		{
			it->item->Display();
		}

		// TODO store all of this
		sf::Vector2f tmpSize(200.f, 100.f);
		for (int i = 0; i < 2; i++)
		{
			sf::FloatRect tmpRect(transform->getPos().x + 20.f + static_cast<float>(i) * tmpSize.x * 1.2f, transform->getPos().y + 20.f, tmpSize.x, tmpSize.y);

			sf::String tmpString;
			switch (i)
			{
			case 0:
				tmpString = "Craft"; break;
			case 1:
				tmpString = "\nCraft\n"; break;
			default:
				break;
			}

			Window::rectangle.setFillColor(sf::Color::White);
			Window::rectangle.setPosition(tmpRect.getPosition());
			Window::rectangle.setSize(tmpRect.getSize());
			Window::rectangle.setOrigin(sf::Vector2f());
			Window::rectangle.setScale(sf::Vector2f(1.f, 1.f));
			Window::Draw();

			Window::text.setFillColor(sf::Color(123, 63, 0, 200));
			Window::text.setString(tmpString);
			Window::text.setPosition(tmpRect.getPosition() + tmpRect.getSize() * 0.5f);
			Window::text.setCharacterSize(30);
			Tools::CenterTextOrigin(Window::text);
			Window::Draw(Window::text);

			if (i == 1)
			{
				Window::text.setString("\nDatabase");
				Tools::CenterTextOrigin(Window::text);
				Window::Draw(Window::text);
			}
			
			Window::text.setFillColor(sf::Color(255, 255, 255));
		}

	}
	 
	//if (m_isOpen)
	//{
	//	_window.rectangle.setPosition(Inventory::m_pos);
	//	_window.rectangle.setOrigin(sf::Vector2f());
	//	_window.rectangle.setSize(sf::Vector2f(1720.f, 880.f));
	//	_window.rectangle.setFillColor(sf::Color(123, 63, 0, 200));
	//	_window.rectangle.setTexture(nullptr);

	//	_window.draw(_window.rectangle);

	//	_window.rectangle.setFillColor(sf::Color(255, 255, 255));
	//}

	//_window.text.setFillColor(sf::Color::White);
	//_window.text.setCharacterSize(30);
	//_window.text.setString((m_isOpen ? "I -> to close the Inventory" : "I -> to open the Inventory"));
	//_window.text.setPosition(sf::Vector2f(10.f, 5.f));
	//_window.draw(_window.text);


	//if (m_isOpen)
	//{
	//	for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//	{
	//		(*it)->display(_window);
	//	}
	//}

}

void Inventory::AddItem(const GameItem& _item)
{
	bool haveAlready(false);
	for (size_t i = 0; i < m_item.size(); i++)
	{
		if (_item.item == m_item[i].item)
		{
			m_item[i].quantity += _item.quantity;
			haveAlready = true;
			break;
		}
	}

	if (!haveAlready)
	{
		m_item.push_back(_item);
	}
}

void Inventory::addItem(Item* _item)
{
	_item->setState(Item::State::IN_INVENTORY);
	_item->setHover(false);
	m_item.push_back(_item);

	repositionItems();
}

Item* Inventory::getItem()
{
	for (size_t i = 0; i < m_item.size(); i++)
	{
		// TODO
	}

	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	if ((*it)->isHovered()
	//		|| 1) // TODO not
	//	{
	//		if (Armor* armor = dynamic_cast<Armor*>(*it))
	//			return new Armor(*armor);
	//		if (Weapon* weapon = dynamic_cast<Weapon*>(*it))
	//		{
	//			return new Weapon(*weapon);
	//		}
	//		return (*it);
	//		return (*it)->Item::getItem();
	//	}
	//}

	return nullptr;
}

void Inventory::EraseItem(Item* _item)
{
	for (size_t i = 0; i < m_item.size(); i++)
	{
		if (m_item[i].item == _item)
		{
			delete m_item[i].item;
			m_item.erase(m_item.begin() + i);
			break;
		}
	}

	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	if ((*it) == _item)
	//	{
	//		it = m_item.erase(it);
	//		break;
	//	}
	//}

	repositionItems();
}

void Inventory::setOpening(bool _shouldBeOpened)
{
	m_isOpen = _shouldBeOpened;
}

bool Inventory::isOpen()
{
	return m_isOpen;
}

void Inventory::repositionItems()
{
	//int count(0);
	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	(*it)->setPos(sf::Vector2f(Inventory::m_pos.x + 100.f + 200.f * (float)count , Inventory::m_pos.y + 500.f));
	//	count++;
	//}
}
