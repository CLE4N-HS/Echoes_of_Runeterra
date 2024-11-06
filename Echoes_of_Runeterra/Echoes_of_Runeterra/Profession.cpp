#include "Profession.h"

Profession::Profession() : m_level(1), m_xp(0), m_levelXp(100)
{
}

void Profession::addXp(int _xp)
{
	m_xp += _xp;
	int i(0);
	while (m_xp >= m_levelXp && i++ < 100)
	{
		m_level++;
		m_xp -= m_levelXp;

		m_levelXp += (m_levelXp / 5 + 50) / 10 * 10;
	}
}
