#include "TileAutoDatabase.h"
#include "TileAuto.h"

TileAutoDatabase::TileAutoDatabase()
{
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::VOID));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::UP, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::DIRT), TileAuto::Direction::UP_LEFT, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::RIGHT, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::DOWN, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::LEFT, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::UP_RIGHT, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::DOWN_RIGHT, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::DOWN_LEFT, Tile::Type::DIRT));
	AddTileAuto(new TileAuto(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), TileAuto::Direction::UP_LEFT, Tile::Type::DIRT));
}

TileAutoDatabase::~TileAutoDatabase()
{
}

uint32_t TileAutoDatabase::GetId(const TileAuto* const& _tileAuto)
{
	return uint32_t((_tileAuto->GetType() << 0) + (_tileAuto->GetInside() << 8) + (_tileAuto->GetOutside() << 16));
}

void TileAutoDatabase::AddTileAuto(TileAuto* _tileAuto)
{
	m_TileAuto.insert({ GetId(_tileAuto), _tileAuto});
}
