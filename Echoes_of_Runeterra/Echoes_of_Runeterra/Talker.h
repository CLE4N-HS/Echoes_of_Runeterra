#pragma once
#include "Npc.h"

class Talker : public Npc
{
public:
	Talker();
	Talker(const std::string& _name, const std::string& _dialogueKey = "");
	~Talker();

	virtual void Update() override;
	virtual void Display() override;

	inline std::string GetDialogueKey() const { return m_dialogueKey; }
	inline void SetDialogueKey(std::string _dialogueKey) { m_dialogueKey = _dialogueKey; }

private:
	std::string m_dialogueKey;

};
