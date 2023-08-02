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
	/// Выбор следующего действия
	/// </summary>
	/// <param name="amountOfAction">Общее количество выполненных действий в дереве</param>
	/// <param name="treeDepth">Глубина дерева</param>
	/// <returns>Индекс выбранного действия</returns>
	int ChoiseSheet(unsigned int amountOfAction, int& treeDepth);

	/// <summary>
	/// Возврат списока действий для последующих узлов
	/// </summary>
	/// <returns>Список действий для последующих узлов</returns>
	vector<int> GetFollowingActions();

	/// <summary>
	/// Проверка есть ли ещё не созданные узлы
	/// </summary>
	/// <returns>true - есть, false - нет</returns>
	bool IsAnyActions();

	/// <summary>
	/// Проверка есть ли созданные узлы
	/// </summary>
	/// <returns>true - есть, false - нет</returns>
	bool IsAnySheets();

	/// <summary>
	/// Добавить случайное действие из оставшихся, как последующий узел
	/// </summary>
	/// <param name="treeDepth">Глубина дерева</param>
	/// <returns>Индекс добавленного узла</returns>
	int SetSheets(int &treeDepth);

public:
	/// <summary>
	/// Тип поведения данного узла. Зависит от типа поведения Action
	/// </summary>
	TypeBehavior typeThisNode;

	/// <summary>
	/// Проверка есть ли ещё не созданные узлы
	/// </summary>
	/// <returns>true - есть, false - нет</returns>
	void ClearIndexNextNode();

	virtual unsigned int GetAmountOfAction() = 0;
	virtual double GetGeneralScore() = 0;
	virtual void WinningGameUpgrade() = 0;
	virtual int GetMaxDepth() = 0;
};

