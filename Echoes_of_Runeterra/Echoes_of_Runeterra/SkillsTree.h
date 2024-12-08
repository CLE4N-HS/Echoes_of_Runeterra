#pragma once
#include "Tools.h"
#include "Entity.h"
#include "SkillsBranch.h"

class SkillsTree : public Entity
{
public:
	SkillsTree();
	SkillsTree(SkillsTree* _skillTree);
	SkillsTree(const std::string& _name, const std::vector<SkillsBranch*>& _branches);
	~SkillsTree();

	void Update();
	void Display();

private:
	void CorrectPositions();
	std::vector<SkillsBranch*> m_tree;
	bool m_isComplete = false;

	int m_xp;
	int m_levelXp;


};
