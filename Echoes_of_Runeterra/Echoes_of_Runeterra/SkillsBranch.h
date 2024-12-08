#pragma once
#include "Tools.h"
#include "Entity.h"
#include "SkillsLeaf.h"

class SkillsBranch : public Entity
{
public:
	SkillsBranch(const std::vector<SkillsLeaf*>& _leaves);
	~SkillsBranch();

	void Update();
	void Display();

	void CorrectPositions(const sf::Vector2f& _pos);

	inline bool IsComplete() const { return m_isComplete; }

private:
	std::vector<SkillsLeaf*> m_branch;
	bool m_isComplete = false;

};
