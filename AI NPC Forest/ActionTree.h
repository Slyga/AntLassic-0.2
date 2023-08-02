#pragma once

#include <iostream>
#include <string>
#include "Node.h"

class ActionTree :
    public Node
{
private:
    /// <summary>
    /// ����� ���������� ����������� �������� � ������
    /// </summary>
    unsigned int amountOfAction;
    /// <summary>
    /// ��������� ���� ������������� �����
    /// </summary>
    double generalScore;
    /// <summary>
    /// ������� ������
    /// </summary>
    int treeDepth;

public:

    ActionTree();

    /// <summary>
    /// �����������
    /// </summary>
    /// <param name="followingActions_">������ �������� ��� ����������� �����</param>
    /// <param name="typeBehavior_">��� ��������� ����</param>
    /// <param name="nodeDepth_">������� ����</param>
    ActionTree(std::vector<int> followingActions_, TypeBehavior typeBehavior_);

    /// <summary>
    /// ����������� �����������
    /// </summary>
    /// <param name="actionTree">���������� ������</param>
    ActionTree(ActionTree& actionTree);

    /// <summary>
    /// ������� ������������ ������� ����
    /// </summary>
    /// <returns>������������ ������� ����</returns>
    int GetMaxDepth() override;

    /// <summary>
    /// ���������� ����� ���������� ����������� �������� � ���� � � ���������� �����
    /// </summary>
    /// <returns>����� ���������� ����������� �������� � ���� � � ���������� �����</returns>
    unsigned int GetAmountOfAction() override;

    /// <summary>
    /// ���������� ����� ���� ���� � �������� �������������� �����
    /// </summary>
    /// <returns>����� ���� ���� � ���������� �����</returns>
    double GetGeneralScore() override;

    /// <summary>
    /// �������� ���������� ���������� ������������� � ���� � ��������� �������������� �����
    /// </summary>
    void WinningGameUpgrade() override;

    /// <summary>
    /// �������� ���������� �������� � ���-��������
    /// </summary>
    /// <param name="actionTree">������ ����-��������</param>
    void InformationTransfer(ActionTree &actionTree);

    /// <summary>
    /// ���� ����� ���������� ������������ ��������
    /// </summary>
    /// <param name="scoreLastAction">���� ���������� ������������ ��������</param>
    void SetScoreLastAction(double scoreLastAction);

    /// <summary>
    /// ����� ���������� ��������
    /// </summary>
    /// </return>������ ���������� �������� <return>
    int Start();

    void Print(int numOutputLength);
};

