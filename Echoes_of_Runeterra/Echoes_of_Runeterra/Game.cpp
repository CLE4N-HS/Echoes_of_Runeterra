#include "Game.h"

Game::Game() : m_itemDB(new ItemDataBase), m_map(), m_character1("Player"), m_character2()
{
	m_character1.setPos(sf::Vector2f(960.f, 800.f));
	m_character2.setPos(sf::Vector2f(1200.f, 100.f));

	m_map.addItem(m_itemDB->takeItem("sword"));
}

Game::~Game()
{
	delete m_itemDB;
}

void Game::update(Window& _window , State*& _state)
{
	m_map.update(_window);
	m_character1.update(_window);
	m_character2.update(_window);

	if (vec2fGetMagnitude(sf::Vector2f(m_character1.getPos() - m_character2.getPos())) < 500.f)
	{
		m_character1.attack(m_character2);
	}
}

void Game::display(Window& _window)
{
	m_map.display(_window);
	m_character1.display(_window);
	m_character2.display(_window);



	// Player
	if (m_character1.isInventoryOpen())
		m_character1.displayInventory(_window);
}
