#include "SkillsSystem.h"
#include "TreeDataBase.h"

SkillsSystem::SkillsSystem()
{
	m_skillTree = TreeDataBase::getTree("tree1");
}

SkillsSystem::~SkillsSystem()
{
}

void SkillsSystem::update(Window& _window)
{
	m_skillTree->update(_window);
}
