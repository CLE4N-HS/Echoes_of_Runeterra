#pragma once

class DayNightSystem
{
public:
	DayNightSystem();
	~DayNightSystem();

	void Update();

	inline int& GetHour() { return m_Hour; }
	inline int& GetMinute() { return m_Minute; }
	inline float& GetCoefficient() { return m_Coefficient; }

private:
	int m_Hour = 0;
	int m_Minute = 0;

	float m_Second = 0.f;
	float m_Coefficient = 1.f;

};
