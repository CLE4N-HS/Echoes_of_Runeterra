#include "TorchObject.h"
#include "Window.h"
#include "RenderStatesManager.h"
#include "ParticleManager.h"

TorchObject::TorchObject() : Object()
{
}

TorchObject::TorchObject(sf::Vector2f _pos, sf::Vector2f _size, std::string_view _textureName) : Object(_pos, _size, _textureName)
{
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
	// Update ik
	m_ParticleTime += Tools::GetDeltaTime();

	if (m_ParticleTime > m_TimeToParticle)
	{
		m_ParticleTime = randomFloat(0.0f, m_TimeToParticle * 0.5f);

		Particle* newParticle = new Particle();
		newParticle->pos = sf::Vector2f( sf::Vector2f(m_Pos + m_Size * 0.5f) + sf::Vector2f(randomFloat(-m_Size.x * 0.5f, m_Size.x * 0.5f), randomFloat(-m_Size.y * 0.25f, m_Size.y * 0.25f)));
		newParticle->size = sf::Vector2f(10.f, 10.f);
		newParticle->origin = newParticle->size * 0.5f;
		newParticle->velocity = sf::Vector2f(0.f, -100.f);
		newParticle->startColor = sf::Color(255, 0, 0, 255);
		newParticle->endColor = sf::Color(255, 255, 0, 0);
		newParticle->color = newParticle->startColor;
		newParticle->timeToDie = 1.f;
		ParticleManager::Add(newParticle);
	}

}

nlohmann::json TorchObject::ToJson()
{
	nlohmann::json j;

	j["Position"] = { m_Pos.x, m_Pos.y };
	j["Size"] = { m_Size.x, m_Size.y };
	j["TextureName"] = m_TextureName;

	return j;
}

void TorchObject::FromJson(const nlohmann::json& _j)
{
	m_Pos = sf::Vector2f(_j["Position"][0], _j["Position"][1]);
	m_Size = sf::Vector2f(_j["Size"][0], _j["Size"][1]);
	m_TextureName = _j["TextureName"];
}
