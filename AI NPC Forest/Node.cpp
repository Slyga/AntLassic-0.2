#include <math.h>
#include <limits>
#include <stdlib.h>
#include "Node.h"
#include "ActionBranch.h"

int Node::ChoiseSheet(unsigned int amountOfAction, unsigned int& treeDepth)
{
    double EvaluationNewActionBranch = 0;
    if (amountOfAction != 0)
    {
        EvaluationNewActionBranch = sqrt(2 * log(amountOfAction));
    }
    double maxEvaluation = -std::numeric_limits<double>::max();
    int item = -1;
    for (size_t i = 0; i < sheets.size(); i++)
    {
        if (sheets[i] != NULL)
        {
            ActionBranch* sheet = (ActionBranch*)sheets[i];
            if (sheet->GetActionBranchEvaluation(amountOfAction) > maxEvaluation)
            {
                maxEvaluation = sheet->GetActionBranchEvaluation(amountOfAction);
                item = i;
            }
        }
    }
    if (maxEvaluation <= EvaluationNewActionBranch && IsAnyActions())
    {
        item = SetSheets(treeDepth);
        ActionBranch* temp = (ActionBranch*)sheets[item];
        temp->GetActionBranchEvaluation(amountOfAction);
    }
    return item;
}

std::vector<int> Node::GetFollowingActions()
{
    std::vector<int> followingActions_ = std::vector<int>(Node::followingActions);
    for (size_t i = 0; i < sheets.size(); i++)
    {
        if (sheets[i] != NULL)
        {
            ActionBranch* temp = (ActionBranch*)sheets[i];
            followingActions_[i] = temp->ActivAction;
        }
    }
    return followingActions_;
}

bool Node::IsAnyActions()
{
    for (size_t i = 0; i < followingActions.size(); i++)
    {
        if (followingActions[i] != -1)
        {
            return true;
        }
    }
    return false;
}

bool Node::IsAnySheets()
{
    for (size_t i = 0; i < sheets.size(); i++)
    {
        if (sheets[i] != NULL)
        {
            return true;
        }
    }
    return false;
}

int Node::SetSheets(unsigned int& treeDepth)
{
    srand((unsigned int)time(NULL));
    int indexAction;
    do
    {
        indexAction = rand() % (followingActions.size());
    } while (followingActions[indexAction] == -1);

    sheets[indexAction] = new ActionBranch(followingActions[indexAction], GetFollowingActions(), typeBehavior, nodeDepth + 1);
    followingActions[indexAction] = -1;
    if (treeDepth == nodeDepth)
    {
        treeDepth++;
    }
    return indexAction;
}

Node::Node()
{
    nodeDepth = -1;
    indexNextNode = -1;
}

void Node::ClearIndexNextNode()
{
    if (indexNextNode != -1)
    {
        ActionBranch* temp = (ActionBranch*)sheets[indexNextNode];
        temp->ClearIndexNextNode();
        indexNextNode = -1;
    }
}

void Node::Delete()
{
    for (size_t i = 0; i < sheets.size(); i++)
    {
        ActionBranch* sheet = (ActionBranch*)sheets[i];
        if (sheet != NULL)
        {
            sheet->Delete();
            delete sheet;
            sheets[i] = NULL;
        }
    }
}
