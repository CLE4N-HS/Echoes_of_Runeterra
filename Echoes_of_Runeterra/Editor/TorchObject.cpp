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
	sf::RenderTexture tmp;
	//m_Pos = sf::Vector2f(400.f, 200.f);
	sf::RectangleShape rect(m_Size);
	rect.setPosition(m_Pos);

	tmp.create(m_Size.x, m_Size.y);

	tmp.draw(rect);

	sf::Texture tex = tmp.getTexture();

	Window::rectangle.setTexture(&tex, true);

	Window::rectangle.setPosition(m_Pos);
	Window::rectangle.setSize(m_Size);
	//Window::rectangle.setOrigin(Window::rectangle.getSize() * 0.5f);
	Window::rectangle.setFillColor(sf::Color(100, 0, 200, 100));
	float az = 540.f;
	sf::Glsl::Vec2 ttt(m_Pos);
	ttt.y = 1080.f - m_Pos.y;
	ttt.x += m_Size.x * 0.5f;
	ttt.y -= m_Size.y * 0.5f;
	RenderStatesManager::SetShaderUniform("torch", "lightPosition", ttt);
	//RenderStatesManager::SetShaderUniform("torch", "lightPosition", sf::Glsl::Vec2(m_Size * 0.5f));
	RenderStatesManager::SetShaderUniform("torch", "lightRadius", float(10.f));
	RenderStatesManager::SetShaderUniform("torch", "texture", tex);
	RenderStatesManager::SetShader("torch");

	Window::Draw(Window::rectangle, RenderStatesManager::RenderStates);
}

void TorchObject::DisplayParticles()
{
}
