#include "TreeDataBase.h"
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
	//////////////////////////////////////////////////////////////
	/// 
	/// A tree is made up of branches, which are made up of leaves
	///
	//////////////////////////////////////////////////////////////

	SkillsLeaf* tree1_branch1_leaf1(new SkillsLeaf(new FightingSkills()));
	SkillsLeaf* tree1_branch1_leaf2(new SkillsLeaf(new FightingSkills()));
	SkillsLeaf* tree1_branch1_leaf3(new SkillsLeaf(new FightingSkills()));
	SkillsLeaf* tree1_branch2_leaf1(new SkillsLeaf(new ExplorationSkills()));
	SkillsLeaf* tree1_branch2_leaf2(new SkillsLeaf(new ProfessionSkills()));
	SkillsLeaf* tree1_branch2_leaf3(new SkillsLeaf(new FightingSkills()));
	SkillsLeaf* tree1_branch3_leaf1(new SkillsLeaf(new SocialSkills(1)));
	SkillsLeaf* tree1_branch3_leaf2(new SkillsLeaf(new ExplorationSkills()));
	SkillsLeaf* tree1_branch3_leaf3(new SkillsLeaf(new SocialSkills(2)));

	SkillsBranch* tree1_branch1(new SkillsBranch(std::vector<SkillsLeaf*>{tree1_branch1_leaf1, tree1_branch1_leaf2, tree1_branch1_leaf3}));
	SkillsBranch* tree1_branch2(new SkillsBranch(std::vector<SkillsLeaf*>{tree1_branch2_leaf1, tree1_branch2_leaf2, tree1_branch2_leaf3}));
	SkillsBranch* tree1_branch3(new SkillsBranch(std::vector<SkillsLeaf*>{tree1_branch3_leaf2, tree1_branch3_leaf2, tree1_branch3_leaf3}));

	SkillsTree* tree1(new SkillsTree("tree1", std::vector<SkillsBranch*>{tree1_branch1, tree1_branch2, tree1_branch3}));
	m_treeDB.push_back(tree1);
}

TreeDataBase::~TreeDataBase()
{
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
