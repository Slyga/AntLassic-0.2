#include "ActionTree.h"
#include "ActionBranch.h"

ActionTree::ActionTree()
	: Node()
{
	amountOfAction = 0;
	generalScore = 0;
	treeDepth = 1;
	nodeDepth = 0;
}

ActionTree::ActionTree(std::vector<int> followingActions_, TypeBehavior typeBehavior_) 
	: ActionTree()
{
	followingActions = std::vector<int>(followingActions_);
	sheets = std::vector<Node*>(followingActions.size());
	for (size_t i = 0; i < followingActions.size(); i++)
	{
		sheets.push_back(NULL);
	}
	typeBehavior = typeBehavior_;
}

ActionTree::ActionTree(ActionTree& actionTree)
	: ActionTree(actionTree.followingActions, actionTree.typeBehavior)
{
	amountOfAction = actionTree.amountOfAction;
	treeDepth = actionTree.treeDepth;
	for (size_t i = 0; i < actionTree.sheets.size(); i++)
	{
		ActionBranch* sheet = (ActionBranch*)actionTree.sheets[i];
		if (sheet != NULL) sheets[i] = new ActionBranch(*(ActionBranch*)sheet);
		else sheets[i] = NULL;
	}
}

int ActionTree::GetMaxDepth()
{
	if (nodeDepth > 0) return nodeDepth;
	if (IsAnySheets())
	{
		int max = 0;
		for (size_t i = 0; i < sheets.size(); i++)
		{
			ActionBranch* sheet = (ActionBranch*)sheets[i];
			if (sheet != NULL)
			{
				int current = sheet->GetMaxDepth();
				if (max < current)
				{
					max = current;
				}
			}
		}
		nodeDepth = max;
		return nodeDepth;
	}
	else
	{
		nodeDepth = 0;
		return nodeDepth;
	}
}

unsigned int ActionTree::GetAmountOfAction()
{
	unsigned int sumNumberOfGames = 0;
	for (size_t i = 0; i < sheets.size(); i++)
	{
		ActionBranch* sheet = (ActionBranch*)sheets[i];
		if (sheet != NULL)
		{
			sumNumberOfGames += sheet->GetAmountOfAction();
		}
	}
	return sumNumberOfGames;
}

double ActionTree::GetGeneralScore()
{
	generalScore = 0;
	if (indexNextNode != -1)
	{
		generalScore += sheets[indexNextNode]->GetGeneralScore();
	}
	return generalScore;
}

void ActionTree::WinningGameUpgrade()
{
	if (indexNextNode != -1)
	{
		sheets[indexNextNode]->WinningGameUpgrade();
	}
}

void ActionTree::InformationTransfer(ActionTree* actionTree)
{
	WinningGameUpgrade();
	GetGeneralScore();
	if (treeDepth > actionTree->treeDepth)
	{
		actionTree->treeDepth = treeDepth;
	}
	if (indexNextNode == -1)
	{
		return;
	}
	else if (actionTree->sheets[indexNextNode] != NULL)
	{
		ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
		sheet->InformationTransfer((ActionBranch*)actionTree->sheets[indexNextNode], generalScore, true);
	}
	else
	{
		actionTree->sheets[indexNextNode] = new ActionBranch(*(ActionBranch*)sheets[indexNextNode]);
		actionTree->sheets[indexNextNode]->ClearIndexNextNode();
		actionTree->followingActions[indexNextNode] = -1;
		ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
		sheet->InformationTransfer((ActionBranch*)actionTree->sheets[indexNextNode], generalScore, false);
	}
	actionTree->amountOfAction = actionTree->GetAmountOfAction();
}

void ActionTree::SetScoreLastAction(double scoreLastAction)
{
	if (indexNextNode == -1) return;
	else
	{
		ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
		sheet->SetScoreLastAction(scoreLastAction, amountOfAction);
	}
}

int ActionTree::Start()
{
	if (indexNextNode == -1)
	{
		indexNextNode = ChoiseSheet(amountOfAction, treeDepth);
	}
	ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
	return sheet->Start(amountOfAction, treeDepth);
}

void ActionTree::Print(int numOutputLength)
{
}
