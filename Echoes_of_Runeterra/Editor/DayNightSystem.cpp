#include "DayNightSystem.h"
#include "Tools.h"
#include "Window.h"

DayNightSystem::DayNightSystem() : m_Shader(new sf::Shader()), m_RenderStates()
{
	m_Shader->loadFromFile("../Resources/Shader/test.frag", sf::Shader::Fragment);
}

DayNightSystem::~DayNightSystem()
{
	delete m_Shader;
}

void DayNightSystem::Update()
{
	float dt = Tools::GetDeltaTime();

	m_Coefficient = std::max(0, m_Coefficient);
	m_Coefficient = std::min(10000, m_Coefficient);

	m_Second += dt * static_cast<float>(m_Coefficient);
	
	while (m_Second >= 60.f)
	{
		m_Minute += 1;
		m_Second -= 60.f;
	}
	
	while (m_Minute >= 60)
	{
		m_Hour += 1;
		m_Minute -= 60;
	}
	
	if (m_Hour >= 24)
	{
		m_Hour = 0;
	}

	float uTime = static_cast<float>(m_Hour) + static_cast<float>(m_Minute) / 60.f;
	m_Shader->setUniform("u_time", uTime);
}

void DayNightSystem::Display()
{
	Window::SetView(true);
	Window::rectangle.setPosition(sf::Vector2f(0.f, 0.f));
	Window::rectangle.setSize(Window::view.getSize());
	Window::rectangle.setOrigin(sf::Vector2f(0.f, 0.f));
	Window::rectangle.setTexture(nullptr);
	Window::rectangle.setFillColor(sf::Color(255, 255, 255, 0));
	m_RenderStates.shader = m_Shader;
	Window::Draw(Window::rectangle, m_RenderStates);
}