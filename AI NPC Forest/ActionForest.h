#pragma once

#include "ProgenitorActionForest.h"

class ActionForest :
    public ProgenitorActionForest
{
private:
    /// <summary>
    /// ������ ��������
    /// </summary>
    ProgenitorActionForest* progenitorActionForest;

public:

    /// <summary>
    /// �����������
    /// </summary>
    ActionForest();

    /// <summary>
    /// �����������
    /// </summary>
    /// <param name="progenitorActionForest_">������ ��������</param>
    /// <param name="actionTrees_">������ ��������</param>
    /// <param name="choiseActionTrees">������� ������������� ����� ���������</param>
    ActionForest(ProgenitorActionForest *progenitorActionForest_);

    /// <summary>
    /// ���� ����� ���������� ������������ ��������
    /// </summary>
    /// <param name="scoreLastAction">���� ���������� ������������ ��������</param>
    void SetScoreLastAction(double scoreLastAction);

    /// <summary>
    /// ������ ���������� ��������
    /// </summary>
    /// <returns>������ ���������� ���������</returns>
    int Start();

    /// <summary>
    /// �������� ���������� ���� ��������
    /// </summary>
    void InformationTransfer();
};

