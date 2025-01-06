#include "TileTextureManager.h"

std::map<std::string_view, sf::Texture*> TileTextureManager::m_Texture{};

TileTextureManager::TileTextureManager()
{
}

TileTextureManager::~TileTextureManager()
{
}

bool TileTextureManager::AddTexture(std::string_view _name, std::string_view _path)
{
	sf::Texture* tex(new sf::Texture());

	if (!tex->loadFromFile(std::string(_path)))
	{
		delete tex;
		return false;
	}

	m_Texture.insert({ _name, tex });

	return true;
}

sf::Texture* TileTextureManager::GetTexture(std::string_view _name)
{
	std::map<std::string_view, sf::Texture*>::const_iterator it = m_Texture.find(_name);

	if (it == m_Texture.end())
	{
		return nullptr;
	}

	return (*it).second;
}
