#include "Game.h"
#include "DatabaseManager.h"
#include "CharacterManager.h"
#include "SkillTreeManager.h"
#include "DialogueManager.h"
//#include "MapManager.h"
#include "FightManager.h"

#include "TileTextureManager.h"
#include "Window.h"
#include "RenderStatesManager.h"
#include "ObjectTextureManager.h"
#include "TorchObject.h"
#include "AnimTile.h"
#include "ParticleManager.h"
#include "ComponentName.h"

#include "NpcTextureManager.h"
#include "EnemyTextureManager.h"

Game::Game() : m_Map(), m_DayNightSystem(), m_Enemy() //: m_mapManager(), m_dialogueManager(), m_interactionManager(), m_craftManager()//, m_skillsSystem(m_treeDB)
{
	DatabaseManager::loadAllDatabase();

	std::ifstream mapToLoad("../Resources/Saves/GameMap/MapToLoad.txt");

	bool hasFoundMap = false;
	if (mapToLoad.is_open())
	{
		std::string path;
		mapToLoad >> path;

		mapToLoad.close();

		std::ifstream map(path);

		if (map.is_open())
		{
			hasFoundMap = true;
			m_Map.Load(map, m_Enemy);

			map.close();
		}
	}

	if (!hasFoundMap)
	{
		m_Map.DefaultMap();
	}

	TileTextureManager::AddTexture("tileset", TILE_TEXTURE_PATH "tileset.png");
	TileTextureManager::AddTexture("tile", TILE_TEXTURE_PATH "tile.png");
	TileTextureManager::AddTexture("animTile", TILE_TEXTURE_PATH "animTile.png");
	TileTextureManager::AddTexture("water", TILE_TEXTURE_PATH "water.png");
	TileTextureManager::AddTexture("collision", TILE_TEXTURE_PATH "collision.png");
	TileTextureManager::AddTexture("cloud", TILE_TEXTURE_PATH "cloud_75.png");

	ObjectTextureManager::AddTexture("chest", OBJECT_TEXTURE_PATH "coffre32.png");
	ObjectTextureManager::AddTexture("torch", OBJECT_TEXTURE_PATH "torch.png");

	NpcTextureManager::AddTexture("penguin", NPC_TEXTURE_PATH "penguin.png");
	NpcTextureManager::AddTexture("bob", NPC_TEXTURE_PATH "bob.png");

	EnemyTextureManager::AddTexture("wildCorruptedBeast", ENEMY_TEXTURE_PATH "wildCorruptedBeast.png");
	EnemyTextureManager::AddTexture("spiritWolf", ENEMY_TEXTURE_PATH "spiritWolf.png");

	RenderStatesManager::AddShader("torch", SHADER_PATH "torch.frag", sf::Shader::Type::Fragment);
	RenderStatesManager::AddShader("dayNight", SHADER_PATH "dayNight.frag", sf::Shader::Type::Fragment);


	new PawnManager();
	new SkillTreeManager();
	new DialogueManager();
	//new MapManager();
	new FightManager();
	//DialogueManager::SetupDialogue("intro");
	//m_mapManager.addItem(m_itemDB->getItem("sword"));
	//m_mapManager.addItem(m_itemDB->getItem("pickaxe"));
	//m_mapManager.addItem(m_itemDB->getItem("metalArmor"));
	//m_mapManager.addItem(m_itemDB->getItem("shield"));
	//m_mapManager.addItem(m_itemDB->getItem("heart"));
	//m_mapManager.addItem(m_itemDB->getItem("speedPotion"));

	//m_characterManager.addCharacterItem("Player", m_itemDB->getItem("sword"));

	//Enemy* e = EnemyDatabase::CreateNewEnemy("wildCorruptedBeast");
	//if (e)
	//{
	//	e->transform->setPos(sf::Vector2f(120.f, 450.f));
	//	m_Enemy.push_back(e);
	//}
}

Game::~Game()
{
}

