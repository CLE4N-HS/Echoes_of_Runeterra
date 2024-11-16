#pragma once
#include "Skills.h"

class SocialSkills : public Skills
{
public:
	SocialSkills(int _socialBonus);
	~SocialSkills();

	virtual void update(Window& _window) override;

private:
	int m_socialBonus;

};
