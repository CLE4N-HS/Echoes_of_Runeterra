#include "TreeDataBase.h"
#include "FightingSkills.h"
#include "ExplorationSkills.h"
#include "ProfessionSkills.h"
#include "SocialSkills.h"

//std::map<std::string, SkillsTree*> TreeDataBase::m_treeDB;

//TreeDataBase treeDB;

TreeDataBase::TreeDataBase()
{
	//////////////////////////////////////////////////////////////
	/// 
	/// A tree is made up of branches, which are made up of leaves
	///
	//////////////////////////////////////////////////////////////
	
	SkillsLeaf* tr(new SkillsLeaf(new FightingSkills()));

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

	SkillsTree* tree1(new SkillsTree(std::vector<SkillsBranch*>{tree1_branch1, tree1_branch2, tree1_branch3}));
	m_treeDB.insert({ "tree1", tree1 });

	//
	//SkillsLeaf tree2_branch1_leaf1(new FightingSkills());
	//SkillsLeaf tree2_branch1_leaf2(new FightingSkills());
	//SkillsLeaf tree2_branch1_leaf3(new FightingSkills());
	//SkillsBranch tree2_branch1(std::vector<SkillsLeaf*>{&tree1_branch1_leaf1, &tree1_branch1_leaf2, &tree1_branch1_leaf3});

	//SkillsLeaf tree2_branch2_leaf1(new ExplorationSkills());
	//SkillsLeaf tree2_branch2_leaf2(new ProfessionSkills());
	//SkillsLeaf tree2_branch2_leaf3(new FightingSkills());
	//SkillsBranch tree2_branch2(std::vector<SkillsLeaf*>{&tree1_branch2_leaf1, &tree1_branch2_leaf2, &tree1_branch2_leaf3});

	//SkillsLeaf tree2_branch3_leaf1(new SocialSkills(3));
	//SkillsLeaf tree2_branch3_leaf2(new ExplorationSkills());
	//SkillsLeaf tree2_branch3_leaf3(new SocialSkills(4));
	//SkillsBranch tree2_branch3(std::vector<SkillsLeaf*>{&tree1_branch3_leaf2, &tree1_branch3_leaf2, &tree1_branch3_leaf3});

	//SkillsTree tree2(std::vector<SkillsBranch*>{&tree1_branch1, & tree1_branch2, & tree1_branch3});
	//m_treeDB.insert({ "tree2", &tree2 });

}

TreeDataBase::~TreeDataBase()
{
}

SkillsTree*& TreeDataBase::getTree(std::string _name)
{
	SkillsTree* a = m_treeDB[_name];

	return m_treeDB[_name];
	// TODO: insérer une instruction return ici
}
