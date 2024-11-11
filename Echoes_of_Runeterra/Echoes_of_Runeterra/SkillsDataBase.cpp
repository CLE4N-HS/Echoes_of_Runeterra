#include "SkillsDataBase.h"
#include "FightingSkills.h"
#include "ExplorationSkills.h"
#include "ProfessionSkills.h"
#include "SocialSkills.h"

std::map<std::string, Skills*> SkillsDataBase::m_skillsDB;

SkillsDataBase skillDB;

SkillsDataBase::SkillsDataBase()
{
	m_skillsDB.insert({ "fighting1", new FightingSkills() });
	m_skillsDB.insert({ "fighting2", new FightingSkills() });
	m_skillsDB.insert({ "fighting3", new FightingSkills() });
	
	m_skillsDB.insert({ "exploration1", new ExplorationSkills() });
	m_skillsDB.insert({ "exploration2", new ExplorationSkills() });
	m_skillsDB.insert({ "exploration3", new ExplorationSkills() });
	
	m_skillsDB.insert({ "profession1", new ProfessionSkills() });
	m_skillsDB.insert({ "profession2", new ProfessionSkills() });
	m_skillsDB.insert({ "profession3", new ProfessionSkills() });
	
	m_skillsDB.insert({ "social1", new SocialSkills(1) });
	m_skillsDB.insert({ "social2", new SocialSkills(2) });
	m_skillsDB.insert({ "social3", new SocialSkills(3) });
}

SkillsDataBase::~SkillsDataBase()
{
}
