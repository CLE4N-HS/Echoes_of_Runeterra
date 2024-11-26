#include "MapFighter.h"

MapFighter::MapFighter(Fighter* _fighter) : m_fighter(_fighter)
{
}

MapFighter::~MapFighter()
{
	delete m_fighter;
}

void MapFighter::Update()
{
}

void MapFighter::Display()
{
}
