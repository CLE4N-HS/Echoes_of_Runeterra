#include "Game.h"
#include "Player.h"
#include "Npc.h"

Game::Game() : m_itemDB(new ItemDataBase), m_map(), m_characterManager(), m_dialogueManager(), m_interactionManager()
{
	m_map.addItem(m_itemDB->takeItem("sword"));

	//m_character["Player"]->addItem(m_itemDB->takeItem("pickaxe"));
	//m_character["Player"]->addItem(m_itemDB->takeItem("metalArmor"));
	//m_character["Player"]->addItem(m_itemDB->takeItem("speedPotion"));
	//m_character["Player"]->addItem(m_itemDB->takeItem("dzfzf"));

	m_dialogueManager.setupDialogue("intro");
}

Game::~Game()
{
}

void Game::update(Window& _window , State*& _state)
{
	m_map.update(_window);

	m_characterManager.update(_window);

	m_dialogueManager.update(_window);

	m_interactionManager.update(_window, &m_characterManager, &m_dialogueManager);
}

void Game::display(Window& _window)
{
	m_map.display(_window);

	m_characterManager.display(_window);

	m_dialogueManager.display(_window);


	// test
	_window.text.setFillColor(sf::Color::White);
	_window.text.setCharacterSize(30);
	_window.text.setString("You can interact with an NPC by being\nclose to him and clicking on him");
	_window.text.setPosition(sf::Vector2f(100.f, 55.f));
	_window.draw(_window.text);
}
