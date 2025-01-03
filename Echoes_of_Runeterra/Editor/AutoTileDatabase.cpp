#include "AutoTileDatabase.h"
#include "AutoTile.h"

AutoTileDatabase::AutoTileDatabase()
{
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::VOID));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::UP, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::DIRT),  AutoTile::Direction::UP_LEFT, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::RIGHT, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::DOWN, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::LEFT, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::UP_RIGHT, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::DOWN_RIGHT, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::DOWN_LEFT, Tile::Type::DIRT));
	//AddAutoTile(new AutoTile(Tile(sf::IntRect(), sf::Vector2f(), Tile::Type::GRASS), AutoTile::Direction::UP_LEFT, Tile::Type::DIRT));
}

AutoTileDatabase::~AutoTileDatabase()
{
}

uint32_t AutoTileDatabase::GetId(const AutoTile* const& _autoTile)
{
	return uint32_t((_autoTile->getType() << 0) + (_autoTile->GetInside() << 8) + (_autoTile->GetOutside() << 16));
}

void AutoTileDatabase::AddAutoTile(AutoTile* _autoTile)
{
	m_AutoTile.insert({ GetId(_autoTile), _autoTile });
}
