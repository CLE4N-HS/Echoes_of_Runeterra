#include "Player.h"
#include "ItemDatabase.h"
#include "MouseManager.h"
#include "Window.h"

Player::Player() : Player("Player")
{
}

Player::Player(std::string _name) : Pawn(_name)
{
	this->transform->setSize(sf::Vector2f(50.f, 50.f));
	this->transform->setOrigin(this->transform->getSize() * 0.5f);
	this->transform->setPos(sf::Vector2f(960.f, 540.f));
	m_targetPos = this->transform->getPos();

	m_inventory.SetInstigator(this);
	m_inventory.AddItem(GameItem(ItemDatabase::GetItem("sword")));
	m_inventory.AddItem(GameItem(ItemDatabase::GetItem("speedPotion"), 2));
	m_inventory.AddItem(GameItem(ItemDatabase::GetItem("pickaxe"), 2));
}

Player::~Player()
{
}

void Player::Update()
{
	m_inventory.Update();

	if (!m_inventory.isOpen())
	{
		this->UpdateMovement();
	}

	/*
	m_attackTimer += dt;

	this->updateMovement(_window);

	m_profession->update(_window);

	m_inventory->update(_window);

	this->updateInventoryInteractions(_window);*/
}

void Player::Display()
{
	this->transform->CorrectWindowRectangle();

	Window::Draw();

	m_inventory.Display();



	//_window.rectangle.setPosition(m_pos);
	//_window.rectangle.setTexture(tex_getTexture("viego"));
	//_window.rectangle.setSize(m_size);
	//_window.rectangle.setOrigin(m_origin);
	//_window.rectangle.setTextureRect(texGetRectAnim(_window, "viego", m_animState.c_str(), &m_frameX, &m_animTimer));
	//if (m_animState == "walk" && m_foward.x < 0.f)
	//	_window.rectangle.setScale(sf::Vector2f(m_scale.x * -1.f, m_scale.y));
	//else
	//	_window.rectangle.setScale(m_scale);

	//_window.draw(_window.rectangle);
	//_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));

	//char buffer[100]{};
	//_window.text.setCharacterSize(30);
	//_window.text.setFillColor(sf::Color::White);

	//_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 20.f));
	//sprintf(buffer, "Level : %d", m_level);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 50.f));
	//sprintf(buffer, "Xp : %d/%d", m_xp, m_levelXp);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);


	//if (m_armor != nullptr)
	//{
	//	_window.rectangle.setPosition(m_pos);
	//	_window.rectangle.setTexture(tex_getTexture("items"));
	//	sf::IntRect tmpArmorRect = tex_getAnimRect("items", m_armor->getName().c_str());
	//	_window.rectangle.setSize(sf::Vector2f(sf::Vector2i(tmpArmorRect.width, tmpArmorRect.height)));
	//	_window.rectangle.setOrigin(sf::Vector2f(sf::Vector2i(tmpArmorRect.width / 2, tmpArmorRect.height / 2)));
	//	_window.rectangle.setTextureRect(tmpArmorRect);
	//	_window.rectangle.setScale(sf::Vector2f(3.f, 3.f));
	//	_window.draw(_window.rectangle);
	//}

	//if (m_weapon != nullptr)
	//{
	//	_window.rectangle.setPosition(m_pos + sf::Vector2f(0.f, -50.f));
	//	_window.rectangle.setTexture(tex_getTexture("items"));
	//	sf::IntRect tmpWeaponRect = tex_getAnimRect("items", m_weapon->getName().c_str());
	//	_window.rectangle.setSize(sf::Vector2f(sf::Vector2i(tmpWeaponRect.width, tmpWeaponRect.height)));
	//	_window.rectangle.setOrigin(sf::Vector2f(sf::Vector2i(tmpWeaponRect.width / 2, tmpWeaponRect.height / 2)));
	//	_window.rectangle.setTextureRect(tmpWeaponRect);
	//	_window.rectangle.setScale(sf::Vector2f(3.f, 3.f));
	//	_window.draw(_window.rectangle);
	//}

	//_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));

	//m_inventory->display(_window);

	//m_profession->display(_window);

}

void Player::UpdateMovement()
{
	float dt = Tools::GetDeltaTime();

	if (MouseManager::OneTimePressed())
	{
		m_targetPos = Window::GetMousePos();
	}

	sf::Vector2f forwardVec = sf::Vector2f(m_targetPos - this->transform->getPos());
	if (Tools::Magnitude(forwardVec) > 100.f)
	{
		m_forward = Tools::Normalize(forwardVec);

		this->transform->Move(m_forward * m_moveSpeed * dt);
	}

	//if (!m_inventory->isOpen() && _window.mouseManager.hasJustPressed(sf::Mouse::Left))
	//{
	//	m_targetPos = _window.getMousePos();
	//	m_foward = sf::Vector2f(m_targetPos - m_pos);
	//	vec2fNormalize(m_foward);
	//}

	//if (vec2fGetMagnitude(sf::Vector2f(m_targetPos - m_pos)) > 26.f)
	//{
	//	m_pos += m_foward * m_moveSpeed * dt;
	//	m_animState = "walk";
	//}
	//else
	//{
	//	m_animState = "idle";
	//}
}

void Player::UpdateInventoryInteractions()
{
	//if (m_inventory->isOpen() && _window.mouseManager.hasJustPressed(sf::Mouse::Left))
	//{
	//	Item* item = m_inventory->getItem();
	//	if (item != nullptr) // to know if we have choosen an item
	//	{
	//		// differentiate items type
	//		Weapon* tmpWeapon = dynamic_cast<Weapon*>(item);
	//		Armor* tmpArmor = dynamic_cast<Armor*>(item);
	//		Consumable* tmpConsumable = dynamic_cast<Consumable*>(item);

	//		if (tmpWeapon != nullptr)
	//		{
	//			//m_inventory->eraseItem(item); TODO let
	//			if (m_weapon != nullptr) // if we already have a Weapon, return it back to the Inventory
	//				m_inventory->addItem(m_weapon);
	//			
	//			int speed = tmpWeapon->getSpeed();
	//			tmpWeapon->SETSPEEDTESTTODO(123);
	//			speed = tmpWeapon->getSpeed();

	//			m_weapon = tmpWeapon;
	//		}
	//		else if (tmpArmor != nullptr)
	//		{
	//			m_inventory->eraseItem(item);
	//			if (m_armor != nullptr) // if we already have an Armor, return it back to the Inventory
	//				m_inventory->addItem(m_armor);

	//			m_armor = tmpArmor;
	//		}
	//		else if (tmpConsumable != nullptr)
	//		{
	//			// gain consumable Stats
	//			m_maxHp += tmpConsumable->getHpBuff();
	//			m_hp += tmpConsumable->getHpBuff();
	//			m_defense += tmpConsumable->getDefenseBuff();
	//			m_speed += tmpConsumable->getSpeedBuff();
	//			Pawn::giveXp(50);
	//			m_inventory->eraseItem(item);
	//		}
	//	}
	//}
}
