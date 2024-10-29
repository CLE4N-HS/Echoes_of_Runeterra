#include "Master.h"

Master::Master() : m_window("Echoes of Runeterra", sf::Style::Default), m_state()
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

		m_state.update(m_window);
		m_state.display(m_window);

		m_window.display();
	}
}
