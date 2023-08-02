#include "ActionBranch.h"

double ActionBranch::GetBalancingTerm(unsigned int amountOfAction, unsigned int numberOfGames)
{
    return 0.0;
}

ActionBranch::ActionBranch()
{
}

ActionBranch::ActionBranch(int ActivAction_, std::vector<int> followingActions_, TypeBehavior typeBehavior_, int nodeDepth_)
{
}

ActionBranch::ActionBranch(ActionBranch& actionBranch)
{
}

int ActionBranch::GetMaxDepth()
{
    return 0;
}

unsigned int ActionBranch::GetAmountOfAction() 
{
    return 0;
}

double ActionBranch::GetActionBranchEvaluation(unsigned int amountOfAction)
{
    return 0.0;
}

double ActionBranch::GetGeneralScore()
{
    return 0.0;
}

void ActionBranch::WinningGameUpgrade()
{
}

double ActionBranch::GetGenerationModifierChanging(double generalScore)
{
    return 0.0;
}

void ActionBranch::InformationTransfer(ActionBranch actionBranch, double generalScore, bool increaseNumberUses)
{
}

void ActionBranch::SetScoreLastAction(double scoreLastAction, unsigned int& amountOfAction)
{
}

int ActionBranch::Start(unsigned int& amountOfAction, unsigned int& treeDepth)
{
    return 0;
}

void ActionBranch::Print(int depth, int treeDepth, std::string outputType, int outputLength)
{
}
