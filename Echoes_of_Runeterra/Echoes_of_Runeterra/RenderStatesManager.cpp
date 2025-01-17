#include "RenderStatesManager.h"

std::map<std::string_view, sf::Shader*> RenderStatesManager::Shader = {};
sf::RenderStates RenderStatesManager::RenderStates = sf::RenderStates();

RenderStatesManager::RenderStatesManager()
{
	RenderStates = sf::RenderStates();
	//RenderStates.transform = sf::Transform::Identity;
	//RenderStates.blendMode = sf::BlendAlpha;
	//RenderStates.shader = new sf::Shader();
	//RenderStates.texture = nullptr;
}

RenderStatesManager::~RenderStatesManager()
{
}

bool RenderStatesManager::LoadShader(const std::string& _path, sf::Shader::Type _type)
{
	sf::Shader* tmp = new sf::Shader();
	if (!tmp->loadFromFile(_path, _type))
	{
		delete tmp;
		return false;
	}

	delete RenderStates.shader;
	RenderStates.shader = tmp;

	return true;
}

void RenderStatesManager::SetTexture(const sf::Texture& _texture)
{
	delete RenderStates.texture;
	sf::Texture* tmp = new sf::Texture(_texture);
	RenderStates.texture = tmp;
}

bool RenderStatesManager::AddShader(std::string_view _name, std::string_view _path, sf::Shader::Type _type)
{
	std::map<std::string_view, sf::Shader*>::iterator it = Shader.find(_name);
	if (it != Shader.end())
		return false;

	sf::Shader* newShader = new sf::Shader();

	if (!newShader->loadFromFile(std::string(_path), _type))
	{
		delete newShader;
		return false;
	}

	Shader.insert({ _name, newShader});

	return true;
}

bool RenderStatesManager::SetShader(std::string_view _name)
{
	std::map<std::string_view, sf::Shader*>::iterator it = Shader.find(_name);
	if (it == Shader.end())
		return false;

	RenderStates.shader = (*it).second;

	return true;
}