void Game::Update()
{
	m_DayNightSystem.Update();

	ParticleManager::Update();

	if (DialogueManager::IsInDialogue())
	{
		DialogueManager::Update();
	}
	else if (FightManager::IsInFight())
	{
		FightManager::Update();
	}
	else
	{
		//MapManager::Update();
		PawnManager::Update();

		if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
		{
			player->UpdateMovement(m_Map);
		}

		m_Map.UpdateChest();

		const sf::Vector2f mousePos = Window::GetMousePos();

		Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player"));

		for (std::vector<Enemy*>::iterator it = m_Enemy.begin(); it != m_Enemy.end();)
		{
			if (player && player->transform->GetRect().intersects((*it)->transform->GetRect()))
			{
				FightManager::SetupFight(new Fight(player, std::vector<Enemy*>{EnemyDatabase::CreateNewEnemy(dynamic_cast<Enemy*>((*it))),
					EnemyDatabase::CreateNewEnemy(dynamic_cast<Enemy*>((*it))),
					EnemyDatabase::CreateNewEnemy(dynamic_cast<Enemy*>((*it)))}));
				delete (*it);
				it = m_Enemy.erase(it);
				continue;
			}

			it++;
		}

		if (!NightOnePass && m_DayNightSystem.GetHour() <= 5)
		{
			Enemy* e = EnemyDatabase::CreateNewEnemy("spiritWolf");

			if (e)
			{
				e->transform->setPos(sf::Vector2f(200.f, 200.f));
				e->transform->setSize(sf::Vector2f(32.f, 32.f));
				e->transform->setOrigin(sf::Vector2f(16.f, 16.f));
				e->m_TextureName = "spiritWolf";
				m_Enemy.push_back(e);
				NightOnePass = true;
			}
		}

	}
	//SkillTreeManager::Update();

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
	sf::Vector2f centerViewPos = Window::view.getCenter();
	Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player"));
	if (player)
	{
		centerViewPos = player->transform->getPos();
	}

	Window::view.setCenter(centerViewPos);
	Window::SetView();

	m_Map.Display();

	std::vector<std::vector<std::vector<Tile*>>> map = m_Map.getMap();
	std::vector<Object*> object = m_Map.getObject();

	/*
	Window::rectangle.setOrigin(sf::Vector2f());
	Window::rectangle.setSize(sf::Vector2f(sf::Vector2<int>(Tile::SIZE, Tile::SIZE)));
	//test
	Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
	float tmpDt = Tools::GetDeltaTime();
	for (size_t l = 0; l < map.size(); l++)
	{
		if (m_Layer[l])
		{
			for (size_t y = 0; y < map[l].size(); y++)
			{
				for (size_t x = 0; x < map[l][y].size(); x++)
				{
					if (sf::Texture* tex = TileTextureManager::GetTexture(map[l][y][x]->GetTextureName()))
					{
						if (AnimTile* animTile = dynamic_cast<AnimTile*>(map[l][y][x]))
						{
							animTile->Anim(tmpDt);
						}

						Window::rectangle.setTexture(tex);
						Window::rectangle.setTextureRect(map[l][y][x]->GetRect());
						Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * Tile::SIZE, y * Tile::SIZE)));

						Window::Draw();
					}
				}
			}
		}
	}
	*/


	//this->DisplayLayer(Map::Layer::COLLISION);

	{
		Window::rectangle.setTexture(nullptr);

		if (FightManager::IsInFight())
		{
			FightManager::Display();
		}
		else
		{
			this->DisplayLayer(Map::Layer::BACKGROUND);

			Window::rectangle.setTexture(nullptr);
			//MapManager::Display();
			Window::rectangle.setFillColor(sf::Color(255, 255, 255));
			PawnManager::Display();
			for (std::vector<Enemy*>::iterator it = m_Enemy.begin(); it != m_Enemy.end(); it++)
			{
				Window::rectangle.setTexture(EnemyTextureManager::GetTexture((*it)->m_TextureName));
				Window::rectangle.setTextureRect(sf::IntRect(0, 0, 32, 32));
				Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
				(*it)->transform->CorrectWindowRectangle();
				Window::Draw();
			}
			//Window::text.setCharacterSize(20);
			//Window::text.setFillColor(sf::Color(255, 255, 255));
			//for (std::vector<Enemy*>::iterator it = m_Enemy.begin(); it != m_Enemy.end(); it++)
			//{
			//	Window::rectangle.setFillColor(sf::Color(255, 100, 100));
			//	(*it)->transform->CorrectWindowRectangle();
			//	Window::Draw();

			//	Window::text.setPosition((*it)->transform->getPos() + sf::Vector2f(0.f, -50.f));
			//	Window::text.setString((*it)->GetComponent<ComponentName>()->GetName());
			//	Tools::CenterTextOrigin(Window::text);
			//	Window::Draw(Window::text);
			//}

			Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
			Window::rectangle.setOrigin(sf::Vector2f());
			for (size_t i = 0; i < object.size(); i++)
			{
				object[i]->Display();
			}

			Window::rectangle.setTexture(nullptr);
			Window::rectangle.setFillColor(sf::Color(0, 0, 0, 0));
			for (Object* o : object)
			{
				if (TorchObject* t = dynamic_cast<TorchObject*>(o))
				{
					t->DisplayShader(m_DayNightSystem);
					t->DisplayParticles(m_DayNightSystem);
				}
			}
			ParticleManager::Display();

			this->DisplayLayerTransparency(Map::Layer::FOREGROUND - 1);
		}

		
	}


	Window::rectangle.setTexture(nullptr);

	m_DayNightSystem.Display();

	if (DialogueManager::IsInDialogue())
	{
		DialogueManager::Display();
	}
	else
	{
		player->GetInventory().Display();
	}


	//if (SkillTreeManager::IsInSkillTree())
	//{
	//	SkillTreeManager::Display();
	//}

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

void Game::DisplayLayer(size_t _layer)
{
	std::vector<std::vector<std::vector<Tile*>>> map = m_Map.getMap();

	Window::rectangle.setOrigin(sf::Vector2f());
	Window::rectangle.setSize(sf::Vector2f(sf::Vector2<int>(Tile::SIZE, Tile::SIZE)));
	//test
	Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
	float tmpDt = Tools::GetDeltaTime();

	size_t l = _layer;
	for (size_t y = 0; y < map[l].size(); y++)
	{
		for (size_t x = 0; x < map[l][y].size(); x++)
		{
			if (sf::Texture* tex = TileTextureManager::GetTexture(map[l][y][x]->GetTextureName()))
			{
				if (AnimTile* animTile = dynamic_cast<AnimTile*>(map[l][y][x]))
				{
					animTile->Anim(tmpDt);
				}

				Window::rectangle.setTexture(tex);
				Window::rectangle.setTextureRect(map[l][y][x]->GetRect());
				Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * Tile::SIZE, y * Tile::SIZE)));

				Window::Draw();
			}
		}
	}
}

