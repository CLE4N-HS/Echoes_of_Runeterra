#pragma once
#include "SFML/Graphics/Texture.hpp"
#include <map>
#include <string_view>

#define TEXTURE_PATH "../Resources/Textures/"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static bool AddTexture(std::string_view _name, std::string_view _path);
	static sf::Texture* GetTexture(std::string_view _name);

	static inline std::map<std::string_view, sf::Texture*>& Get() { return m_Texture; }

private:
	static std::map<std::string_view, sf::Texture*> m_Texture;

};
