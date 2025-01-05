#include "Player.h"
#include "ItemDatabase.h"
#include "MouseManager.h"
#include "Window.h"
#include "Alchemist.h"
#include "ComponentName.h"
#include "DialogueManager.h"

Player::Player() : Player("Player")
{
}

Player::Player(std::string _name) : Pawn(_name)
{
	this->AddComponent<ComponentName>(_name);

	this->transform->setSize(sf::Vector2f(20.f, 20.f));
	this->transform->setOrigin(this->transform->getSize() * 0.5f);
	this->transform->setPos(sf::Vector2f(960.f, 540.f));
	m_targetPos = this->transform->getPos();

	m_inventory.SetInstigator(this);
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("sword"), 2));
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("lifePotion"), 2));
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("pickaxe"), 54));
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("shield"), 2));
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("metalArmor"), 5));
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("chicken"), 5));
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("rice"), 70));
	//m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("wood")));
	m_inventory.AddItem(GameItem(ItemDatabase::CreateNewItem("heart"), 10));

	this->SetProfession(new Alchemist());

	this->m_fightStats = FightStats(500, 10, 10);
	this->AddCompanion(new Companion());
	this->AddCompanion(new Companion());
}

Player::~Player()
{
	while (m_companion.size() > 0)
	{
		m_companion.erase(m_companion.begin());
	}
}

