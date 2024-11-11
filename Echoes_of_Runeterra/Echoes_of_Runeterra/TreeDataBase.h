#pragma once
#include "Window.h"
#include "SkillsTree.h"

class TreeDataBase
{
public:
	TreeDataBase();
	~TreeDataBase();

private:
	static std::map<std::string, SkillsTree*> m_treeDB;

};
