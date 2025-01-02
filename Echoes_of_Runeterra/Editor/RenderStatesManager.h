#pragma once
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/Shader.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <string>

#define SHADER_PATH "../Resources/Shader/"

class RenderStatesManager
{
public:
	RenderStatesManager();
	~RenderStatesManager();

	static bool LoadShader(const std::string& _path, sf::Shader::Type _type);
	static void SetTexture(const sf::Texture& _texture);

	static sf::RenderStates RenderStates;

};
