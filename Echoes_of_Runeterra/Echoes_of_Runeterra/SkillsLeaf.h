#pragma once
#include "Tools.h"
#include "Entity.h"
#include "Skills.h"

class SkillsLeaf : public Entity
{
public:
	enum State {
		LOCKED,
		OBTAINABLE,
		ACQUIRED
	};

	SkillsLeaf(Skills* _skill);
	~SkillsLeaf();

	inline SkillsLeaf::State GetState() const { return m_state; }
	inline void SetState(const SkillsLeaf::State& _state) { m_state = _state; }

	void Update();
	void Display();

	inline Skills* GetSkill() { return m_skill; }

private:
	Skills* m_skill;
	SkillsLeaf::State m_state;

};