void Game::DisplayLayerTransparency(size_t _layer)
{
	Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player"));

	if (!player)
	{
		this->DisplayLayer(_layer);
		return;
	}

	sf::Vector2f playerPos = sf::Vector2f(player->transform->getPos().x / 32.f, player->transform->getPos().y / 32.f);
	sf::Vector2f tileHSize(sf::Vector2<size_t>(Tile::SIZE / 2, Tile::SIZE / 2));

	std::vector<std::vector<std::vector<Tile*>>> map = m_Map.getMap();

	Window::rectangle.setOrigin(sf::Vector2f());
	Window::rectangle.setSize(sf::Vector2f(sf::Vector2<int>(Tile::SIZE, Tile::SIZE)));

	float tmpDt = Tools::GetDeltaTime();

	size_t l = _layer;
	for (size_t y = 0; y < map[l].size(); y++)
	{
		for (size_t x = 0; x < map[l][y].size(); x++)
		{
			if (sf::Texture* tex = TileTextureManager::GetTexture(map[l][y][x]->GetTextureName()))
			{
				if (AnimTile* animTile = dynamic_cast<AnimTile*>(map[l][y][x]))
				{
					animTile->Anim(tmpDt);
				}

				Window::rectangle.setTexture(tex);
				Window::rectangle.setTextureRect(map[l][y][x]->GetRect());
				sf::Vector2f tilePos(sf::Vector2<size_t>(x * Tile::SIZE, y * Tile::SIZE));
				Window::rectangle.setPosition(tilePos);
				bool isInMap = (playerPos.x >= 0 && playerPos.y >= 0 && playerPos.y < map[2].size() && playerPos.x < map[2][0].size());

				//sf::Vector2f centerTilePos = tilePos + tileHSize;
				if (isInMap && std::abs(playerPos.x - x) < 3 && std::abs(playerPos.y - y) < 3)
				//if (Tools::SqrMagnitude(playerPos, centerTilePos) < 6000.f)
				{
					Window::rectangle.setFillColor(sf::Color(255, 255, 255, 127));
				}
				else
				{
					Window::rectangle.setFillColor(sf::Color(255, 255, 255, 255));
				}

				Window::Draw();
			}
		}
	}
}

void Game::UpdateEnemy()
{
	Player* p = dynamic_cast<Player*>(PawnManager::GetPawn("Player"));
	if (!p)
		return;

	sf::Vector2f pPos = p->transform->getPos();

	for (std::vector<Enemy*>::iterator it = m_Enemy.begin(); it != m_Enemy.end();)
	{

		if ((Tools::SqrMagnitude((*it)->transform->getPos(), pPos) < 10000.f) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || ((*it)->transform->GetRect().contains(Window::GetMouseViewPos()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))))
		{
			FightManager::SetupFight(new Fight(p, m_Enemy));
			//it = m_Enemy.erase(it);
		}
		else {
			it++;
		}
	}
}
