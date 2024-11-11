#pragma once
#include "Window.h"
#include "SkillsTree.h"

class TreeDataBase
{
public:
	TreeDataBase();
	~TreeDataBase();

	inline SkillsTree* getTree(std::string _name) { return m_treeDB[_name]; }

private:
	std::map<std::string, SkillsTree*> m_treeDB;

};
