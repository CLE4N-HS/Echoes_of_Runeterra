#pragma once
#include "SkillsTree.h"

class SkillTreeManager
{
public:
	SkillTreeManager();
	~SkillTreeManager();

	static void Update();
	static void Display();

	//static inline void SetTree(SkillsTree* _tree) { m_tree = _tree; }

private:
	static std::vector<SkillsTree*> m_tree;
	static int m_currentTreeIndex;
	
};
