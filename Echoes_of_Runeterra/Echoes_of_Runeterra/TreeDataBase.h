#pragma once
#include "Window.h"
#include "SkillsTree.h"

class TreeDataBase
{
public:
	TreeDataBase();
	~TreeDataBase();

	SkillsTree*& getTree(std::string _name);

private:
	std::map<std::string, SkillsTree*> m_treeDB;

};
