#include "DayNightSystem.h"
#include "Tools.h"

DayNightSystem::DayNightSystem()
{
}

DayNightSystem::~DayNightSystem()
{
}

void DayNightSystem::Update()
{
	float dt = Tools::GetDeltaTime();

	m_Second += dt * m_Coefficient;
	
	if (m_Second >= 60.f)
	{
		m_Minute += 1;
		m_Second -= 60.f;
	}
	
	if (m_Minute >= 60)
	{
		m_Hour += 1;
		m_Minute -= 60;
	}
	
	if (m_Hour >= 24)
	{
		m_Hour = 0;
	}
}
