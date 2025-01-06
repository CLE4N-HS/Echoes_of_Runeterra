#pragma once
#include "State.h"
#include "Map.h"
#include "DayNightSystem.h"
#include "EnemyDatabase.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();

	virtual void Update();

	virtual void Display();

private:
	Map m_Map;
	DayNightSystem m_DayNightSystem;

	void DisplayLayer(size_t _layer);
	void DisplayLayerTransparency(size_t _layer);

	std::vector<Enemy*> m_Enemy;
	bool NightOnePass = false;

	void UpdateEnemy();

	//DialogueManager m_dialogueManager;
	//InteractionManager m_interactionManager;

};
