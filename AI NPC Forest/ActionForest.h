#pragma once

#include "ProgenitorActionForest.h"

class ActionForest :
    public ProgenitorActionForest
{
private:
    /// <summary>
    /// Дерево родитель
    /// </summary>
    ProgenitorActionForest* progenitorActionForest;

public:

    /// <summary>
    /// Конструктор
    /// </summary>
    ActionForest();

    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="progenitorActionForest_">Дерево родитель</param>
    /// <param name="actionTrees_">Список деревьев</param>
    /// <param name="choiseActionTrees">Функция переключателя между деревьями</param>
    ActionForest(ProgenitorActionForest *progenitorActionForest_);

    /// <summary>
    /// Ввод счёта последнего выполненного действия
    /// </summary>
    /// <param name="scoreLastAction">Счёт последнего выполненного действия</param>
    void SetScoreLastAction(double scoreLastAction);

    /// <summary>
    /// Запуск следующего действия
    /// </summary>
    /// <returns>Индекс выбранного действися</returns>
    int Start();

    /// <summary>
    /// Передача инофрмации лесу родителю
    /// </summary>
    void InformationTransfer();
};

