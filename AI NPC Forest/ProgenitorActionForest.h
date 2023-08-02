#pragma once

#include <vector>
#include "BehaviorSelector.h"
#include "ActionTree.h"

class ProgenitorActionForest
{
private:
	/// <summary>
	/// ������������� ����� ���������
	/// </summary>
	BehaviorSelector* behaviorSelector;
public:
	/// <summary>
	/// ������ �������� � ����
	/// </summary>
	std::vector<ActionTree> actionTrees;
	/// <summary>
	/// ������ ����������� ��������� ������
	/// </summary>
	int lastActivTree;

	/// <summary>
	/// �����������
	/// </summary>
	ProgenitorActionForest();

	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="actionTrees_">������ ��������</param>
	/// <param name="behaviorSelector_">������������� ����� ���������</param>
	ProgenitorActionForest(std::vector<ActionTree> actionTrees_, BehaviorSelector* behaviorSelector_);

	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="progenitorActionForest">������� �����������</param>
	ProgenitorActionForest(ProgenitorActionForest& progenitorActionForest);

	/// <summary>
	/// ������� ���� ������������� ���������
	/// </summary>
	/// <returns>���� ������������� ���������</returns>
	TypeBehavior GetTypeBehaviorLastActiveTree();

	/// <summary>
	/// ������� ���� ������������� ���������
	/// </summary>
	/// <returns>���� ������������� ���������</returns>
	BehaviorSelector* GetCloneBehaviorSelector();

	void Print(int numOutputLength);
};

