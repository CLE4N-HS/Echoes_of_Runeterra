#include "TextureManager.h"

std::map<std::string_view, sf::Texture*> TextureManager::m_Texture{};

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::AddTexture(std::string_view _name, std::string_view _path)
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

sf::Texture* TextureManager::GetTexture(std::string_view _name)
{
	return m_Texture[_name];
}
