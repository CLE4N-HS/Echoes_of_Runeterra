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
	//static void AddTree(const std::string& _name, std::vector<std::vector<std::string>> _tree);
	static void AddTree(const std::string& _name, const std::vector<std::vector<std::string>>& _tree);

	static std::list<SkillsTree*> m_treeDB;
	//std::map<std::string, SkillsTree*> m_treeDB;

};
