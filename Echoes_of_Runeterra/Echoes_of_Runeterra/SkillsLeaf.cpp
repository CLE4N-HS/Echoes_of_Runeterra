#include "SkillsLeaf.h"

SkillsLeaf::SkillsLeaf(Skills* _skill) : m_skill(_skill)
{
}

SkillsLeaf::~SkillsLeaf()
{
	delete m_skill;
}

void SkillsLeaf::update(Window& _window)
{
	if (m_isUnlocked)
	{
		m_skill->update(_window);
	}
}
