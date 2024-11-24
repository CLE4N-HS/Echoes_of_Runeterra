#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "CraftManager.h"
#include "Window.h"
#include "KeyboardManager.h"
#include "MouseManager.h"
#include "CraftDataBase.h"
#include "ComponentName.h"
#include "CharacterManager.h"
#include "Player.h"
#include "ItemDatabase.h"
#include "ProfessionCraftDatabase.h"

Inventory::Inventory() : Entity(Transform(sf::Vector2f(100.f, 100.f), sf::Vector2f(1720.f, 880.f), Transform::Origin::TOP_LEFT)), m_item(), m_isOpen(false)
{
	m_button.reserve(sizeof(InventoryButton) * 3);
	sf::Vector2f tmpSize(200.f, 100.f);
	sf::Vector2f tmpPos(transform->getPos());
	m_button.push_back(InventoryButton(Transform(sf::Vector2f(tmpPos.x + 20.f + 0.f * tmpSize.x * 1.2f, tmpPos.y + 20.f), tmpSize, Transform::Origin::TOP_LEFT), "Craft"));
	m_button.push_back(InventoryButton(Transform(sf::Vector2f(tmpPos.x + 20.f + 1.f * tmpSize.x * 1.2f, tmpPos.y + 20.f), tmpSize, Transform::Origin::TOP_LEFT), "\nCraft\n"));
	m_button.push_back(InventoryButton(Transform(sf::Vector2f(tmpPos.x + 20.f + 2.f * tmpSize.x * 1.2f, tmpPos.y + 20.f), tmpSize, Transform::Origin::TOP_LEFT), "Equip"));
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	if (KeyboardManager::OneTimePressed(sf::Keyboard::I))
	{
		m_isOpen = !m_isOpen;
		UnselectItems();
	}

	if (!m_isOpen)
		return;

	sf::Vector2f mousePos = Window::GetMousePos();

	for (std::vector<InventoryItem>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		if (it->gameItem.item->transform->GetRect().contains(mousePos) && MouseManager::OneTimePressed())
		{
			it->isSelected = !it->isSelected;
		}

		//it->gameItem.item->setHover(false);
		//if (m_isOpen)
		//{
		//	it->gameItem.item->Update();
		//}
	}

	UpdateButton();

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
	Window::text.setFillColor(sf::Color::White);
	Window::text.setCharacterSize(30);
	Window::text.setString((m_isOpen ? "I -> to close the Inventory" : "I -> to open the Inventory"));
	Window::text.setPosition(sf::Vector2f(10.f, 5.f));
	Window::text.setOrigin(sf::Vector2f());
	Window::Draw(Window::text);

	if (!m_isOpen)
		return;

	// bg
	transform->CorrectWindowRectangle();
	Window::rectangle.setFillColor(sf::Color(123, 63, 0, 200));
	Window::Draw();

	Window::rectangle.setFillColor(sf::Color(255, 255, 255));

	if (m_isInDatabase)
	{
		std::list<CraftItem*> craftDB = CraftDatabase::GetDatabase();

		sf::Vector2f startPos(this->transform->getPos() + sf::Vector2f(20.f, 160.f));
		sf::Vector2f itemPos(startPos + sf::Vector2f(200.f, 0.f));
		
		std::vector<GameItem> selectedItem;
		for (size_t i = 0; i < m_item.size(); i++)
		{
			if (m_item[i].isSelected)
				selectedItem.push_back(m_item[i].gameItem);
		}

		Window::text.setOrigin(sf::Vector2f());
		for (std::list<CraftItem*>::iterator it = craftDB.begin(); it != craftDB.end(); it++)
		{
			Window::text.setPosition(startPos);
			Window::text.setStyle(sf::Text::Style::Underlined);
			Window::text.setString((*it)->item->GetComponent<ComponentName>()->GetName() + " :");
			Window::text.setFillColor(sf::Color::White);
			Window::Draw(Window::text);

			Window::text.setStyle(sf::Text::Style::Regular);
			itemPos.x = Window::text.getPosition().x + Window::text.getLocalBounds().width + 20.f;
			for (size_t reqItem = 0; reqItem < (*it)->requiredItem.size(); reqItem++)
			{
				Window::text.setPosition(itemPos);
				Window::text.setString((*it)->requiredItem[reqItem]->item->GetComponent<ComponentName>()->GetName()
					+ " [" + std::to_string((*it)->requiredItem[reqItem]->quantity) + "] " + (reqItem + 1 >= (*it)->requiredItem.size() ? "" : ","));

				Window::text.setFillColor(sf::Color(255, 255, 255));
				for (size_t i = 0; i < selectedItem.size(); i++)
				{
					if (selectedItem[i].item->operator==((*it)->requiredItem[reqItem]->item))
					{
						if (selectedItem[i].quantity >= (*it)->requiredItem[reqItem]->quantity)
							Window::text.setFillColor(sf::Color(255, 0, 0));
						else
							Window::text.setFillColor(sf::Color(255, 127, 127));

						break;
					}
				}

				Window::Draw(Window::text);

				itemPos.x = Window::text.getPosition().x + Window::text.getLocalBounds().width + 20.f;
			}

			itemPos.y = startPos.y = Window::text.getPosition().y + Window::text.getLocalBounds().height + 20.f;
		}

		startPos.y += 20.f;
		Window::text.setPosition(startPos);
		Window::text.setStyle(sf::Text::Style::Bold);
		Window::text.setString("Profession Craft :");
		Window::text.setFillColor(sf::Color::White);
		Window::Draw(Window::text);
		Window::text.setStyle(sf::Text::Style::Regular);

		itemPos.y = startPos.y = Window::text.getPosition().y + Window::text.getLocalBounds().height + 40.f;

		std::list<ProfessionCraft*> professionDB = ProfessionCraftDatabase::GetDatabase();

		Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player"));
		Profession* profession = player->GetProfession();

		std::string playerProfession = (profession ? profession->ToString() : "");

		for (std::list<ProfessionCraft*>::iterator it = professionDB.begin(); it != professionDB.end(); it++)
		{
			if (playerProfession != (*it)->profession)
				continue;

			Window::text.setPosition(startPos);
			Window::text.setStyle(sf::Text::Style::Underlined);
			Window::text.setString((*it)->craftItem->item->GetComponent<ComponentName>()->GetName() + " :");
			Window::text.setFillColor(sf::Color::White);
			Window::Draw(Window::text);

			Window::text.setStyle(sf::Text::Style::Regular);
			itemPos.x = Window::text.getPosition().x + Window::text.getLocalBounds().width + 20.f;
			for (size_t reqItem = 0; reqItem < (*it)->craftItem->requiredItem.size(); reqItem++)
			{
				Window::text.setPosition(itemPos);
				Window::text.setString((*it)->craftItem->requiredItem[reqItem]->item->GetComponent<ComponentName>()->GetName()
					+ " [" + std::to_string((*it)->craftItem->requiredItem[reqItem]->quantity) + "] " + (reqItem + 1 >= (*it)->craftItem->requiredItem.size() ? "" : ","));

				Window::text.setFillColor(sf::Color(255, 255, 255));
				for (size_t i = 0; i < selectedItem.size(); i++)
				{
					if (selectedItem[i].item->operator==((*it)->craftItem->requiredItem[reqItem]->item))
					{
						if (selectedItem[i].quantity >= (*it)->craftItem->requiredItem[reqItem]->quantity)
							Window::text.setFillColor(sf::Color(255, 0, 0));
						else
							Window::text.setFillColor(sf::Color(255, 127, 127));

						break;
					}
				}

				Window::Draw(Window::text);

				itemPos.x = Window::text.getPosition().x + Window::text.getLocalBounds().width + 20.f;
			}

			itemPos.y = startPos.y = Window::text.getPosition().y + Window::text.getLocalBounds().height + 20.f;
		}
	}
	else
	{
		// item
		Window::text.setFillColor(sf::Color(255, 255, 255));
		Window::text.setCharacterSize(30);
		for (std::vector<InventoryItem>::iterator it = m_item.begin(); it != m_item.end(); it++)
		{
			//it->gameItem.item->Display();
			// ^ equals ^
			Window::rectangle.setFillColor(sf::Color(255, 0, 0, 100));
			it->gameItem.item->transform->CorrectWindowRectangle();
			Window::Draw();


			Window::text.setPosition(it->gameItem.item->transform->getPos() + it->gameItem.item->transform->getSize() * 0.5f);
			Window::text.setString(it->gameItem.item->GetComponent<ComponentName>()->GetName());
			Tools::CenterTextOrigin(Window::text);
			Window::Draw(Window::text);

			Window::text.setPosition(it->gameItem.item->transform->getPos() + it->gameItem.item->transform->getSize() * 0.5f + sf::Vector2f(0.f, 70.f));
			Window::text.setString(std::to_string(it->gameItem.quantity));
			Tools::CenterTextOrigin(Window::text);
			Window::Draw(Window::text);
		}

		// item hover
		Window::rectangle.setFillColor(sf::Color(255, 255, 255, 100));
		for (std::vector<InventoryItem>::iterator it = m_item.begin(); it != m_item.end(); it++)
		{
			if (it->isSelected)
			{
				it->gameItem.item->transform->CorrectWindowRectangle();
				Window::Draw();
			}
		}
		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
	}

	DisplayButton();

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
		if (_item.item->operator==(m_item[i].gameItem.item))
		{
			m_item[i].gameItem.quantity += _item.quantity;
			haveAlready = true;
			break;
		}
	}

	if (!haveAlready)
	{
		m_item.push_back(_item);
		RepositionItems();
	}
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

