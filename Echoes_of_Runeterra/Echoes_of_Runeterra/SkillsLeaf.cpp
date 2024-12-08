#include "SkillsLeaf.h"
#include "Window.h"
#include "ComponentName.h"

SkillsLeaf::SkillsLeaf(Skills* _skill) : Entity(Transform(sf::Vector2f(), sf::Vector2f(50.f, 50.f))), m_skill(_skill), m_state(SkillsLeaf::State::LOCKED)
{
}

SkillsLeaf::~SkillsLeaf()
{
	delete m_skill;
}

void SkillsLeaf::Update()
{
	//m_skill->Update();
}

void SkillsLeaf::Display()
{
	this->transform->CorrectWindowRectangle();

	switch (m_state)
	{
	case SkillsLeaf::LOCKED:
		Window::rectangle.setFillColor(sf::Color(0, 0, 0));
		break;
	case SkillsLeaf::OBTAINABLE:
		Window::rectangle.setFillColor(sf::Color(255, 0, 0));
		break;
	case SkillsLeaf::ACQUIRED:
		Window::rectangle.setFillColor(sf::Color(0, 255, 0));
		break;
	default:
		Window::rectangle.setFillColor(sf::Color(255, 255, 255));
		break;
	}

	Window::Draw(Window::rectangle);

	Window::text.setCharacterSize(24);
	Window::text.setPosition(this->transform->getPos() + sf::Vector2f(0.f, -10.f));
	Window::text.setString(m_skill->GetComponent<ComponentName>()->GetName());

	Window::text.setFillColor(sf::Color(255, 255, 255));
	Window::text.setOutlineColor(sf::Color(0, 0, 0));
	Window::text.setOutlineThickness(2.f);

	Tools::CenterTextOrigin(Window::text);
	Window::Draw(Window::text);

	Window::text.setOutlineThickness(0.f);
}
