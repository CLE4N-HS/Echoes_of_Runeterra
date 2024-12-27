#include "MapEdit.h"
#include "SimpleTile.h"

MapEdit::MapEdit(std::vector<std::vector<Tile*>>* _map) : m_Map(_map)
{
}

MapEdit::~MapEdit()
{
}

sf::Vector2i MapEdit::TilePos(sf::Vector2f _pos)
{
	sf::Vector2i tmp(sf::Vector2f(_pos.x - (*m_Map)[0][0]->GetPos().x, _pos.y - (*m_Map)[0][0]->GetPos().y));
	return sf::Vector2i(tmp.x / Tile::SIZE, tmp.y / Tile::SIZE);
}

bool MapEdit::IsInMap(sf::Vector2i _pos)
{
	return (_pos.x >= 0 && _pos.y >= 0 && _pos.y < (*m_Map).size() && _pos.x < (*m_Map)[0].size());
}

bool MapEdit::EditTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect)
{
	sf::Vector2i tilePos = this->TilePos(_pos);
	if (!(this->IsInMap(tilePos)))
		return false;

	(*m_Map)[tilePos.y][tilePos.x]->SetTextureName(_textureName);
	(*m_Map)[tilePos.y][tilePos.x]->SetRect(_rect);

	return true;
}

void MapEdit::Resize(sf::Vector2<size_t> _size)
{
	// Add Y
	for (size_t y = (*m_Map).size() - 1; y < _size.y - 1; y++)
	{
		(*m_Map).push_back(std::vector<Tile*>());
		size_t nbX = (*m_Map)[y].size();
		for (size_t x = 0; x < nbX; x++)
		{
			(*m_Map)[y + 1].push_back(new SimpleTile());
		}
	}

	// Add X
	for (size_t x = (*m_Map)[0].size() - 1; x < _size.x - 1; x++)
	{
		for (size_t y = 0; y < (*m_Map).size(); y++)
		{
			(*m_Map)[y].push_back(new SimpleTile());
		}
	}

	// Remove Y
	for (size_t y = (*m_Map).size() - 1; y > _size.y - 1; y--)
	{
		for (size_t x = 0; (*m_Map)[y].begin() != (*m_Map)[y].end();)
		{
			delete (*m_Map)[y][x];
			std::vector<Tile*>::iterator it2 = (*m_Map)[y].begin();
			(*m_Map)[y].erase(it2);
		}
		std::vector<std::vector<Tile*>>::iterator it1 = (*m_Map).begin() + y;
		(*m_Map).erase(it1);
	}

	// Remove X
	for (size_t x = (*m_Map)[0].size() - 1; x > _size.x - 1; x--)
	{
		size_t nbY = (*m_Map).size();
		for (size_t y = 0; y < nbY; y++)
		{
			delete (*m_Map)[y][x];
			std::vector<Tile*>::iterator it2 = (*m_Map)[y].begin() + x;
			(*m_Map)[y].erase(it2);
		}
	}

}
