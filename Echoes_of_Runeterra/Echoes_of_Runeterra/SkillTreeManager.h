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

	static inline bool IsInSkillTree() { return m_IsInSkillTree; }
	static inline void SetInInSkillTree(bool _isIt) { m_IsInSkillTree = _isIt; }

private:
	static std::vector<SkillsTree*> m_tree;
	static int m_currentTreeIndex;
	static bool m_IsInSkillTree;
	
};
