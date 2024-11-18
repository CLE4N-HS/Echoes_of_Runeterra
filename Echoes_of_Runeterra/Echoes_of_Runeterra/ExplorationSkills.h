#pragma once
#include "Skills.h"

class ExplorationSkills : public Skills
{
public:
	ExplorationSkills(const std::string& _name);
	~ExplorationSkills();

	virtual void Update() override;

private:

};
