#include "SkillsDataBase.h"
#include "FightingSkills.h"
#include "ExplorationSkills.h"
#include "ProfessionSkills.h"
#include "SocialSkills.h"
#include "ComponentName.h"

std::list<Skills*> SkillsDataBase::m_skillsDB;

SkillsDataBase::SkillsDataBase()
{
	m_skillsDB.push_back(new FightingSkills("fighting1"));
	m_skillsDB.push_back(new FightingSkills("fighting2"));
	m_skillsDB.push_back(new FightingSkills("fighting3"));
	
	m_skillsDB.push_back(new ExplorationSkills("exploration1"));
	m_skillsDB.push_back(new ExplorationSkills("exploration2"));
	m_skillsDB.push_back(new ExplorationSkills("exploration3"));

	m_skillsDB.push_back(new ProfessionSkills("profession1"));
	m_skillsDB.push_back(new ProfessionSkills("profession2"));
	m_skillsDB.push_back(new ProfessionSkills("profession3"));

	m_skillsDB.push_back(new SocialSkills("social1"));
	m_skillsDB.push_back(new SocialSkills("social2"));
	m_skillsDB.push_back(new SocialSkills("social3"));
}

SkillsDataBase::~SkillsDataBase()
{
	for (std::list<Skills*>::iterator it = m_skillsDB.begin(); it != m_skillsDB.end();)
	{
		delete (*it);
		it = m_skillsDB.erase(it);
	}
}

Skills* SkillsDataBase::GetSkills(const std::string& _name)
{
	for (std::list<Skills*>::iterator it = m_skillsDB.begin(); it != m_skillsDB.end(); it++)
	{
		if ((*it)->GetComponent<ComponentName>()->GetName() == _name)
		{
			return (*it);
		}
	}

	return nullptr;
}

Skills* SkillsDataBase::CreateSkills(Skills* _skills)
{
	if (FightingSkills* fighting = dynamic_cast<FightingSkills*>(_skills))
		return new FightingSkills(*fighting);
	else if (ExplorationSkills* exploration = dynamic_cast<ExplorationSkills*>(_skills))
		return new ExplorationSkills(*exploration);
	else if (ProfessionSkills* profession = dynamic_cast<ProfessionSkills*>(_skills))
		return new ProfessionSkills(*profession);
	else if (SocialSkills* social = dynamic_cast<SocialSkills*>(_skills))
		return new SocialSkills(*social);

	return nullptr;
}
