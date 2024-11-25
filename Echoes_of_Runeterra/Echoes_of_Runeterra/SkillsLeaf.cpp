#include "SkillsLeaf.h"
#include "Window.h"

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

	Window::Draw(Window::rectangle);
}
