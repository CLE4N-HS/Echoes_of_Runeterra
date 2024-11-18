#pragma once
#include "Tools.h"
#include "Skills.h"

class SkillsDataBase
{
public:
	SkillsDataBase();
	~SkillsDataBase();

	/// <summary>
	/// Gets a pointer to the Skills if founded
	/// Use this only for a Database in order to not change the Skills values
	/// </summary>
	static Skills* GetSkills(const std::string& _name);

	/// <summary>
	/// Creates a new Skills without relation with the database
	/// </summary>
	static Skills* CreateSkills(Skills* _skills);

	//static inline Skills* getSkill(std::string _name) { return m_skillsDB[_name]; }

private:
	static std::list<Skills*> m_skillsDB;
	//static std::map<std::string, Skills*> m_skillsDB;

};
