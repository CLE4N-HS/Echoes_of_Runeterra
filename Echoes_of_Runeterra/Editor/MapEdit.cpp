#include "MapEdit.h"
#include "SimpleTile.h"
#include "Editor.h"
#include "TorchObject.h"
#include "ChestObject.h"
#include "AnimTile.h"

MapEdit::MapEdit(std::vector<std::vector<std::vector<Tile*>>>* _map, std::vector<Object*>* _object) : m_Map(_map), m_Object(_object)
{
}

MapEdit::~MapEdit()
{
}

sf::Vector2i MapEdit::TilePos(sf::Vector2f _pos)
{
	//sf::Vector2i tmp(sf::Vector2f(_pos.x - (*m_Map)[m_Layer][0][0]->GetPos().x, _pos.y - (*m_Map)[m_Layer][0][0]->GetPos().y));

	// assuming the map is in 0,0
	sf::Vector2i tmp(_pos);
	return sf::Vector2i(tmp.x / Tile::SIZE, tmp.y / Tile::SIZE);
}

bool MapEdit::IsInMap(sf::Vector2i _pos)
{
	Map::Layer currentLayer = m_Layer;
	if (currentLayer == Map::Layer::FOREGROUND)
		currentLayer = Map::Layer::OBJECT;

	return (_pos.x >= 0 && _pos.y >= 0 && _pos.y < (*m_Map)[currentLayer].size() && _pos.x < (*m_Map)[currentLayer][0].size());
}

bool MapEdit::EditTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect, Tile::Type _type)
{
	if (m_Layer == Map::Layer::OBJECT)
		return false;

	Map::Layer currentLayer = m_Layer;
	if (currentLayer == Map::Layer::FOREGROUND)
		currentLayer = Map::Layer::OBJECT;

	sf::Vector2i tilePos = this->TilePos(_pos);
	if (!(this->IsInMap(tilePos)))
		return false;

	SimpleTile* simpleTile = dynamic_cast<SimpleTile*>((*m_Map)[currentLayer][tilePos.y][tilePos.x]);
	if (!simpleTile)
	{
		delete (*m_Map)[currentLayer][tilePos.y][tilePos.x];
		(*m_Map)[currentLayer][tilePos.y][tilePos.x] = new SimpleTile();
	}

	(*m_Map)[currentLayer][tilePos.y][tilePos.x]->SetTextureName(_textureName);
	(*m_Map)[currentLayer][tilePos.y][tilePos.x]->SetRect(_rect);
	(*m_Map)[currentLayer][tilePos.y][tilePos.x]->GetType() = _type;

	return true;
}

bool MapEdit::EditAnimTile(sf::Vector2f _pos, std::string_view _textureName, sf::IntRect _rect, Tile::Type _type, int _frameX, float _animSpeed)
{
	if (m_Layer == Map::Layer::OBJECT)
		return false;

	Map::Layer currentLayer = m_Layer;
	if (currentLayer == Map::Layer::FOREGROUND)
		currentLayer = Map::Layer::OBJECT;

	sf::Vector2i tilePos = this->TilePos(_pos);
	if (!(this->IsInMap(tilePos)))
		return false;

	AnimTile* animTile = dynamic_cast<AnimTile*>((*m_Map)[currentLayer][tilePos.y][tilePos.x]);
	if (!animTile)
	{
		delete (*m_Map)[currentLayer][tilePos.y][tilePos.x];
		(*m_Map)[currentLayer][tilePos.y][tilePos.x] = new AnimTile();
		animTile = dynamic_cast<AnimTile*>((*m_Map)[currentLayer][tilePos.y][tilePos.x]);
	}

	animTile->GetMaxFrameX() = _frameX;
	animTile->GetAnimSpeed() = _animSpeed;

	if (_textureName == "animTile")
	{
		_textureName = "water";
	}

	(*m_Map)[currentLayer][tilePos.y][tilePos.x]->SetTextureName(_textureName);
	(*m_Map)[currentLayer][tilePos.y][tilePos.x]->SetRect(_rect);
	(*m_Map)[currentLayer][tilePos.y][tilePos.x]->GetType() = _type;

	return true;
}

