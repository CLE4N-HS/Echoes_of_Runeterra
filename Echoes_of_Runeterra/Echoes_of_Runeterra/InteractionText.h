#pragma once
#include "Window.h"

class InteractionText
{
public:
	InteractionText();
	~InteractionText();

	// TODO maybe delete all texts when the interaction is finished

protected:
	// TODO sureley getSize
	std::vector<std::string> m_text;

};
