#include "Talker.h"
#include "Window.h"
#include "ComponentName.h"
#include "DialogueManager.h"
#include "MouseManager.h"
#include "CharacterManager.h"
#include "Player.h"

Talker::Talker() : Talker("Default Talker", "")
{
}

Talker::Talker(const std::string& _name, const std::string& _dialogueKey) : Npc(_name), m_dialogueKey(_dialogueKey)
{
	this->AddComponent<ComponentName>(_name);
}

Talker::~Talker()
{
}

void Talker::Update()
{
	const sf::Vector2f mousePos = Window::GetMouseViewPos();
	if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
	{
		if (Tools::SqrMagnitude(player->transform->getPos(), this->transform->getPos()) < 10000.f && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) || (this->transform->GetRect().contains(mousePos) &&  sf::Mouse::isButtonPressed(sf::Mouse::Left)) /*MouseManager::OneTimePressed()*/))
		{
			DialogueManager::SetupDialogue(m_dialogueKey);
		}
	}
}

void Talker::Display()
{
	Window::rectangle.setFillColor(sf::Color(0, 255, 0));
	this->transform->CorrectWindowRectangle();
	Window::Draw();

	Window::text.setFillColor(sf::Color(255, 255, 255));
	Window::text.setCharacterSize(30);

	Window::text.setPosition(this->transform->getPos() + sf::Vector2f(0.f, -this->transform->getSize().y * 0.9f));
	Window::text.setString(this->GetComponent<ComponentName>()->GetName());
	Window::text.setStyle(sf::Text::Style::Underlined);
	Tools::CenterTextOrigin(Window::text);
	Window::Draw(Window::text);

	Window::text.setStyle(sf::Text::Style::Regular);
}
