#pragma once

#include <vector>
#include "ActionBranch.h"
#include "TypeBehavior.h"

using namespace std;

class Node
{
protected:
	
	vector<ActionBranch> sheets;
	vector<int> followingActins;
	int nodeDepth;
	int indexNextNode;

	/// <summary>
	/// ����� ���������� ��������
	/// </summary>
	/// <param name="amountOfAction">����� ���������� ����������� �������� � ������</param>
	/// <param name="treeDepth">������� ������</param>
	/// <returns>������ ���������� ��������</returns>
	int ChoiseSheet(unsigned int amountOfAction, int& treeDepth);

	/// <summary>
	/// ������� ������� �������� ��� ����������� �����
	/// </summary>
	/// <returns>������ �������� ��� ����������� �����</returns>
	vector<int> GetFollowingActions();

	/// <summary>
	/// �������� ���� �� ��� �� ��������� ����
	/// </summary>
	/// <returns>true - ����, false - ���</returns>
	bool IsAnyActions();

	/// <summary>
	/// �������� ���� �� ��������� ����
	/// </summary>
	/// <returns>true - ����, false - ���</returns>
	bool IsAnySheets();

	/// <summary>
	/// �������� ��������� �������� �� ����������, ��� ����������� ����
	/// </summary>
	/// <param name="treeDepth">������� ������</param>
	/// <returns>������ ������������ ����</returns>
	int SetSheets(int &treeDepth);

public:
	/// <summary>
	/// ��� ��������� ������� ����. ������� �� ���� ��������� Action
	/// </summary>
	TypeBehavior typeThisNode;

	/// <summary>
	/// �������� ���� �� ��� �� ��������� ����
	/// </summary>
	/// <returns>true - ����, false - ���</returns>
	void ClearIndexNextNode();

	virtual unsigned int GetAmountOfAction() = 0;
	virtual double GetGeneralScore() = 0;
	virtual void WinningGameUpgrade() = 0;
	virtual int GetMaxDepth() = 0;
};

