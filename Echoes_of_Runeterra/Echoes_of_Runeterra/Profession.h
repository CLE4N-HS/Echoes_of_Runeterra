#pragma once
#include "Window.h"

class Profession
{
public:
	Profession();
	~Profession() = default;

	virtual void update(Window& _window) = 0;
	virtual void display(Window& _window) = 0;

	void addXp(int _xp);

protected:
	inline int getLevel() {return m_level; }

private:
	int m_level;
	int m_xp;
	int m_levelXp;

};
