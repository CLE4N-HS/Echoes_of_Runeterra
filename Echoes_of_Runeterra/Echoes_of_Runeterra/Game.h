#pragma once
#include "State.h"
#include "ItemDatabase.h"
#include "CharacterManager.h"
#include "MapManager.h"
#include "DialogueManager.h"
#include "InteractionManager.h"
#include "CraftManager.h"
#include "SkillsSystem.h"
#include "TreeDataBase.h"

class Game : public State
{
public:
	Game();
	virtual ~Game();

	virtual void Update();

	virtual void Display();

private:
	ItemDataBase* m_itemDB;
	CharacterManager m_characterManager;
	MapManager m_mapManager;
	DialogueManager m_dialogueManager;
	InteractionManager m_interactionManager;
	CraftManager m_craftManager;

	TreeDataBase* m_treeDB;
	SkillsSystem m_skillsSystem;

};
