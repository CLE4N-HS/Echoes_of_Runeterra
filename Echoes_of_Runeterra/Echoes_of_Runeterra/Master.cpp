#include "Master.h"

Master::Master() : m_window("Echoes of Runeterra", sf::Style::Default), m_stateManager()
{
}

Master::~Master()
{
}

void Master::loop()
{
	while (!m_window.isDone())
	{
		m_window.update();

		if (m_window.hasFocus())
			m_stateManager.update(m_window);

		m_stateManager.display(m_window);

		m_window.display();
	}
}
