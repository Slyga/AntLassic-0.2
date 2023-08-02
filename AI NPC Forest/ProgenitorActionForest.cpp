#include "ProgenitorActionForest.h"

ProgenitorActionForest::ProgenitorActionForest()
{
}

ProgenitorActionForest::ProgenitorActionForest(std::vector<ActionTree> actionTrees_, BehaviorSelector behaviorSelector_)
{
}

ProgenitorActionForest::ProgenitorActionForest(ProgenitorActionForest& progenitorActionForest)
{
}

TypeBehavior ProgenitorActionForest::GetTypeBehaviorLastActiveTree()
{
	return TypeBehavior();
}

BehaviorSelector* ProgenitorActionForest::GetCloneBehaviorSelector()
{
	return nullptr;
}

void ProgenitorActionForest::Print(int numOutputLength)
{
}
