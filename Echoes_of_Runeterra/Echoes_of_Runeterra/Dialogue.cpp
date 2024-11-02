#include "Dialogue.h"

Dialogue::Dialogue() : m_text()
{
}

Dialogue::~Dialogue()
{
}

void Dialogue::setup(std::map<std::string, InteractionText*>& _text)
{
	m_text = _text;
}

void Dialogue::update(Window& _window)
{
	if (m_text.size() > 0) // if not then there's no dialogue
	{
		for (std::map<std::string, InteractionText*>::iterator it = m_text.begin(); it != m_text.end(); it++)
		{
			(*it).second->update(_window);
		}
	}
}

void Dialogue::display(Window& _window)
{
	if (m_text.size() > 0) // if not then there's no dialogue
	{
		_window.rectangle.setFillColor(sf::Color(0, 200, 0, 200));
		_window.rectangle.setOrigin(sf::Vector2f());
		_window.rectangle.setPosition(sf::Vector2f(50.f, 600.f));
		_window.rectangle.setSize(sf::Vector2f(1820.f, 400.f));
		_window.rectangle.setTexture(nullptr);

		_window.draw(_window.rectangle);
		_window.rectangle.setFillColor(sf::Color(255, 255, 255));

		for (std::map<std::string, InteractionText*>::iterator it = m_text.begin(); it != m_text.end(); it++)
		{
			(*it).second->display(_window);
		}
	}
}
