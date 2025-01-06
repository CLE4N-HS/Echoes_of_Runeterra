#pragma once
#include "Fighter.h"

class Enemy : public Fighter
{
public:
	Enemy();
	~Enemy();

	virtual void Update() = 0;
	virtual void Display() = 0;

	std::string m_TextureName;
private:

};
