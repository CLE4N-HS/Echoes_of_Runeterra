#include "SkillsLeaf.h"

SkillsLeaf::SkillsLeaf(Skills* _skill) : m_skill(_skill), m_state(SkillsLeaf::State::LOCKED)
{
}

SkillsLeaf::~SkillsLeaf()
{
	delete m_skill;
}

void SkillsLeaf::Update()
{
	//m_skill->Update();
}
