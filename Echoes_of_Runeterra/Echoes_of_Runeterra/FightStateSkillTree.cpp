#include "FightStateSkillTree.h"
#include "SkillTreeManager.h"
#include "Window.h"
#include "FightManager.h"
#include "FightStatePlayerChoice.h"
#include "KeyboardManager.h"

FightStateSkillTree::FightStateSkillTree()
{
}

FightStateSkillTree::~FightStateSkillTree()
{
}

void FightStateSkillTree::Update()
{
	SkillTreeManager::Update();

	if (KeyboardManager::OneTimePressed(sf::Keyboard::S))
	{
		FightManager::ChangeFightState(new FightStatePlayerChoice());
	}

}

void FightStateSkillTree::Display()
{
	SkillTreeManager::Display();

	Window::text.setPosition(100.f, 200.f);
	Window::text.setCharacterSize(30);
	Window::text.setString("Press S to return");
	Window::text.setFillColor(sf::Color(255, 255, 255));
	Window::Draw(Window::text);
}
