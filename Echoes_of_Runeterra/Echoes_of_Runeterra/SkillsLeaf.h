#pragma once
#include "Window.h"
#include "Skills.h"

class SkillsLeaf
{
public:
	SkillsLeaf(Skills* _skill);
	~SkillsLeaf();

	inline bool isUnlocked() { return m_isUnlocked; }
	inline void unlock(bool _unlock = true) { m_isUnlocked = _unlock; }

	void Update();

private:
	Skills* m_skill;
	bool m_isUnlocked;

};