bool MapEdit::EditObject(sf::Vector2f _pos, std::string_view _textureName, sf::Vector2f _size, int _texture)
{
	//sf::Vector2i objectPos = this->TilePos(_pos);
	//if (!(this->IsInMap(objectPos)))
	//	return false;

	switch (_texture)
	{
	case Editor::Texture::TORCH:
		(*m_Object).push_back(new TorchObject(_pos, _size, _textureName)); break;
	case Editor::Texture::CHEST:
		(*m_Object).push_back(new ChestObject(_pos, _size, _textureName)); break;
	default:
		break;
	}

	return true;
}

bool MapEdit::EraseTile(sf::Vector2f _pos)
{
	if (m_Layer == Map::Layer::OBJECT)
		return false;

	Map::Layer currentLayer = m_Layer;
	if (currentLayer == Map::Layer::FOREGROUND)
		currentLayer = Map::Layer::OBJECT;

	sf::Vector2i tilePos = this->TilePos(_pos);
	if (!(this->IsInMap(tilePos)))
		return false;

	delete (*m_Map)[currentLayer][tilePos.y][tilePos.x];
	(*m_Map)[currentLayer][tilePos.y][tilePos.x] = new SimpleTile();

	return true;
}

bool MapEdit::EraseObject(sf::Vector2f _pos)
{
	for (std::vector<Object*>::iterator it = (*m_Object).begin(); it != (*m_Object).end();)
	{
		if (sf::FloatRect((*it)->GetPos(), (*it)->GetSize()).contains(_pos))
		{
			delete (*it);
			it = (*m_Object).erase(it);
		}
		else
		{
			it++;
		}
	}

	return true;
}

void MapEdit::Resize(sf::Vector2<size_t> _size)
{
	// Add Y
	for (size_t l = 0; l < (*m_Map).size(); l++)
	{
		for (size_t y = (*m_Map)[l].size() - 1; y < _size.y - 1; y++)
		{
			(*m_Map)[l].push_back(std::vector<Tile*>());
			size_t nbX = (*m_Map)[l][y].size();
			for (size_t x = 0; x < nbX; x++)
			{
				(*m_Map)[l][y + 1].push_back(new SimpleTile());
			}
		}
	}

	// Add X
	for (size_t l = 0; l < (*m_Map).size(); l++)
	{
		for (size_t x = (*m_Map)[l][0].size() - 1; x < _size.x - 1; x++)
		{
			for (size_t y = 0; y < (*m_Map)[l].size(); y++)
			{
				(*m_Map)[l][y].push_back(new SimpleTile());
			}
		}
	}


	// Remove Y
	for (size_t l = 0; l < (*m_Map).size(); l++)
	{
		for (size_t y = (*m_Map)[l].size() - 1; y > _size.y - 1; y--)
		{
			for (size_t x = 0; (*m_Map)[l][y].begin() != (*m_Map)[l][y].end();)
			{
				delete (*m_Map)[l][y][x];
				std::vector<Tile*>::iterator it2 = (*m_Map)[l][y].begin();
				(*m_Map)[l][y].erase(it2);
			}
			std::vector<std::vector<Tile*>>::iterator it1 = (*m_Map)[l].begin() + y;
			(*m_Map)[l].erase(it1);
		}
	}


	// Remove X
	for (size_t l = 0; l < (*m_Map).size(); l++)
	{
		for (size_t x = (*m_Map)[l][0].size() - 1; x > _size.x - 1; x--)
		{
			size_t nbY = (*m_Map)[l].size();
			for (size_t y = 0; y < nbY; y++)
			{
				delete (*m_Map)[l][y][x];
				std::vector<Tile*>::iterator it2 = (*m_Map)[l][y].begin() + x;
				(*m_Map)[l][y].erase(it2);
			}
		}
	}


}

void MapEdit::SetLayer(Map::Layer _layer)
{
	m_Layer = _layer;
}
