#include "Game.h"
#include "DatabaseManager.h"
#include "CharacterManager.h"
#include "SkillTreeManager.h"
#include "DialogueManager.h"
#include "MapManager.h"

Game::Game() //: m_mapManager(), m_dialogueManager(), m_interactionManager(), m_craftManager()//, m_skillsSystem(m_treeDB)
{
	DatabaseManager::loadAllDatabase();
	new PawnManager();
	new SkillTreeManager();
	new DialogueManager();
	MapManager::MapManager();
	//DialogueManager::SetupDialogue("intro");
	//m_mapManager.addItem(m_itemDB->getItem("sword"));
	//m_mapManager.addItem(m_itemDB->getItem("pickaxe"));
	//m_mapManager.addItem(m_itemDB->getItem("metalArmor"));
	//m_mapManager.addItem(m_itemDB->getItem("shield"));
	//m_mapManager.addItem(m_itemDB->getItem("heart"));
	//m_mapManager.addItem(m_itemDB->getItem("speedPotion"));

	//m_characterManager.addCharacterItem("Player", m_itemDB->getItem("sword"));
}

Game::~Game()
{
}

void Game::Update()
{
	if (DialogueManager::IsInDialogue())
	{
		DialogueManager::Update();
	}
	else
	{
		MapManager::Update();
		PawnManager::Update();
		SkillTreeManager::Update();
	}
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
	MapManager::Display();
	PawnManager::Display();
	if (0)
		SkillTreeManager::Display();
	DialogueManager::Display();

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
