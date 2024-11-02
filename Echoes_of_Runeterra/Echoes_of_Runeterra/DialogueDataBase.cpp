#include "DialogueDataBase.h"
#include "Question.h"
#include "Answer.h"
#include "Comment.h"

DialogueDataBase::DialogueDataBase() : m_interactionTextDB()
{
	// TODO maybe at alignement of the anwser in the Answer constructor
	// TODO Answer will have a Type to specify, like Quest, CanSayItAgain..
	m_interactionTextDB.insert({ "intro Q1", new Question("Are you a good person ?")});
	m_interactionTextDB.insert({ "intro A1", new Answer("Yes I am !")});
	m_interactionTextDB.insert({ "intro A2", new Answer("I don't really know..")});
	m_interactionTextDB.insert({ "intro A3", new Answer("No.")});
	m_interactionTextDB.insert({ "intro C1", new Comment("Nice i knew it !")});
	m_interactionTextDB.insert({ "intro C2", new Comment("Hum, okay try to find out i guess")});
	m_interactionTextDB.insert({ "intro C3", new Comment("Oh, sorry for you")});
}

DialogueDataBase::~DialogueDataBase()
{
}
