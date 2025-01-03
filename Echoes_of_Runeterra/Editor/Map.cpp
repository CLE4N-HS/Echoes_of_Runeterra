#include "Map.h"
#include "Tile.h"
#include "AutoTile.h"
#include "SimpleTile.h"
#include "Window.h"

#include "TileTextureManager.h"
#include "TorchObject.h"
#include "ChestObject.h"

#include "Externals/json.hpp"

Map::Map()
{
	DefaultMap();
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

	// Map
	{
		size_t lSize = m_Map.size();
		size_t ySize = m_Map[0].size();
		size_t xSize = m_Map[0][0].size();

		j["Map"]["Size"]["L"] = lSize;
		j["Map"]["Size"]["Y"] = ySize;
		j["Map"]["Size"]["X"] = xSize;

		for (size_t l = 0; l < lSize; l++)
		{
			std::string lToS = std::to_string(l);
			std::string lStmp("Layer " + lToS);
			const char* lS = lStmp.c_str();
			for (size_t y = 0; y < ySize; y++)
			{
				std::string yToS = std::to_string(y);
				std::string yStmp("Y " + std::string(3 - yToS.length(), '0') + yToS);
				const char* yS = yStmp.c_str();
				for (size_t x = 0; x < xSize; x++)
				{
					std::string xToS = std::to_string(x);
					std::string xStmp("X " + std::string(3 - xToS.length(), '0') + xToS);
					const char* xS = xStmp.c_str();

					if (SimpleTile* simpleTile = dynamic_cast<SimpleTile*>(m_Map[l][y][x]))
						j["Map"][lS][yS][xS]["SimpleTile"] = m_Map[l][y][x]->ToJson();
				}
			}
		}
	}

	// Object
	{
		size_t oSize = m_Object.size();
		std::string oSizeToS = std::to_string(oSize);

		j["Object"]["Size"] = oSize;

		for (size_t i = 0; i < oSize; i++)
		{
			std::string iToS = std::to_string(i);
			std::string iStmp(std::string(oSizeToS.length() - iToS.length(), '0') + iToS);
			const char* iS = iStmp.c_str();

			std::string objStmp("");
			if (TorchObject* torchObject = dynamic_cast<TorchObject*>(m_Object[i]))
				objStmp = "TorchObject";
			else if (ChestObject* chestObject = dynamic_cast<ChestObject*>(m_Object[i]))
				objStmp = "ChestObject";

			const char* objS = objStmp.c_str();

			j["Object"][iS][objS] = m_Object[i]->ToJson();
		}
	}
	
	_file << j.dump(4);
}

void Map::Load(std::ifstream& _file)
{
	DeinitMap();

	nlohmann::json j;

	_file >> j;

	size_t sizeL = j["Map"]["Size"]["L"];
	size_t sizeY = j["Map"]["Size"]["Y"];
	size_t sizeX = j["Map"]["Size"]["X"];

	m_Map.reserve(sizeL);
	for (size_t l = 0; l < sizeL; l++)
	{
		std::string lToS = std::to_string(l);
		std::string lStmp("Layer " + lToS);
		const char* lS = lStmp.c_str();

		m_Map.push_back(std::vector<std::vector<Tile*>>());
		m_Map[l].reserve(sizeY);
		for (size_t y = 0; y < sizeY; y++)
		{
			std::string yToS = std::to_string(y);
			std::string yStmp("Y " + std::string(3 - yToS.length(), '0') + yToS);
			const char* yS = yStmp.c_str();

			m_Map[l].push_back(std::vector<Tile*>());
			m_Map[l][y].reserve(sizeX);
			for (size_t x = 0; x < sizeX; x++)
			{
				std::string xToS = std::to_string(x);
				std::string xStmp("X " + std::string(3 - xToS.length(), '0') + xToS);
				const char* xS = xStmp.c_str();

				if (j["Map"][lS][yS][xS].contains("SimpleTile"))
				{
					m_Map[l][y].push_back(new SimpleTile());
					m_Map[l][y][x]->FromJson(j["Map"][lS][yS][xS]["SimpleTile"]);
				}
			}
		}
	}

	size_t oSize = j["Object"]["Size"];
	std::string oSizeToS = std::to_string(oSize);

	for (size_t i = 0; i < oSize; i++)
	{
		std::string iToS = std::to_string(i);
		std::string iStmp(std::string(oSizeToS.length() - iToS.length(), '0') + iToS);
		const char* iS = iStmp.c_str();

		if (j["Object"][iS].contains("TorchObject"))
		{
			m_Object.push_back(new TorchObject());
			m_Object[i]->FromJson(j["Object"][iS]["TorchObject"]);
		}
		else if (j["Object"][iS].contains("ChestObject"))
		{
			m_Object.push_back(new ChestObject());
			m_Object[i]->FromJson(j["Object"][iS]["ChestObject"]);
		}
	}
}

void Map::DeinitMap()
{
	while (m_Map.size() > 0)
	{
		while (m_Map[0].size() > 0)
		{
			while (m_Map[0][0].size() > 0)
			{
				delete m_Map[0][0][0];
				m_Map[0][0].erase(m_Map[0][0].begin());
			}
			m_Map[0].erase(m_Map[0].begin());
		}
		m_Map.erase(m_Map.begin());
	}

	while (m_Object.size() > 0)
	{
		delete m_Object[0];
		m_Object.erase(m_Object.begin());
	}
}

void Map::DefaultMap()
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
				if (l == 0)
				{
					m_Map[l][y].push_back(new SimpleTile());
					m_Map[l][y][x]->SetTextureName("tileset");
					m_Map[l][y][x]->SetRect(sf::IntRect(64, 0, 32, 32));
				}
				else
				{
					m_Map[l][y].push_back(new SimpleTile());
				}
			}
		}
	}
}
