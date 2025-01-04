#include "MapFighterManager.h"
#include "Window.h"
#include "CharacterManager.h"
#include "Player.h"
#include "FightManager.h"
#include "ComponentName.h"
#include "EnemyDatabase.h"

MapFighterManager::MapFighterManager()
{
}

MapFighterManager::~MapFighterManager()
{
	// TODO clear
}

void MapFighterManager::Update()
{
	const sf::Vector2f mousePos = Window::GetMouseViewPos();

	Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player"));

	for (std::list<MapFighter*>::iterator it = m_mapFighter.begin(); it != m_mapFighter.end();)
	{
		if (player && player->transform->GetRect().intersects((*it)->m_fighter->transform->GetRect()))
		{
			FightManager::SetupFight(new Fight(player, std::vector<Enemy*>{EnemyDatabase::CreateNewEnemy(dynamic_cast<Enemy*>((*it)->m_fighter)),
				EnemyDatabase::CreateNewEnemy(dynamic_cast<Enemy*>((*it)->m_fighter)),
				EnemyDatabase::CreateNewEnemy(dynamic_cast<Enemy*>((*it)->m_fighter))}));
			delete (*it)->m_fighter;
			it = m_mapFighter.erase(it);
			continue;
		}

		it++;
	}

}

void MapFighterManager::Display()
{
	Window::text.setCharacterSize(20);
	Window::text.setFillColor(sf::Color(255, 255, 255));
	for (std::list<MapFighter*>::iterator it = m_mapFighter.begin(); it != m_mapFighter.end(); it++)
	{
		Window::rectangle.setFillColor(sf::Color(255, 100, 100));
		(*it)->m_fighter->transform->CorrectWindowRectangle();
		Window::Draw();

		Window::text.setPosition((*it)->m_fighter->transform->getPos() + sf::Vector2f(0.f, -50.f));
		Window::text.setString((*it)->m_fighter->GetComponent<ComponentName>()->GetName());
		Tools::CenterTextOrigin(Window::text);
		Window::Draw(Window::text);
	}
}

void MapFighterManager::AddFighter(MapFighter* _fighter, Transform _transform)
{
	if (_fighter)
	{
		m_mapFighter.push_back(_fighter);
		*m_mapFighter.back()->m_fighter->transform = _transform;
	}
}
