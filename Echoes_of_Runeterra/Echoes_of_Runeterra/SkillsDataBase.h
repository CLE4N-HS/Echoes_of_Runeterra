#pragma once
#include "Window.h"
#include "Skills.h"

class SkillsDataBase
{
public:
	SkillsDataBase();
	~SkillsDataBase();

	static inline Skills* getSkill(std::string _name) { return m_skillsDB[_name]; }

private:

	static std::map<std::string, Skills*> m_skillsDB;

};
