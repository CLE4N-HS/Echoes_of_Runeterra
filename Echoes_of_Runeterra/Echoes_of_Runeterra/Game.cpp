#include "Game.h"
#include "Player.h"
#include "Npc.h"

Game::Game() : m_itemDB(new ItemDataBase), m_mapManager(), m_characterManager(), m_dialogueManager(), m_interactionManager(), m_craftManager(m_itemDB),
	m_treeDB(new TreeDataBase),
	m_skillsSystem(m_treeDB)
{
	m_mapManager.addItem(m_itemDB->getItem("sword"));
	m_mapManager.addItem(m_itemDB->getItem("pickaxe"));
	m_mapManager.addItem(m_itemDB->getItem("metalArmor"));
	m_mapManager.addItem(m_itemDB->getItem("shield"));
	m_mapManager.addItem(m_itemDB->getItem("heart"));
	m_mapManager.addItem(m_itemDB->getItem("speedPotion"));
	m_dialogueManager.setupDialogue("intro");

	m_characterManager.addCharacterItem("Player", m_itemDB->getItem("sword"));
}

Game::~Game()
{
}

void Game::Update()
{
	//m_mapManager.update(_window);

	////if (!m_dialogueManager.isInDialogue())
	//	m_characterManager.update(_window);

	//m_dialogueManager.update(_window);

	//if (!m_dialogueManager.isInDialogue())
	//	m_interactionManager.update(_window, &m_characterManager, &m_dialogueManager, &m_mapManager);

	//m_skillsSystem.update(_window);
}

void Game::Display()
{
	//m_mapManager.display(_window);

	//m_characterManager.display(_window);

	//m_dialogueManager.display(_window);


	//// test
	//_window.text.setFillColor(sf::Color::White);
	//_window.text.setCharacterSize(30);
	//_window.text.setString("You can interact with an NPC by being\nclose to him and clicking on him\nSame with Items");
	//_window.text.setPosition(sf::Vector2f(10.f, 55.f));
	//_window.draw(_window.text);
}
