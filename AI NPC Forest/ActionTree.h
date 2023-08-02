#pragma once

#include <iostream>
#include <string>
#include "Node.h"

class ActionTree :
    public Node
{
private:
    /// <summary>
    /// Общее количество выполненных действий в дереве
    /// </summary>
    unsigned int amountOfAction;
    /// <summary>
    /// Суммарный счёт использованых узлов
    /// </summary>
    double generalScore;
    /// <summary>
    /// Глубина дерева
    /// </summary>
    int treeDepth;

public:

    ActionTree();

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="followingActions_">Список действий для последующих узлов</param>
    /// <param name="typeBehavior_">Тип поведения узла</param>
    /// <param name="nodeDepth_">Глубина узла</param>
    ActionTree(std::vector<int> followingActions_, TypeBehavior typeBehavior_);

    /// <summary>
    /// Конструктор копирования
    /// </summary>
    /// <param name="actionTree">Копируемый объект</param>
    ActionTree(ActionTree& actionTree);

    /// <summary>
    /// Вернуть максимальную глубину узла
    /// </summary>
    /// <returns>Максимальную глубина узла</returns>
    int GetMaxDepth() override;

    /// <summary>
    /// Возвращает общее количество выполненных действий у узла и у последющих узлов
    /// </summary>
    /// <returns>Общее количество выполненных действий у узла и у последющих узлов</returns>
    unsigned int GetAmountOfAction() override;

    /// <summary>
    /// Возвращает общий счёт узла и следющих использованных узлов
    /// </summary>
    /// <returns>Общее счёт узла и последющих узлов</returns>
    double GetGeneralScore() override;

    /// <summary>
    /// Повысить количество выйгрышных использований у узла и следующих использованных узлов
    /// </summary>
    void WinningGameUpgrade() override;

    /// <summary>
    /// Передача инофрмации деревьям в лес-родитель
    /// </summary>
    /// <param name="actionTree">дерево леса-родителя</param>
    void InformationTransfer(ActionTree &actionTree);

    /// <summary>
    /// Ввод счёта последнего выполненного действия
    /// </summary>
    /// <param name="scoreLastAction">Счёт последнего выполненного действия</param>
    void SetScoreLastAction(double scoreLastAction);

    /// <summary>
    /// Выбор следующего действия
    /// </summary>
    /// </return>Индекс следующего действия <return>
    int Start();

    void Print(int numOutputLength);
};

