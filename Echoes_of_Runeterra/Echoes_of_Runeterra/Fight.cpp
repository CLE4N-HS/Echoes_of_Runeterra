#include "Fight.h"
#include "FightStatePlayerChoice.h"
#include "Window.h"
#include "ComponentName.h"

Fight::Fight(Player* _player, const std::vector<Enemy*>& _enemy) : m_player(_player), m_enemy(_enemy)
{
	m_state = new FightStatePlayerChoice();
	//m_enemy.push_back(m_enemy[0]);
	//m_enemy.push_back(m_enemy[0]);
	//m_enemy.push_back(m_enemy[0]);
	//m_enemy.push_back(m_enemy[0]);
	//m_enemy.push_back(m_enemy[0]);

	this->RepositionEnemies();
}

Fight::~Fight()
{
	delete m_state;
}

void Fight::Update()
{
	m_state->Update();
}

void Fight::Display()
{
	this->DisplayEnemies();

	if (m_player)
		this->DisplayPlayer();

	m_state->Display();
}

void Fight::ChangeState(FightState* _state)
{
	delete m_state;
	m_state = _state;
}

void Fight::DisplayPlayer()
{
	// this color was found (randomly) by Google (c)
	Window::rectangle.setFillColor(sf::Color(250, 90, 191));
	Window::rectangle.setPosition(sf::Vector2f(960.f, 900.f));
	Window::rectangle.setSize(sf::Vector2f(200.f, 300.f));
	Window::rectangle.setOrigin(Window::rectangle.getSize() * 0.5f);
	Window::rectangle.setScale(sf::Vector2f(1.f, 1.f));
	Window::Draw();

	Window::text.setFillColor(sf::Color(255, 255, 255));
	Window::text.setCharacterSize(30);

	// name
	Window::text.setString(m_player->GetComponent<ComponentName>()->GetName());
	Window::text.setPosition(Window::rectangle.getPosition() - sf::Vector2f(0.f, Window::rectangle.getSize().y * 0.3f));
	Tools::CenterTextOrigin(Window::text);
	Window::Draw(Window::text);

	Window::text.setCharacterSize(20);
	DisplayStats(Window::rectangle.getPosition(), Window::rectangle.getSize(), m_player->GetFightStats());



	const size_t nbCompabnion = m_player->GetCompanion().size();
	// this color was found (randomly) by ChatGPT (c)
	Window::rectangle.setFillColor(sf::Color(87, 203, 14));
	Window::rectangle.setSize(sf::Vector2f(160.f, 160.f));
	Window::rectangle.setOrigin(Window::rectangle.getSize() * 0.5f);
	Window::rectangle.setScale(sf::Vector2f(1.f, 1.f));
	for (size_t i = 0; i < nbCompabnion; i++)
	{
		Window::rectangle.setPosition(sf::Vector2f(600.f - Tools::Lerp(0.f, 400.f, static_cast<float>(i) / static_cast<float>(nbCompabnion - 1)), 900.f));
		Window::Draw();

		// name
		Window::text.setString(m_player->GetCompanion()[i]->GetComponent<ComponentName>()->GetName());
		Window::text.setPosition(Window::rectangle.getPosition() - sf::Vector2f(0.f, Window::rectangle.getSize().y * 0.3f));
		Tools::CenterTextOrigin(Window::text);
		Window::Draw(Window::text);

		DisplayStats(Window::rectangle.getPosition(), Window::rectangle.getSize(), m_player->GetCompanion()[i]->GetFightStats());
	}
}

void Fight::DisplayStats(const sf::Vector2f& _pos, const sf::Vector2f& _size, const FightStats& _fightStats)
{
	Window::text.setString("Hp : " + std::to_string(_fightStats.hp));
	Window::text.setPosition(_pos + sf::Vector2f(0.f, _size.y * 0.1f));
	Tools::CenterTextOrigin(Window::text);
	Window::Draw(Window::text);

	Window::text.setString("Attack : " + std::to_string(_fightStats.attack));
	Window::text.setPosition(_pos + sf::Vector2f(0.f, _size.y * 0.25f));
	Tools::CenterTextOrigin(Window::text);
	Window::Draw(Window::text);

	Window::text.setString("Defense : " + std::to_string(_fightStats.defense));
	Window::text.setPosition(_pos + sf::Vector2f(0.f, _size.y * 0.4f));
	Tools::CenterTextOrigin(Window::text);
	Window::Draw(Window::text);
}

void Fight::DisplayEnemies()
{
	const size_t nbEnemies = m_enemy.size();
	// this color was found (randomly) by PickerWheel (c)
	Window::rectangle.setFillColor(sf::Color(114, 53, 215));
	Window::text.setCharacterSize(20);
	for (size_t i = 0; i < nbEnemies; i++)
	{
		m_enemy[i]->transform->CorrectWindowRectangle();
		Window::Draw();

		// name
		Window::text.setString(m_enemy[i]->GetComponent<ComponentName>()->GetName());
		Window::text.setPosition(Window::rectangle.getPosition() - sf::Vector2f(0.f, Window::rectangle.getSize().y * 0.3f));
		Tools::CenterTextOrigin(Window::text);
		Window::Draw(Window::text);

		DisplayStats(m_enemy[i]->transform->getPos(), m_enemy[i]->transform->getSize(), m_enemy[i]->GetFightStats());
	}
}

void Fight::RepositionEnemies()
{
	const size_t nbEnemies = m_enemy.size();
	for (size_t i = 0; i < nbEnemies; i++)
	{
		m_enemy[i]->transform->setScale(sf::Vector2f(1.f, 1.f));
		m_enemy[i]->transform->setSize(sf::Vector2f(250.f, 200.f));
		m_enemy[i]->transform->setOrigin(m_enemy[i]->transform->getSize() * 0.5f);

		sf::Vector2f tmpPos = sf::Vector2f(960.f, 200.f);
		float halfSizeX(0.f);
		if (nbEnemies % 2 == 0)
		{
			halfSizeX = 400.f;
			tmpPos.x += lerp(-halfSizeX, halfSizeX, (nbEnemies - 1 <= 0 ? 0.f : static_cast<float>(i) / static_cast<float>(nbEnemies - 1)));
		}
		else if (nbEnemies > 1)
		{
			halfSizeX = 500.f;
			tmpPos.x += lerp(-halfSizeX, halfSizeX, (nbEnemies - 1 <= 0 ? 0.f : static_cast<float>(i) / static_cast<float>(nbEnemies - 1)));
		}
		m_enemy[i]->transform->setPos(tmpPos);
	}
}
