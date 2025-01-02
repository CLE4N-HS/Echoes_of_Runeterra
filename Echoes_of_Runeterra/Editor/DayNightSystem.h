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

private:
	int m_Hour = 0;
	int m_Minute = 0;

	float m_Second = 0.f;
	int m_Coefficient = 60;

	sf::Shader* m_Shader;
	sf::RenderStates m_RenderStates;

};
