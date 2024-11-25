#include "EndButton.h"
#include "Window.h"
#include "MouseManager.h"

EndButton::EndButton(std::string _button, sf::Vector2f _pos) : InteractionText(_button, _pos)
{
	m_isVisible = false;
}

void EndButton::setup()
{
	InteractionText::setup();
	m_isVisible = false;
}

void EndButton::Update()
{
	if (m_isVisible)
	{
		if (m_rect.contains(Window::GetMousePos()))
		{
			m_isHovered = true;

			if (MouseManager::OneTimePressed())
			{
				m_hasChoosen = true;
			}
		}
		else
		{
			m_isHovered = false;
		}
	}
	//if (m_isVisible)
	//{
	//	if (m_rect.contains(_window.getMousePos()))
	//	{
	//		m_isHovered = true;

	//		if (_window.mouseManager.hasJustPressed(sf::Mouse::Left))
	//		{
	//			m_hasChoosen = true;
	//		}
	//	}
	//	else
	//	{
	//		m_isHovered = false;
	//	}
	//}
}

void EndButton::Display()
{
	if (m_isVisible)
	{
		Window::text.setPosition(transform->getPos());
		Window::text.setString(m_text);
		Window::Draw(Window::text);
		m_rect = Window::text.getGlobalBounds();

		if (m_isHovered)
		{
			Window::rectangle.setPosition(m_rect.getPosition());
			Window::rectangle.setSize(m_rect.getSize());
			Window::Draw();
		}
		//_window.text.setPosition(m_pos);
		//_window.text.setString(m_text);

		//_window.draw(_window.text);
		//m_rect = _window.text.getGlobalBounds();

		//if (m_isHovered)
		//{
		//	_window.rectangle.setPosition(m_rect.getPosition());
		//	_window.rectangle.setSize(m_rect.getSize());

		//	_window.draw(_window.rectangle);
		//}
	}
}
