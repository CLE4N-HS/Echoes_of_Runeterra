#pragma once
#include "tools.h"

class Consumable
{
public:
	Consumable();
	~Consumable();

private:
	std::string m_name;
	int m_hp;
	int m_defense;
	int m_speed;

};

void cons_read(std::string _filePath);
