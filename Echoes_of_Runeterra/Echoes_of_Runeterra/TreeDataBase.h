#pragma once
#include "Window.h"
#include "SkillsTree.h"

class TreeDataBase
{
public:
	TreeDataBase();
	~TreeDataBase();

	static SkillsTree* CreateNewTree(const std::string& _name);

private:
	static std::list<SkillsTree*> m_treeDB;
	//std::map<std::string, SkillsTree*> m_treeDB;

};
