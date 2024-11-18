#include "TreeDataBase.h"
#include "SkillsDataBase.h"
#include "FightingSkills.h"
#include "ExplorationSkills.h"
#include "ProfessionSkills.h"
#include "SocialSkills.h"
#include "ComponentName.h"

//std::map<std::string, SkillsTree*> TreeDataBase::m_treeDB;
std::list<SkillsTree*> TreeDataBase::m_treeDB;

//TreeDataBase treeDB;

TreeDataBase::TreeDataBase()
{
	SkillsLeaf* tree1_branch1_leaf1(new SkillsLeaf(SkillsDataBase::GetSkills("fighting1")));
	SkillsLeaf* tree1_branch1_leaf2(new SkillsLeaf(SkillsDataBase::GetSkills("fighting2")));
	SkillsLeaf* tree1_branch1_leaf3(new SkillsLeaf(SkillsDataBase::GetSkills("fighting3")));

	SkillsLeaf* tree1_branch2_leaf1(new SkillsLeaf(SkillsDataBase::GetSkills("exploration1")));
	SkillsLeaf* tree1_branch2_leaf2(new SkillsLeaf(SkillsDataBase::GetSkills("exploration2")));
	SkillsLeaf* tree1_branch2_leaf3(new SkillsLeaf(SkillsDataBase::GetSkills("social1")));

	SkillsLeaf* tree1_branch3_leaf1(new SkillsLeaf(SkillsDataBase::GetSkills("profession1")));
	SkillsLeaf* tree1_branch3_leaf2(new SkillsLeaf(SkillsDataBase::GetSkills("social2")));
	SkillsLeaf* tree1_branch3_leaf3(new SkillsLeaf(SkillsDataBase::GetSkills("profession2")));

	SkillsBranch* tree1_branch1(new SkillsBranch(std::vector<SkillsLeaf*>{tree1_branch1_leaf1, tree1_branch1_leaf2, tree1_branch1_leaf3}));
	SkillsBranch* tree1_branch2(new SkillsBranch(std::vector<SkillsLeaf*>{tree1_branch2_leaf1, tree1_branch2_leaf2, tree1_branch2_leaf3}));
	SkillsBranch* tree1_branch3(new SkillsBranch(std::vector<SkillsLeaf*>{tree1_branch3_leaf1, tree1_branch3_leaf2, tree1_branch3_leaf3}));

	SkillsTree* tree1(new SkillsTree("tree1", std::vector<SkillsBranch*>{tree1_branch1, tree1_branch2, tree1_branch3}));
	//m_treeDB.push_back(tree1);

	// same thing
	this->AddTree("tree2", std::vector<std::vector<std::string>>({
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" }
		}));

	
	this->AddTree("tree1", std::vector<std::vector<std::string>>({
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" }
		}));
	
	this->AddTree("tree3", std::vector<std::vector<std::string>>({
		{ "fighting1"},
		{ "fighting1", "fighting2"},
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3", "fighting1" },
		{ "fighting1", "fighting2", "fighting3", "fighting1", "fighting1" }
		}));
	
	this->AddTree("tree4", std::vector<std::vector<std::string>>({
		{ "fighting1", "fighting2", "fighting3", "fighting3" },
		{ "fighting1", "fighting2", "fighting3", "fighting3" },
		{ "fighting1", "fighting2", "fighting3", "fighting3" },
		{ "fighting1", "fighting2", "fighting3", "fighting3" }
		}));
	
	this->AddTree("tree5", std::vector<std::vector<std::string>>({
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3", "fighting3"  },
		{ "fighting1", "fighting2", "fighting3", "fighting3"  },
		{ "fighting1", "fighting2", "fighting3", "fighting3" },
		{ "fighting1", "fighting2"}
		}));
	
	this->AddTree("tree6", std::vector<std::vector<std::string>>({
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" },
		{ "fighting1", "fighting2", "fighting3" }
		}));
}

TreeDataBase::~TreeDataBase()
{
	for (std::list<SkillsTree*>::iterator it = m_treeDB.begin(); it != m_treeDB.end();)
	{
		delete (*it);
		it = m_treeDB.erase(it);
	}
}

SkillsTree* TreeDataBase::CreateNewTree(const std::string& _name)
{
	for (std::list<SkillsTree*>::iterator it = m_treeDB.begin(); it != m_treeDB.end(); it++)
	{
		if ((*it)->GetComponent<ComponentName>()->GetName() == _name)
		{
			return new SkillsTree((*it));
		}
	}
	return nullptr;
}

void TreeDataBase::AddTree(const std::string& _name, const std::vector<std::vector<std::string>>& _tree)
{
	std::vector<SkillsBranch*> skillBranch;
	for (size_t branch = 0; branch < _tree.size(); branch++)
	{
		std::vector<SkillsLeaf*> skillLeaf;
		for (size_t leaf = 0; leaf < _tree[branch].size(); leaf++)
		{
			skillLeaf.push_back(new SkillsLeaf(SkillsDataBase::GetSkills(_tree[branch][leaf])));
		}
		skillBranch.push_back(new SkillsBranch(skillLeaf));
	}

	m_treeDB.push_back(new SkillsTree(_name, skillBranch));
}
