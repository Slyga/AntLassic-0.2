#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "ActionBranch.h"

double ActionBranch::GetBalancingTerm(unsigned int amountOfAction, unsigned int numberOfGames)
{
    if (amountOfAction == 0) amountOfAction = 1;
    if (numberOfGames == 0) numberOfGames = 1;
    return sqrt(2 * log(amountOfAction) / numberOfGames);
}

ActionBranch::ActionBranch() 
    : Node()
{
    ActivAction = -1;
    winningGame = 0;
    numberOfGames = 0;
    generationModifier = 0;
    startingActionBranchEvaluation = 0;
    actionBranchEvaluation = 0;
    isWinningGameUpgrade = false;
    statusUsed = StatusUsed::noActive;
    lastScoreAction = 0;
}

ActionBranch::ActionBranch(int ActivAction_, std::vector<int> followingActions_, TypeBehavior typeBehavior_, int nodeDepth_) 
    : ActionBranch()
{
    ActivAction = ActivAction_;
    followingActions = std::vector<int>(followingActions_);
    sheets = std::vector<Node*>(followingActions.size());
    for (size_t i = 0; i < followingActions.size(); i++)
    {
        sheets.push_back(NULL);
    }
    typeBehavior = typeBehavior_;
    nodeDepth = nodeDepth_;
}

ActionBranch::ActionBranch(ActionBranch& actionBranch)
    : ActionBranch(actionBranch.ActivAction, actionBranch.followingActions, actionBranch.typeBehavior, actionBranch.nodeDepth)
{
    srand((unsigned int)time(NULL));
    winningGame = actionBranch.winningGame;
    numberOfGames = actionBranch.numberOfGames; 
    generationModifier = actionBranch.generationModifier + actionBranch.generationModifier * ((rand() % (21) - 10) / 100.0);
    startingActionBranchEvaluation = actionBranch.startingActionBranchEvaluation;
    for (size_t i = 0; i < actionBranch.sheets.size(); i++)
    {
        ActionBranch* sheet = (ActionBranch*)actionBranch.sheets[i];
        if (sheet != NULL) sheets[i] = new ActionBranch(*sheet);
        else sheets[i] = NULL;
    }
}

int ActionBranch::GetMaxDepth()
{
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
        return max;
    }
    else return nodeDepth;
}

