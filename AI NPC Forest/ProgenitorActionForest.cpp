#include "ProgenitorActionForest.h"
#include <iostream>

ProgenitorActionForest::ProgenitorActionForest()
{
	behaviorSelector = NULL;
	lastActiveTree = -1;
}

ProgenitorActionForest::ProgenitorActionForest(std::vector<ActionTree*> actionTrees_, BehaviorSelector* behaviorSelector_)
	: ProgenitorActionForest()
{
	actionTrees = std::vector<ActionTree*>(actionTrees_.size());
	for (size_t i = 0; i < actionTrees_.size(); i++)
	{
		actionTrees.push_back(actionTrees_[i]);
	}
	behaviorSelector = behaviorSelector_->GetCloneBehaviorSelector();
}

ProgenitorActionForest::ProgenitorActionForest(ProgenitorActionForest& progenitorActionForest) 
	: ProgenitorActionForest(progenitorActionForest.actionTrees, progenitorActionForest.behaviorSelector) {}

TypeBehavior ProgenitorActionForest::GetTypeBehaviorLastActiveTree()
{
	return actionTrees[lastActiveTree]->typeBehavior;
}

BehaviorSelector* ProgenitorActionForest::GetCloneBehaviorSelector()
{
	return behaviorSelector->GetCloneBehaviorSelector();
}

void ProgenitorActionForest::Delete()
{
	for (size_t i = 0; i < actionTrees.size(); i++)
	{
		if (actionTrees[i] != NULL)
		{
			actionTrees[i]->Delete();
			delete actionTrees[i];
			actionTrees[i] = NULL;
		}
	}
}

void ProgenitorActionForest::Print(int numOutputLength)
{
	for (size_t i = 0; i < actionTrees.size(); i++)
	{
		ActionTree* tree = actionTrees[i];
		std::cout << "Дерево " << tree->typeBehavior << std::endl;
		tree->Print(numOutputLength);
		std::cout << std::endl;
	}
	std::cout << "##################################################################################" << std::endl;
}
