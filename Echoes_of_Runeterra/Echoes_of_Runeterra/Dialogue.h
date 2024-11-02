#pragma once
#include "Window.h"
#include "Question.h"
#include "Answer.h"
#include "Comment.h"

class Dialogue
{
public:
	Dialogue();
	~Dialogue();

	void createQuestion(std::string _name);

	void update(Window& _window);
	void display(Window& _window);

private:
	Question m_question;
	std::vector<Answer> m_answer;
	Comment m_comment;

};
