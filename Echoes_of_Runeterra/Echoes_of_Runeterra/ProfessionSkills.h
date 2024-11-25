#pragma once
#include "Skills.h"

class ProfessionSkills : public Skills
{
public:
	ProfessionSkills(const std::string& _name);
	~ProfessionSkills();

	virtual void Update() override;

private:

};
