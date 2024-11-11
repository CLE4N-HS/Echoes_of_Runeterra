#include "Game.h"
#include "Player.h"
#include "Npc.h"


#include "craftdbtest.h"
#include "FightingSkills.h"
#include "SocialSkills.h"

Game::Game() : m_itemDB(new ItemDataBase), m_mapManager(), m_characterManager(), m_dialogueManager(), m_interactionManager(), m_craftManager(m_itemDB)
{
	SkillsLeaf leaf(new FightingSkills());
	SkillsLeaf leaf2(new SocialSkills());
	std::vector<SkillsLeaf*> allLeaves;
	allLeaves.push_back(&leaf);
	allLeaves.push_back(&leaf2);
	SkillsBranch branch(allLeaves);

	SkillsLeaf leaf9(new FightingSkills());
	SkillsLeaf leaf29(new SocialSkills());
	std::vector<SkillsLeaf*> allLeaves9{ &leaf9, &leaf29 };
	allLeaves9.push_back(&leaf9);
	allLeaves9.push_back(&leaf29);
	SkillsBranch branch9(std::vector<SkillsLeaf*>{ &leaf9, & leaf29 });

	std::vector<SkillsBranch*> allBranches;
	allBranches.push_back(&branch);
	allBranches.push_back(&branch9);

	SkillsTree tree(std::vector<SkillsBranch*>{&branch, &branch9});



	//std::vector<SkillsLeaf*> branch;
	//branch.push_back(new SkillsLeaf(new FightingSkills()));
	//std::vector<SkillsBranch*> tree;
	//tree.push_back()
	//a.push_back(new SkillsBranch(b));
	//m_testSkillTree = new SkillsTree(a);

	m_mapManager.addItem(m_itemDB->getItem("sword"));
	m_mapManager.addItem(m_itemDB->getItem("pickaxe"));
	m_mapManager.addItem(m_itemDB->getItem("metalArmor"));
	m_mapManager.addItem(m_itemDB->getItem("shield"));
	m_mapManager.addItem(m_itemDB->getItem("heart"));
	m_mapManager.addItem(m_itemDB->getItem("speedPotion"));
	m_dialogueManager.setupDialogue("intro");
}

Game::~Game()
{
}

void Game::update(Window& _window, State*& _state)
{
	m_mapManager.update(_window);

	if (!m_dialogueManager.isInDialogue())
		m_characterManager.update(_window);

	m_dialogueManager.update(_window);

	if (!m_dialogueManager.isInDialogue())
		m_interactionManager.update(_window, &m_characterManager, &m_dialogueManager, &m_mapManager);
}

void Game::display(Window& _window)
{
	m_mapManager.display(_window);

	m_characterManager.display(_window);

	m_dialogueManager.display(_window);


	// test
	_window.text.setFillColor(sf::Color::White);
	_window.text.setCharacterSize(30);
	_window.text.setString("You can interact with an NPC by being\nclose to him and clicking on him\nSame with Items");
	_window.text.setPosition(sf::Vector2f(10.f, 55.f));
	_window.draw(_window.text);
}
