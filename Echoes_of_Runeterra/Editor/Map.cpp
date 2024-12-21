#include "Map.h"
#include "Tile.h"
#include "AutoTile.h"
#include "SimpleTile.h"
#include "Window.h"

Map::Map()
{
	size_t sizeY = 20;
	size_t sizeX = 10;

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
			Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(y * 32, x * 32)));
			Window::rectangle.setSize(sf::Vector2f(32.f, 32.f));
			Window::Draw();
		}
	}
}
