#pragma once
#include "Skills.h"

class SocialSkills : public Skills
{
public:
	SocialSkills(int _socialBonus);
	~SocialSkills();

	virtual void Update() override;

private:
	int m_socialBonus;

};
