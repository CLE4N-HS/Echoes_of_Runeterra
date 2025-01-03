#include "TorchObject.h"
#include "Window.h"
#include "ObjectTextureManager.h"
#include "RenderStatesManager.h"

TorchObject::TorchObject() : Object()
{
}

TorchObject::TorchObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName) : Object(_pos, _size, _textureName)
{
	RenderStatesManager::AddShader("torch", SHADER_PATH "torch.frag", sf::Shader::Type::Fragment);
	RenderStatesManager::AddShader("sim", SHADER_PATH "sim.frag", sf::Shader::Type::Fragment);
}

TorchObject::~TorchObject()
{
}

void TorchObject::Display()
{
	this->SetupDraw();

	Window::Draw();
}

void TorchObject::DisplayShader(DayNightSystem& _system)
{
	float factor = 1080.f / Window::view.getSize().y;
	float size = m_Size.x * 4.f;
	float halfSize = size * 0.5f;
	sf::Vector2f centerPos(m_Pos + m_Size * 0.5f);
	
	Window::rectangle.setPosition(centerPos);
	Window::rectangle.setSize(sf::Vector2f(size, size));
	Window::rectangle.setOrigin(Window::rectangle.getSize() * 0.5f);
	Window::rectangle.setFillColor(sf::Color(0, 0, 0, 0));

	sf::Glsl::Vec2 lightPos(Window::ScreenPos(centerPos));
	lightPos.y = 1080.f - lightPos.y;

	RenderStatesManager::SetShaderUniform("torch", "lightPosition", lightPos);
	RenderStatesManager::SetShaderUniform("torch", "lightRadius", halfSize * factor);
	RenderStatesManager::SetShaderUniform("torch", "lightIntensity", _system.GetNormalizedTime());
	RenderStatesManager::SetShader("torch");

	Window::Draw(Window::rectangle, RenderStatesManager::RenderStates);
}

void TorchObject::DisplayParticles()
{
}
