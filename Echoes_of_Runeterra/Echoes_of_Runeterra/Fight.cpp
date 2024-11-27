#include "Fight.h"
#include "FightStatePlayerChoice.h"
#include "Window.h"
#include "ComponentName.h"

Fight::Fight(Player* _player, const std::vector<Enemy*>& _enemy) : m_player(_player), m_enemy(_enemy)
{
	m_state = new FightStatePlayerChoice();
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



	size_t nbCompabnion = m_player->GetCompanion().size();
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
