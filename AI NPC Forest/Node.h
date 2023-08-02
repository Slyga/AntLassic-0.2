#pragma once

#include <vector>
#include "TypeBehavior.h"

class Node
{
protected:
	/// <summary>
	/// Список последующих узлов
	/// </summary>
	std::vector<Node*> sheets;
	/// <summary>
	/// Список действий для последующих узлов
	/// </summary>
	std::vector<int> followingActins;
	/// <summary>
	/// Глубина узла
	/// </summary>
	int nodeDepth;
	/// <summary>
	/// Следующий узел, использовавшийся прошлый раз
	/// </summary>
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
	std::vector<int> GetFollowingActions();

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

	Node();

	/// <summary>
	/// Проверка есть ли ещё не созданные узлы
	/// </summary>
	/// <returns>true - есть, false - нет</returns>
	void ClearIndexNextNode();

	/// <summary>
	/// Возвращает общее количество выполненных действий у узла и у последющих узлов
	/// </summary>
	/// <returns>Общее количество выполненных действий у узла и у последющих узлов</returns>
	virtual unsigned int GetAmountOfAction() = 0;
	
	/// <summary>
	/// Возвращает общий счёт узла и следющих использованных узлов
	/// </summary>
	/// <returns>Общее счёт узла и последющих узлов</returns>
	virtual double GetGeneralScore() = 0;
	
	/// <summary>
	/// Повысить количество выйгрышных использований у узла и следующих использованных узлов
	/// </summary>
	virtual void WinningGameUpgrade() = 0;
	
	/// <summary>
	/// Возврат изменения модификатора поколения
	/// </summary>
	/// <param name="GeneralScore">Общий рейтинг дерева</param>
	/// <return>Изменение модификатора поколения</return>
	virtual int GetMaxDepth() = 0;
};

