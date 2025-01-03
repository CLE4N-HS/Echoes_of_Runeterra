#pragma once
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/Shader.hpp"

class DayNightSystem
{
public:
	DayNightSystem();
	~DayNightSystem();

	void Update();
	void Display();

	inline int& GetHour() { return m_Hour; }
	inline int& GetMinute() { return m_Minute; }
	inline int& GetCoefficient() { return m_Coefficient; }

	inline float GetTime() const { return m_Time; }
	inline float GetNormalizedTime() const { return m_NormalizedTime; }

private:
	int m_Hour = 0;
	int m_Minute = 0;

	float m_Second = 0.f;
	int m_Coefficient = 60;

	float m_Time = 0.f;
	float m_NormalizedTime = 0.f;

};
