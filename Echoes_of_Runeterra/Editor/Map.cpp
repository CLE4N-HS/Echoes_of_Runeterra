#include "Map.h"
#include "Tile.h"
#include "AutoTile.h"
#include "SimpleTile.h"
#include "Window.h"
#include "TileTextureManager.h"

#include "Externals/json.hpp"

Map::Map()
{
	size_t sizeL = Map::Layer::COUNT;
	size_t sizeY = 10;
	size_t sizeX = 20;

	m_Map.reserve(sizeL);
	for (size_t l = 0; l < sizeL; l++)
	{
		m_Map.push_back(std::vector<std::vector<Tile*>>());
		m_Map[l].reserve(sizeY);
		for (size_t y = 0; y < sizeY; y++)
		{
			m_Map[l].push_back(std::vector<Tile*>());
			m_Map[l][y].reserve(sizeX);
			for (size_t x = 0; x < sizeX; x++)
			{
				m_Map[l][y].push_back(new SimpleTile());
			}
		}
	}
}

Map::~Map()
{
}

void Map::Display()
{
	//for (size_t l = 0; l < m_Map.size(); l++)
	//{
	//	for (size_t y = 0; y < m_Map.size(); y++)
	//	{
	//		for (size_t x = 0; x < m_Map[y].size(); x++)
	//		{
	//			Window::rectangle.setTexture(TileTextureManager::GetTexture(m_Map[y][x]->GetTextureName()));
	//			Window::rectangle.setTextureRect(m_Map[y][x]->GetRect());
	//			Window::rectangle.setPosition(sf::Vector2f(sf::Vector2<size_t>(x * 32, y * 32)));
	//			Window::rectangle.setSize(sf::Vector2f(32.f, 32.f));
	//			Window::Draw();
	//		}
	//	}
	//}
}

void Map::Save(std::ostream& _file)
{
	nlohmann::json j;

	size_t lSize = m_Map.size();
	size_t ySize = m_Map[0].size();
	size_t xSize = m_Map[0][0].size();

	j["Size"]["L"] = lSize;
	j["Size"]["Y"] = ySize;
	j["Size"]["X"] = xSize;

	for (size_t l = 0; l < lSize; l++)
	{
		std::string lStmp = std::to_string(l);
		const char* lS = lStmp.c_str();
		for (size_t y = 0; y < ySize; y++)
		{
			std::string yStmp = std::to_string(y);
			const char* yS = yStmp.c_str();
			for (size_t x = 0; x < xSize; x++)
			{
				std::string xStmp = std::to_string(x);
				const char* xS = xStmp.c_str();

				if (SimpleTile* simpleTile = dynamic_cast<SimpleTile*>(m_Map[l][y][x]))
					j[lS][yS][xS]["SimpleTile"] = m_Map[l][y][x]->ToJson();
			}
		}
	}
	
	_file << j.dump(4);
}

void Map::Load(std::ifstream& _file)
{
}
