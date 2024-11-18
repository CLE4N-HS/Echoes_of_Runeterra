#include "SkillsLeaf.h"
#include "Window.h"

SkillsLeaf::SkillsLeaf(Skills* _skill) : m_skill(_skill), m_state(SkillsLeaf::State::LOCKED)
{
	this->transform->setSize(sf::Vector2f(50.f, 50.f));
	this->transform->setOrigin(transform->getSize() * 0.5f);
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
	Window::rectangle.setPosition(this->transform->getPos());
	Window::rectangle.setSize(this->transform->getSize());
	Window::rectangle.setOrigin(this->transform->getOrigin());
	Window::rectangle.setScale(this->transform->getScale());

	Window::Draw(Window::rectangle);
}
