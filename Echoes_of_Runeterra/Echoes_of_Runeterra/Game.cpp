#include "Game.h"
#include "Player.h"
#include "Npc.h"

Game::Game() : m_itemDB(new ItemDataBase), m_map(), m_character()
{
	m_character.insert({ "Player", new Player()});
	m_character.insert({ "Npc", new Npc() });


	m_character["Player"]->setPos(sf::Vector2f(960.f, 800.f));
	m_character["Npc"]->setPos(sf::Vector2f(1200.f, 100.f));

	m_map.addItem(m_itemDB->takeItem("sword"));
	m_character["Player"]->addItem(m_itemDB->takeItem("pickaxe"));
}

Game::~Game()
{
	delete m_itemDB;
}

void Game::update(Window& _window , State*& _state)
{
	m_map.update(_window);

	for (std::unordered_map<std::string, Character*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	{
		it->second->update(_window);
	}

	//if (vec2fGetMagnitude(sf::Vector2f(m_character1.getPos() - m_character2.getPos())) < 500.f)
	//{
	//	m_character1.attack(m_character2);
	//}
}

void Game::display(Window& _window)
{
	m_map.display(_window);

	for (std::unordered_map<std::string, Character*>::iterator it = m_character.begin(); it != m_character.end(); it++)
	{
		it->second->display(_window);
	}
}