void Player::Update()
{
	m_inventory.Update();

	if (!m_inventory.isOpen())
	{
		//this->UpdateMovement();
	}

	for (size_t i = 0; i < m_companion.size(); i++)
	{
		m_companion[i]->Update();
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
	Window::rectangle.setFillColor(sf::Color(0, 0, 255));
	this->transform->CorrectWindowRectangle();

	Window::Draw();

	//m_inventory.Display();



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

void Player::UpdateMovement(Map& _map)
{
	float dt = Tools::GetDeltaTime();

	//if (MouseManager::OneTimePressed())
	//{
	//	m_targetPos = Window::GetMousePos();
	//}

	//sf::Vector2f forwardVec = sf::Vector2f(m_targetPos - this->transform->getPos());
	//if (Tools::Magnitude(forwardVec) > 100.f)
	//{
	//	m_forward = Tools::Normalize(forwardVec);

	//	this->transform->Move(m_forward * m_moveSpeed * dt);
	//}

	m_forward = sf::Vector2f();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
	{
		m_forward.y -= 1.f;
		m_targetPos = sf::Vector2f(this->transform->getPos() + sf::Vector2f(0.f, -1.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		m_forward.x -= 1.f;
		m_targetPos = sf::Vector2f(this->transform->getPos() + sf::Vector2f(-1.f, 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_forward.y += 1.f;
		m_targetPos = sf::Vector2f(this->transform->getPos() + sf::Vector2f(0.f, 1.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_forward.x += 1.f;
		m_targetPos = sf::Vector2f(this->transform->getPos() + sf::Vector2f(1.f, 0.f));
	}

	sf::Vector2f normalizedForward = Tools::Normalize(m_forward);

	sf::Vector2f nextPos = this->transform->getPos() + normalizedForward * dt * 200.f;

	std::vector<std::vector<std::vector<Tile*>>> map = _map.getMap();

	size_t collLayer = Map::Layer::COLLISION;
	if (!m_inventory.isOpen() && map.size() > collLayer)
	{
		sf::Vector2f pos = this->transform->getPos();
		sf::Vector2f hSize = this->transform->getSize() * 0.5f;
		float tSize = static_cast<float>(Tile::SIZE);

		sf::Vector2f nextLocalPosBase = sf::Vector2f(m_forward.x * hSize.x, m_forward.y * hSize.y);
		bool Side = (nextLocalPosBase.y > -8.f && nextLocalPosBase.y < 8.f);

		sf::Vector2f nextLocalPos1 = (Side ? nextLocalPosBase - sf::Vector2f(0.f, hSize.y * 0.5f) : nextLocalPosBase - sf::Vector2f(hSize.x * 0.5f, 0.f));
		sf::Vector2f nextLocalPos2 = (Side ? nextLocalPosBase + sf::Vector2f(0.f, hSize.y * 0.5f) : nextLocalPosBase + sf::Vector2f(hSize.x * 0.5f, 0.f));

		sf::Vector2f mapNextPos1 = sf::Vector2f((pos.x + nextLocalPos1.x), (pos.y + nextLocalPos1.y));
		sf::Vector2f mapNextPos2 = sf::Vector2f((pos.x + nextLocalPos2.x), (pos.y + nextLocalPos2.y));

		//sf::Vector2f mapNextPos = this->transform->getPos() + sf::Vector2f(m_forward.x * this->transform->getSize().x, m_forward.y * this->transform->getSize().y);

		sf::Vector2i tilePos1 = sf::Vector2i(sf::Vector2f(mapNextPos1.x / tSize, mapNextPos1.y / tSize));
		sf::Vector2i tilePos2 = sf::Vector2i(sf::Vector2f(mapNextPos2.x / tSize, mapNextPos2.y / tSize));

		//sf::Vector2i tileMapPos = sf::Vector2i(sf::Vector2f(nextPos.x / tSize, nextPos.y / Tile::SIZE));

		bool isInMap1 = (tilePos1.x >= 0 && tilePos1.y >= 0 && tilePos1.y < map[collLayer].size() && tilePos1.x < map[collLayer][0].size());
		bool isInMap2 = (tilePos2.x >= 0 && tilePos2.y >= 0 && tilePos2.y < map[collLayer].size() && tilePos2.x < map[collLayer][0].size());

		//bool isInMap = (tilePos.x >= 0 && tilePos.y >= 0 && tilePos.y < map[collLayer].size() && tilePos.x < map[collLayer][0].size());

		bool allowedToMove(true);

		if (isInMap1)
		{
			//sf::FloatRect nextRect(this->transform->getPos(), this->transform->getSize() - this->transform->getOrigin());
			sf::FloatRect nextRect1(nextPos - this->transform->getOrigin(), this->transform->getSize());
			sf::FloatRect tileRect1(sf::Vector2f(tilePos1.x * tSize, tilePos1.y * tSize), sf::Vector2f(tSize, tSize));

			if (map[collLayer][tilePos1.y][tilePos1.x]->GetTextureName() != "" && nextRect1.intersects(tileRect1))
			{
				allowedToMove = false;
			}
		}
		if (isInMap2)
		{
			//sf::FloatRect nextRect(this->transform->getPos(), this->transform->getSize() - this->transform->getOrigin());
			sf::FloatRect nextRect2(nextPos - this->transform->getOrigin(), this->transform->getSize());
			sf::FloatRect tileRect2(sf::Vector2f(tilePos2.x * tSize, tilePos2.y * tSize), sf::Vector2f(tSize, tSize));

			if (map[collLayer][tilePos2.y][tilePos2.x]->GetTextureName() != "" && nextRect2.intersects(tileRect2))
			{
				allowedToMove = false;
			}
		}

		if (allowedToMove)
		{
			this->transform->setPos(nextPos);
		}
	}
}

void Player::AddCompanion(Companion* _companion)
{
	if (m_companion.size() >= 2)
	{
		// TODO idk QG or smth
	}
	else
	{
		m_companion.push_back(_companion);
	}
}

void Player::Consume(Consumable* _consumable)
{
	if (_consumable)
	{
		m_fightStats.hp += _consumable->getHpBuff();
		m_fightStats.attack += _consumable->GetAttackBuff();
		m_fightStats.defense += _consumable->getDefenseBuff();
	}
}
//
//void Player::UpdateMovement()
//{
//	
//
//
//
//
//	//if (!m_inventory->isOpen() && _window.mouseManager.hasJustPressed(sf::Mouse::Left))
//	//{
//	//	m_targetPos = _window.getMousePos();
//	//	m_foward = sf::Vector2f(m_targetPos - m_pos);
//	//	vec2fNormalize(m_foward);
//	//}
//
//	//if (vec2fGetMagnitude(sf::Vector2f(m_targetPos - m_pos)) > 26.f)
//	//{
//	//	m_pos += m_foward * m_moveSpeed * dt;
//	//	m_animState = "walk";
//	//}
//	//else
//	//{
//	//	m_animState = "idle";
//	//}
//}

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
