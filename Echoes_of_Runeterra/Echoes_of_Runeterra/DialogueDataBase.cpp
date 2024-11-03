#include "DialogueDataBase.h"
#include "Dialogue.h"
#include "Question.h"
#include "Answer.h"
#include "Comment.h"
#include "EndButton.h"

DialogueDataBase::DialogueDataBase() : m_interactionTextDB()
{
	// TODO maybe at alignement of the anwser in the Answer constructor
	// TODO Answer will have a Type to specify, like Quest, CanSayItAgain..

	sf::Vector2f questionPos = sf::Vector2f(100.f, 600.f);
	sf::Vector2f answerPos = sf::Vector2f(100.f, 700.f);
	sf::Vector2f answerOffset = sf::Vector2f(0.f, 100.f);
	sf::Vector2f commentPos = sf::Vector2f(750.f, 750.f);
	sf::Vector2f endButtonPos = sf::Vector2f(950.f, 900.f);

	m_interactionTextDB.insert({ "intro Q1", new Question("Are you a good person ?", questionPos)});
	m_interactionTextDB.insert({ "intro A1", new Answer("Yes I am !", answerPos)});
	m_interactionTextDB.insert({ "intro A2", new Answer("I don't really know..", answerPos + answerOffset)});
	m_interactionTextDB.insert({ "intro A3", new Answer("No.", answerPos + answerOffset * 2.f)});
	m_interactionTextDB.insert({ "intro C1", new Comment("Nice i knew it !", commentPos)});
	m_interactionTextDB.insert({ "intro C2", new Comment("Hum, okay try to find out i guess", commentPos)});
	m_interactionTextDB.insert({ "intro C3", new Comment("Oh, sorry for you", commentPos)});
	m_interactionTextDB.insert({ "intro E1", new EndButton("Ok.", endButtonPos)});

	m_interactionTextDB.insert({ "npcHello Q1", new Question("How are you ?", questionPos)});
	m_interactionTextDB.insert({ "npcHello A1", new Answer("Fine !", answerPos)});
	m_interactionTextDB.insert({ "npcHello A2", new Answer("So so..", answerPos + answerOffset)});
	m_interactionTextDB.insert({ "npcHello A3", new Answer("I feel bad.", answerPos + answerOffset * 2.f)});
	m_interactionTextDB.insert({ "npcHello C1", new Comment("Cool !", commentPos)});
	m_interactionTextDB.insert({ "npcHello C2", new Comment("Okay it could be worse", commentPos)});
	m_interactionTextDB.insert({ "npcHello C3", new Comment("Oh, sorry for you", commentPos)});
	m_interactionTextDB.insert({ "npcHello E1", new EndButton("Quit.", endButtonPos)});
}

DialogueDataBase::~DialogueDataBase()
{
}

void DialogueDataBase::createText(std::map<std::string, InteractionText*>& _text, std::string _name)
{
	// Question
	if (m_interactionTextDB[_name + " Q1"])
		_text.insert({ "Q1", m_interactionTextDB[_name + " Q1"] });

	// Answers
	if (m_interactionTextDB[_name + " A1"])
		_text.insert({ "A1", m_interactionTextDB[_name + " A1"] });
	if (m_interactionTextDB[_name + " A2"])
		_text.insert({ "A2", m_interactionTextDB[_name + " A2"] });
	if (m_interactionTextDB[_name + " A3"])
		_text.insert({ "A3", m_interactionTextDB[_name + " A3"] });

	// Comments
	if (m_interactionTextDB[_name + " C1"])
		_text.insert({ "C1", m_interactionTextDB[_name + " C1"] });
	if (m_interactionTextDB[_name + " C2"])
		_text.insert({ "C2", m_interactionTextDB[_name + " C2"] });
	if (m_interactionTextDB[_name + " C3"])
		_text.insert({ "C3", m_interactionTextDB[_name + " C3"] });

	// End button
	if (m_interactionTextDB[_name + " E1"])
		_text.insert({ "E1", m_interactionTextDB[_name + " E1"] });
}
