#include "MapEdit.h"

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