unsigned int ActionBranch::GetAmountOfAction() 
{
    unsigned int sumNumberOfGames = numberOfGames;
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

double ActionBranch::GetActionBranchEvaluation(unsigned int amountOfAction)
{
    unsigned int numberOfGames_ = numberOfGames;
    if (amountOfAction == 0) amountOfAction = 1;
    if (numberOfGames_ == 0) numberOfGames_ = 1;
    double n1 = winningGame / (double)numberOfGames_;
    double n2 = GetBalancingTerm(amountOfAction, numberOfGames);
    actionBranchEvaluation = n1 + n2 + generationModifier;
    if (startingActionBranchEvaluation == 0) startingActionBranchEvaluation = actionBranchEvaluation;
    return actionBranchEvaluation;
}

double ActionBranch::GetGeneralScore()
{
    double sumScore = lastScoreAction;
    if (indexNextNode != -1)
    {
        sumScore += sheets[indexNextNode]->GetGeneralScore();
    }
    return sumScore;
}

void ActionBranch::WinningGameUpgrade()
{
    srand((unsigned int)time(NULL)); 
    double probabilityWinning = ((rand() % 101) / 100.0);
    if (probabilityWinning <= lastScoreAction)
        isWinningGameUpgrade = true;
    if (indexNextNode != -1)
    {
        sheets[indexNextNode]->WinningGameUpgrade();
    }
}

double ActionBranch::GetGenerationModifierChanging(double generalScore)
{
    return abs(actionBranchEvaluation - startingActionBranchEvaluation) * lastScoreAction;
}

void ActionBranch::InformationTransfer(ActionBranch *actionBranch, double generalScore, bool increaseNumberUses = true)
{
    actionBranch->startingActionBranchEvaluation = actionBranchEvaluation;
    if (increaseNumberUses) actionBranch->numberOfGames++;
    if (isWinningGameUpgrade) actionBranch->winningGame++;
    actionBranch->generationModifier += GetGenerationModifierChanging(generalScore);
    if (indexNextNode == -1)
    {
        return;
    }
    else if (actionBranch->sheets[indexNextNode] != NULL)
    {
        ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
        sheet->InformationTransfer((ActionBranch*)actionBranch->sheets[indexNextNode], generalScore, increaseNumberUses);
    }
    else
    {
        actionBranch->sheets[indexNextNode] = new ActionBranch(*(ActionBranch*)sheets[indexNextNode]);
        ActionBranch* sheet = (ActionBranch*)actionBranch->sheets[indexNextNode];
        sheet->ClearIndexNextNode();
        actionBranch->followingActions[indexNextNode] = -1;
        sheet = (ActionBranch*)sheets[indexNextNode];
        sheet->InformationTransfer((ActionBranch*)actionBranch->sheets[indexNextNode], generalScore, false);
    }
}

void ActionBranch::SetScoreLastAction(double scoreLastAction, unsigned int& amountOfAction)
{
    if (indexNextNode == -1 && statusUsed == StatusUsed::isUsed)
    {
        lastScoreAction = scoreLastAction;
        statusUsed = StatusUsed::alreadyUsed;
        numberOfGames++;
        amountOfAction++;
    }
    else
    {
        ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
        sheet->SetScoreLastAction(scoreLastAction, amountOfAction);
    }
}

int ActionBranch::Start(unsigned int& amountOfAction, unsigned int& treeDepth)
{
    switch (statusUsed)
    {
    case StatusUsed::noActive:
        statusUsed = StatusUsed::isUsed;
        return ActivAction;

    case StatusUsed::alreadyUsed:
        if (indexNextNode == -1)
        {
            indexNextNode = ChoiseSheet(amountOfAction, treeDepth);
            ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
            return sheet->Start(amountOfAction, treeDepth);
        }
        else
        {
            ActionBranch* sheet = (ActionBranch*)sheets[indexNextNode];
            return sheet->Start(amountOfAction, treeDepth);
        }  
    }
    return -1;
}



void ActionBranch::Print(int depth, int treeDepth, std::string outputType, int outputLength)
{
    if (nodeDepth == depth)
    {
        for (int k = 1; k <= (pow(followingActions.size(), treeDepth - depth - 1) - 0.5) * outputLength; k++)
            std::cout << " ";

        std::cout << ActivAction << ":";

        if (outputType == "numberGame")
            std::cout << ActivAction << "/" << numberOfGames << " ";
        if (outputType == "price")
            std::cout << actionBranchEvaluation << " ";
        if (outputType == "startPrice")
            std::cout << startingActionBranchEvaluation << " ";
        if (outputType == "modifier")
            std::cout << generationModifier << " ";

        for (int k = 1; k <= (pow(followingActions.size(), treeDepth - depth - 1) - 0.5) * outputLength; k++)
            std::cout << " ";
    }
    else if (nodeDepth < depth)
    {
        for (size_t i = 0; i < sheets.size(); i++)
        {
            ActionBranch* sheet = (ActionBranch*)sheets[i];
            if (sheet != NULL)
            {
                sheet->Print(depth, treeDepth, outputType, outputLength);
            }
            else
            {
                if (outputLength > 0)
                    for (int j = 0; j < pow(followingActions.size(), depth - nodeDepth - 1); j++)
                    {
                        for (int k = 1; k <= (pow(followingActions.size(), treeDepth - depth - 1) - 0.5) * outputLength; k++)
                            std::cout << " ";
                        for (int i = 0; i < outputLength - 1; i++)
                            std::cout << "_";
                        std::cout << " ";
                        for (int k = 1; k <= (pow(followingActions.size(), treeDepth - depth - 1) - 0.5) * outputLength; k++)
                            std::cout << " ";
                    }
            }
        }
    }
}
