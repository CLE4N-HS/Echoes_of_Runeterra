#pragma once
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/Shader.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <string_view>
#include <map>

#define SHADER_PATH "../Resources/Shader/"

class RenderStatesManager
{
public:
	RenderStatesManager();
	~RenderStatesManager();

	static bool LoadShader(const std::string& _path, sf::Shader::Type _type);
	static void SetTexture(const sf::Texture& _texture);

	static bool AddShader(std::string_view _name, std::string_view _path, sf::Shader::Type _type);
	static bool SetShader(std::string_view _name);

	template <typename T>
	static bool SetShaderUniform(std::string_view _name, std::string_view _dataName, T _data)
	{
		std::map<std::string_view, sf::Shader*>::iterator it = Shader.find(_name);
		if (it == Shader.end())
			return false;

		(*it).second->setUniform(std::string(_dataName), _data);
		return true;
	}

	static std::map<std::string_view, sf::Shader*> Shader;
	static sf::RenderStates RenderStates;

};
