#pragma once

#include <vector>
#include "TypeBehavior.h"

class Node
{
protected:
	/// <summary>
	/// ������ ����������� �����
	/// </summary>
	std::vector<Node*> sheets;
	/// <summary>
	/// ������ �������� ��� ����������� �����
	/// </summary>
	std::vector<int> followingActions;
	/// <summary>
	/// ������� ����
	/// </summary>
	int nodeDepth;
	/// <summary>
	/// ��������� ����, ���������������� ������� ���
	/// </summary>
	int indexNextNode;

	/// <summary>
	/// ����� ���������� ��������
	/// </summary>
	/// <param name="amountOfAction">����� ���������� ����������� �������� � ������</param>
	/// <param name="treeDepth">������� ������</param>
	/// <returns>������ ���������� ��������</returns>
	int ChoiseSheet(unsigned int amountOfAction, unsigned int& treeDepth);

	/// <summary>
	/// ������� ������� �������� ��� ����������� �����
	/// </summary>
	/// <returns>������ �������� ��� ����������� �����</returns>
	std::vector<int> GetFollowingActions();

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
	int SetSheets(unsigned int &treeDepth);

public:
	/// <summary>
	/// ��� ��������� ������� ����. ������� �� ���� ��������� Action
	/// </summary>
	TypeBehavior typeBehavior;

	/// <summary>
	/// �����������
	/// </summary>
	Node();

	/// <summary>
	/// �������� ���� �� ��� �� ��������� ����
	/// </summary>
	/// <returns>true - ����, false - ���</returns>
	void ClearIndexNextNode();

	/// <summary>
	/// ���� ����������� �����
	/// </summary>
	void Delete();

	/// <summary>
	/// ���������� ����� ���������� ����������� �������� � ���� � � ���������� �����
	/// </summary>
	/// <returns>����� ���������� ����������� �������� � ���� � � ���������� �����</returns>
	virtual unsigned int GetAmountOfAction() = 0;
	
	/// <summary>
	/// ���������� ����� ���� ���� � �������� �������������� �����
	/// </summary>
	/// <returns>����� ���� ���� � ����������� �����</returns>
	virtual double GetGeneralScore() = 0;
	
	/// <summary>
	/// �������� ���������� ���������� ������������� � ���� � ��������� �������������� �����
	/// </summary>
	virtual void WinningGameUpgrade() = 0;
	
	/// <summary>
	/// ������� ��������� ������������ ���������
	/// </summary>
	/// <param name="GeneralScore">����� ������� ������</param>
	/// <return>��������� ������������ ���������</return>
	virtual int GetMaxDepth() = 0;
};