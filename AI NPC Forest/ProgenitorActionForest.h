#pragma once

#include <vector>
#include "BehaviorSelector.h"
#include "ActionTree.h"

class ProgenitorActionForest
{
protected:
	/// <summary>
	/// ������������� ����� ���������
	/// </summary>
	BehaviorSelector* behaviorSelector;
public:
	/// <summary>
	/// ������ �������� � ����
	/// </summary>
	std::vector<ActionTree*> actionTrees;
	/// <summary>
	/// ������ ����������� ��������� ������
	/// </summary>
	int lastActiveTree;

	/// <summary>
	/// �����������
	/// </summary>
	ProgenitorActionForest();

	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="actionTrees_">������ ��������</param>
	/// <param name="behaviorSelector_">������������� ����� ���������</param>
	ProgenitorActionForest(std::vector<ActionTree*> actionTrees_, BehaviorSelector* behaviorSelector_);

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

	/// <summary>
	/// ���� �������� � ����
	/// </summary>
	void Delete();

	/// <summary>
	/// ����� � �������. ��� ������������.
	/// </summary>
	/// <param name="numOutputLength">1 - numberGame, 2 - price, 3 - startPrice, 4 - modifier</param>
	void Print(int numOutputLength);
};

