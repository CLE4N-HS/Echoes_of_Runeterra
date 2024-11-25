#include "Npc.h"
#include "textureManager.h"
#include "Window.h"
#include "ComponentName.h"
#include "DialogueManager.h"
#include "MouseManager.h"
#include "CharacterManager.h"
#include "Player.h"

Npc::Npc() : Npc("Npc", "")
{
}

Npc::Npc(std::string _name, std::string _dialogueKey) : Pawn(_name, _dialogueKey)
{
	this->transform->setSize(sf::Vector2f(50.f, 50.f));
	this->transform->setOrigin(this->transform->getSize() * 0.5f);
}

Npc::~Npc()
{
}

void Npc::Update()
{
	const sf::Vector2f mousePos = Window::GetMousePos();

	if (Player* player = dynamic_cast<Player*>(PawnManager::GetPawn("Player")))
	{
		if (Tools::SqrMagnitude(player->transform->getPos(), this->transform->getPos()) < 40000.f && this->transform->GetRect().contains(mousePos) && MouseManager::OneTimePressed())
		{
			DialogueManager::SetupDialogue(m_dialogueKey);
		}
	}
}

void Npc::Display()
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

	//_window.rectangle.setPosition(sf::Vector2f());
	//_window.rectangle.setTexture(tex_getTexture("viego"));
	//_window.rectangle.setSize(m_size);
	//_window.rectangle.setOrigin(m_origin);
	//_window.rectangle.setTextureRect(texGetRectAnim(_window, "viego", m_animState.c_str(), &m_frameX, &m_animTimer));
	//if (m_animState == "walk" && m_foward.x < 0.f)
	//	_window.rectangle.setScale(sf::Vector2f(m_scale.x * -1.f, m_scale.y));
	//else
	//	_window.rectangle.setScale(m_scale);

	//_window.draw(_window.rectangle);

	//char buffer[100]{};
	//_window.text.setCharacterSize(30);
	//_window.text.setFillColor(sf::Color::White);

	//_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 20.f));
	//sprintf(buffer, "Level : %d", m_level);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//_window.text.setPosition(m_pos + sf::Vector2f(-60.f, 50.f));
	//sprintf(buffer, "Xp : %d/%d", m_xp, m_levelXp);
	//_window.text.setString(buffer);
	//_window.draw(_window.text);

	//if (m_isHovered)
	//{
	//	_window.rectangle.setOrigin(m_origin);
	//	_window.rectangle.setPosition(m_pos);
	//	_window.rectangle.setSize(m_size);
	//	_window.rectangle.setScale(m_scale);
	//	_window.rectangle.setTexture(nullptr);
	//	_window.rectangle.setFillColor(sf::Color(255, 255, 255, 100));

	//	_window.draw(_window.rectangle);
	//}

	//_window.rectangle.setFillColor(sf::Color(255, 255, 255));
	//_window.rectangle.setScale(sf::Vector2f(1.f, 1.f));
}
;