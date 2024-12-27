#include "Map.h"
#include "Tile.h"
#include "AutoTile.h"
#include "SimpleTile.h"
#include "Window.h"
#include "TileTextureManager.h"

Map::Map()
{
	m_Map[0]->layer[0][0]->SetPos(sf::Vector2f(0.f, 0.f));

	size_t sizeY = 10;
	size_t sizeX = 20;

	m_Map.reserve(sizeY);
	for (size_t y = 0; y < sizeY; y++)
	{
		m_Map.push_back(std::vector<Tile*>());
		m_Map[y].reserve(sizeX);
		for (size_t x = 0; x < sizeX; x++)
		{
			m_Map[y].push_back(new SimpleTile());
		}
	}
}

Map::~Map()
{
}

void Map::Display()
{
	for (size_t y = 0; y < m_Map.size(); y++)
	{
		for (size_t x = 0; x < m_Map[y].size(); x++)
		{
			Window::rectangle.setTexture(TileTextureManager::GetTexture(m_Map[y][x]->GetTextureName()));
			Window::rectangle.setTextureRect(m_Map[y][x]->GetRect());
			Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * 32, y * 32)));
			Window::rectangle.setSize(sf::Vector2f(32.f, 32.f));
			Window::Draw();
		}
	}
}