void Inventory::RemoveItem(Item* _item, int _quantity, bool _delete)
{
	for (size_t i = 0; i < m_item.size(); i++)
	{
		if (m_item[i].gameItem.item->operator==(_item))
		{
			m_item[i].gameItem.quantity -= _quantity;
			if (m_item[i].gameItem.quantity <= 0)
			{
				if (_delete)
					delete m_item[i].gameItem.item;

				m_item.erase(m_item.begin() + i);
			}
			break;
		}
	}
}

void Inventory::EraseItem(Item* _item)
{
	for (size_t i = 0; i < m_item.size(); i++)
	{
		if (m_item[i].gameItem.item->operator==(_item))
		{
			delete m_item[i].gameItem.item;
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

	RepositionItems();
}

void Inventory::setOpening(bool _shouldBeOpened)
{
	m_isOpen = _shouldBeOpened;
}

bool Inventory::isOpen()
{
	return m_isOpen;
}

void Inventory::RepositionItems()
{
	sf::Vector2f startPos(this->transform->getPos() + sf::Vector2f(100.f, 180.f));
	sf::Vector2f offset(0.f, 0.f);
	for (std::vector<InventoryItem>::iterator it = m_item.begin(); it != m_item.end(); it++)
	{
		it->gameItem.item->transform->setSize(sf::Vector2f(100.f, 100.f));
		it->gameItem.item->transform->setPos(startPos + offset);
		offset.x += 200.f;
		if (startPos.x + offset.x > 1700.f)
		{
			offset.x = 0.f;
			offset.y += 180.f;
		}
	}
	 
	//int count(0);
	//for (std::list<Item*>::iterator it = m_item.begin(); it != m_item.end(); it++)
	//{
	//	(*it)->setPos(sf::Vector2f(Inventory::m_pos.x + 100.f + 200.f * (float)count , Inventory::m_pos.y + 500.f));
	//	count++;
	//}
}

void Inventory::UnselectItems()
{
	for (size_t i = 0; i < m_item.size(); i++)
	{
		m_item[i].isSelected = false;
	}
}

void Inventory::UpdateButton()
{
	sf::Vector2f mousePos = Window::GetMousePos();

	// Craft Database
	if (m_button[1].transform.GetRect().contains(mousePos) && MouseManager::OneTimePressed())
	{
		m_button[1].isClickable = m_isInDatabase = !m_isInDatabase;
	}

	if (m_isInDatabase)
	{
		m_button[0].isClickable = false;
		m_button[2].isClickable = false;
		return;
	}

	std::vector<GameItem> selectedItem;
	for (size_t i = 0; i < m_item.size(); i++)
	{
		if (m_item[i].isSelected)
			selectedItem.push_back(m_item[i].gameItem);
	}

	// Craft
	Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player"));
	Profession* profession = player->GetProfession();

	if ((profession ? CraftManager::IsCraftCorrect(selectedItem, profession->ToString()) : CraftManager::IsCraftCorrect(selectedItem)))
	{
		m_button[0].isClickable = true;

		if (m_button[0].transform.GetRect().contains(mousePos) && MouseManager::OneTimePressed())
		{
			if (Item* item = (profession ? CraftManager::Craft(selectedItem, profession->ToString()) : CraftManager::Craft(selectedItem)))
			{
				for (size_t i = 0; i < m_item.size(); i++)
				{
					for (size_t j = 0; j < selectedItem.size(); j++)
					{
						if (m_item[i].gameItem.item->operator==(selectedItem[j].item))
						{
							m_item[i].gameItem.quantity = selectedItem[j].quantity;
							if (m_item[i].gameItem.quantity <= 0)
							{
								EraseItem(m_item[i].gameItem.item);
							}
						}
					}
				}

				AddItem(GameItem(item));
				RepositionItems();
				UnselectItems();
			}
		}
	}
	else
	{
		m_button[0].isClickable = false;
	}

	// Equip
	if (selectedItem.size() == 1)
	{
		Weapon* weapon = dynamic_cast<Weapon*>(selectedItem[0].item);
		Armor* armor = dynamic_cast<Armor*>(selectedItem[0].item);

		if (weapon || armor)
			m_button[2].isClickable = true;
		else
			m_button[2].isClickable = false;

		if (m_button[2].isClickable && m_button[2].transform.GetRect().contains(mousePos) && MouseManager::OneTimePressed())
		{
			//if (Player* player = reinterpret_cast<Player*>(this->GetParent())) // this line is scary..
			if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
			{
				if (weapon)
				{
					if (Weapon* playerWeapon = player->GetWeapon())
					{
						AddItem(playerWeapon);
					}
					player->SetWeapon( weapon);
					RemoveItem(selectedItem[0].item);
					RepositionItems();
					UnselectItems();
				}
				else if (armor)
				{
					if (Armor* playerArmor = player->GetArmor())
					{
						AddItem(playerArmor);
					}
					player->SetArmor(armor);
					RemoveItem(selectedItem[0].item);
					RepositionItems();
					UnselectItems();
				}
			}
		}
	}
	else
	{
		m_button[2].isClickable = false;
	}
}

void Inventory::DisplayButton()
{
	for (size_t i = 0; i < m_button.size(); i++)
	{
		Window::rectangle.setFillColor(m_button[i].isClickable ? sf::Color(255, 255, 255) : sf::Color(255, 255, 255, 150));
		m_button[i].transform.CorrectWindowRectangle();
		Window::Draw();

		Window::text.setFillColor(sf::Color(123, 63, 0, 200));
		Window::text.setCharacterSize(30);
		Window::text.setPosition(m_button[i].transform.getPos() + m_button[i].transform.getSize() * 0.5f);
		Window::text.setString(m_button[i].string);
		Tools::CenterTextOrigin(Window::text);
		Window::Draw(Window::text);

		if (m_button[i].string[0] == '\n')
		{
			Window::text.setString("\nDatabase");
			Tools::CenterTextOrigin(Window::text);
			Window::Draw(Window::text);
		}
	}
	Window::rectangle.setFillColor(sf::Color(255, 255, 255));
}
