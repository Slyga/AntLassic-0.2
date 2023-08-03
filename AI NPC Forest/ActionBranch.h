#pragma once

#include <iostream>
#include <string>
#include "Node.h"
#include "TypeBehavior.h"

class ActionBranch :
    public Node
{
private:
    /// <summary>
    /// ������ ������������� ����
    /// noActive � �� ��������������
    /// isUsed � ������ ������������
    /// alreadyUsed � ��� ��������������
    /// </summary>
	enum StatusUsed { noActive, isUsed, alreadyUsed}
	statusUsed;

    /// <summary>
    /// ���������� ���������� ������������� ����
    /// </summary>
    unsigned int winningGame;
    /// <summary>
    /// ��������� ������������� ����
    /// </summary>
    unsigned int numberOfGames;
    /// <summary>
    /// ����������� ��������� ���� 
    /// </summary>
    double generationModifier;
    /// <summary>
    /// ��������� ������ ����
    /// </summary>
    double startingActionBranchEvaluation;
    /// <summary>
    /// ������ ����
    /// </summary>
    double actionBranchEvaluation;
    /// <summary>
    /// ��������� ���� ��������������� ��������
    /// </summary>
    double lastScoreAction;

    /// <summary>
    /// ������� ����������������� ����������
    /// </summary>
    /// <param name="amountOfAction">����� ���������� ����������� �������� � ������</param>
    /// <param name="numberOfGames">��������� ������������� ����</param>
    /// <returns>���������������� ���������</returns>
    double GetBalancingTerm(unsigned int amountOfAction, unsigned int numberOfGames);

public:

    /// <summary>
    /// �������� ����
    /// </summary>
    int ActivAction;
    /// <summary>
    /// ����� �� ����������� ���������� ���������� �������������
    /// </summary>
    bool isWinningGameUpgrade;

    ActionBranch();
    /// <summary>
    /// �����������
    /// </summary>
    /// <param name="ActivAction_">�������� ����</param>
    /// <param name="followingActions_">������ �������� ��� ����������� �����</param>
    /// <param name="typeBehavior_">��� ��������� ����</param>
    /// <param name="nodeDepth_">������� ����</param>
    ActionBranch(int ActivAction_, std::vector<int> followingActions_, TypeBehavior typeBehavior_, int nodeDepth_);

    /// <summary>
    /// ����������� �����������
    /// </summary>
    /// <param name="actionBranch">���������� ������</param>
    ActionBranch(ActionBranch &actionBranch);

    /// <summary>
    /// ������� ������������ ������� ����
    /// </summary>
    /// <returns>������������ ������� ����</returns>
    virtual int GetMaxDepth() override;

    /// <summary>
    /// ���������� ����� ���������� ����������� �������� � ���� � � ���������� �����
    /// </summary>
    /// <returns>����� ���������� ����������� �������� � ���� � � ���������� �����</returns>
    virtual unsigned int GetAmountOfAction() override;

    /// <summary>
    /// ������� ������ ����
    /// </summary>
    /// <param name="amountOfAction">����� ���������� ����������� �������� � ������</param>
    /// <returns>������ ����</returns>
    double GetActionBranchEvaluation(unsigned int amountOfAction);

    /// <summary>
    /// ���������� ����� ���� ���� � �������� �������������� �����
    /// </summary>
    /// <returns>����� ���� ���� � ���������� �����</returns>
    virtual double GetGeneralScore() override;

    /// <summary>
    /// �������� ���������� ���������� ������������� � ���� � ��������� �������������� �����
    /// </summary>
    virtual void WinningGameUpgrade() override;

    /// <summary>
    /// ������� ��������� ������������ ���������
    /// </summary>
    /// <param name="GeneralScore">����� ������� ������</param>
    /// <return>��������� ������������ ���������</return>
    double GetGenerationModifierChanging(double generalScore);

    /// <summary>
    /// �������� ���������� ����� � ������-��������
    /// </summary>
    /// <param name="actionBranch">���� ������-��������</param>
    /// <param name="generalScore">����� ������� ������</param>
    /// <param name="increaseNumberUses">����������� ���������� �������������</param>
    void InformationTransfer(ActionBranch *actionBranch, double generalScore, bool increaseNumberUses);

    /// <summary>
    /// ���� ����� ���������� ������������ ��������
    /// </summary>
    /// <param name="scoreLastAction">���� ���������� ������������ ��������</param>
    /// <param name="amountOfAction">����� ���������� ����������� �������� � ������</param>
    void SetScoreLastAction(double scoreLastAction, unsigned int &amountOfAction);

    /// <summary>
    /// ����� ���������� ��������
    /// </summary>
    /// <param name="amountOfAction">����� ���������� ����������� �������� � ������</param>
    /// <param name="treeDepth">������� ������</param>
    /// <return>������ ���������� ��������</return>
    int Start(unsigned int& amountOfAction, unsigned int& treeDepth);

    

    void Print(int depth, int treeDepth, std::string outputType, int outputLength);
};

