#pragma once

#include <vector>
#include "BehaviorSelector.h"
#include "ActionTree.h"

class ProgenitorActionForest
{
protected:
	/// <summary>
	/// Переключатель между деревьями
	/// </summary>
	BehaviorSelector* behaviorSelector;
public:
	/// <summary>
	/// Вектор деревьев в лесу
	/// </summary>
	std::vector<ActionTree*> actionTrees;
	/// <summary>
	/// Индекс предыдущего активного дерева
	/// </summary>
	int lastActiveTree;

	/// <summary>
	/// Конструктор
	/// </summary>
	ProgenitorActionForest();

	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="actionTrees_">Список деревьев</param>
	/// <param name="behaviorSelector_">Переключатель между деревьями</param>
	ProgenitorActionForest(std::vector<ActionTree*> actionTrees_, BehaviorSelector* behaviorSelector_);

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="progenitorActionForest">Элемент копирования</param>
	ProgenitorActionForest(ProgenitorActionForest& progenitorActionForest);

	/// <summary>
	/// Вернуть клон переключателя поведения
	/// </summary>
	/// <returns>Клон переключателя поведения</returns>
	TypeBehavior GetTypeBehaviorLastActiveTree();

	/// <summary>
	/// Вернуть клон переключателя поведения
	/// </summary>
	/// <returns>Клон переключателя поведения</returns>
	BehaviorSelector* GetCloneBehaviorSelector();

	void Print(int numOutputLength);
};

