#pragma once
#include "Skills.h"

class SocialSkills : public Skills
{
public:
	SocialSkills(const std::string& _name);
	~SocialSkills();

	virtual void Update() override;

private:
	//int m_socialBonus;

};
