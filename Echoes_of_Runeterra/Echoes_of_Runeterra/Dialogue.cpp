#include "Dialogue.h"

Dialogue::Dialogue() : m_text(),/* Entity(sf::Vector2f(50.f, 600.f)), */m_state(Dialogue::State::QUESTION_ANSWER)
{
}

Dialogue::~Dialogue()
{
}

void Dialogue::setup(std::map<std::string, InteractionText*>& _text)
{
	m_text = _text;
	
	for (std::map<std::string, InteractionText*>::iterator it = m_text.begin(); it != m_text.end(); it++)
	{
		it->second->setup();
	}

	m_state = Dialogue::State::QUESTION_ANSWER;
}

bool Dialogue::isInDialogue()
{
	return (m_text.size() > 0);
}

void Dialogue::update(Window& _window)
{
	if (m_text.size() > 0) // if not then there's no dialogue
	{
		int answerIndex(0);
		for (std::map<std::string, InteractionText*>::iterator it = m_text.begin(); it != m_text.end(); it++)
		{
			answerIndex++;
			it->second->update(_window);
			if (it->second->hasChoosen())
			{
				it->second->resetChoice();
				if (m_state == Dialogue::State::QUESTION_ANSWER)
				{
					m_state = Dialogue::State::COMMENT;
					for (std::map<std::string, InteractionText*>::iterator it2 = m_text.begin(); it2 != m_text.end(); it2++)
					{
						if (it2->first[0] == 'Q' || it2->first[0] == 'A')
						{
							it2->second->setVisibility(false);
						}
						else if ((it2->first[0] == 'C' && it2->first[1] == answerIndex + 48) || it2->first[0] == 'E')
						{
							it2->second->setVisibility(true);
						}
					}
				}
				else if (m_state == Dialogue::State::COMMENT)
				{
					m_state = Dialogue::State::END;
					m_text.clear();
					break;
				}
			}
		}
	}
}

void Dialogue::display(Window& _window)
{
	//if (m_text.size() > 0) // if not then there's no dialogue
	//{
	//	_window.rectangle.setFillColor(sf::Color(0, 200, 0, 200));
	//	_window.rectangle.setOrigin(sf::Vector2f());
	//	_window.rectangle.setPosition(m_pos);
	//	_window.rectangle.setSize(sf::Vector2f(1820.f, 400.f));
	//	_window.rectangle.setTexture(nullptr);

	//	_window.draw(_window.rectangle);

	//	// text
	//	_window.text.setFillColor(sf::Color::White);
	//	_window.text.setCharacterSize(30);
	//	_window.text.setOrigin(sf::Vector2f());

	//	_window.rectangle.setFillColor(sf::Color(255, 255, 255, 100));
	//	for (std::map<std::string, InteractionText*>::iterator it = m_text.begin(); it != m_text.end(); it++)
	//	{
	//		it->second->display(_window);
	//	}

	//	_window.rectangle.setFillColor(sf::Color(255, 255, 255));
	//}
}
