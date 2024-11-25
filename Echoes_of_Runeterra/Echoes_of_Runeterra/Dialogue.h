#pragma once
#include "Entity.h"
#include "InteractionText.h"

class Dialogue : public Entity
{
public:
	typedef enum {
		QUESTION_ANSWER,
		COMMENT,
		END
	}State;

	Dialogue();
	~Dialogue();

	void setup(std::map<std::string, InteractionText*>& _text);
	bool isInDialogue();

	void Update();
	void Display();

private:
	std::map<std::string, InteractionText*> m_text;
	Dialogue::State m_state;

};
