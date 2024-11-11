#include "SkillsLeaf.h"

SkillsLeaf::SkillsLeaf(Skills* _skill) : m_skill(_skill)
{
}

SkillsLeaf::~SkillsLeaf()
{
	delete m_skill;
}
