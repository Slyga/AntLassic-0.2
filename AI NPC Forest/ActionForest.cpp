#include "ActionForest.h"

ActionForest::ActionForest()
	: ProgenitorActionForest()
{
	progenitorActionForest = NULL;
}

ActionForest::ActionForest(ProgenitorActionForest* progenitorActionForest_)
    : ProgenitorActionForest(progenitorActionForest_->actionTrees, progenitorActionForest_->GetCloneBehaviorSelector())
{
    progenitorActionForest = progenitorActionForest_;
}

void ActionForest::SetScoreLastAction(double scoreLastAction)
{
	if (lastActiveTree == -1) return;
	else actionTrees[lastActiveTree]->SetScoreLastAction(scoreLastAction);
}

int ActionForest::Start()
{
	lastActiveTree = behaviorSelector->GetIndexNextTree();
	return actionTrees[lastActiveTree]->Start();
}

void ActionForest::InformationTransfer()
{
	for (size_t i = 0; i < actionTrees.size(); i++)
	{
		actionTrees[i]->InformationTransfer(progenitorActionForest->actionTrees[i]);
	}
}
