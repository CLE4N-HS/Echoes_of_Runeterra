#pragma once
#include "Tools.h"

class Profession
{
public:
	Profession();
	~Profession() = default;

	virtual void Update() = 0;
	virtual void Display() = 0;

	void addXp(int _xp);

protected:
	inline int getLevel() {return m_level; }

private:
	int m_level;
	int m_xp;
	int m_levelXp;

};
