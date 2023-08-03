#pragma once

#include <iostream>
#include <string>
#include "Node.h"
#include "TypeBehavior.h"

class ActionBranch :
    public Node
{
private:
    /// <summary>
    /// Статус использования узла
    /// noActive — не использовалось
    /// isUsed — сейчас используется
    /// alreadyUsed — уже использовалось
    /// </summary>
	enum StatusUsed { noActive, isUsed, alreadyUsed}
	statusUsed;

    /// <summary>
    /// Количество выйгрышных использований узла
    /// </summary>
    unsigned int winningGame;
    /// <summary>
    /// Количесво использований узла
    /// </summary>
    unsigned int numberOfGames;
    /// <summary>
    /// Модификатор поколения узла 
    /// </summary>
    double generationModifier;
    /// <summary>
    /// Начальная оценка узла
    /// </summary>
    double startingActionBranchEvaluation;
    /// <summary>
    /// Оценка узла
    /// </summary>
    double actionBranchEvaluation;
    /// <summary>
    /// Последний счёт использованного действия
    /// </summary>
    double lastScoreAction;

    /// <summary>
    /// Возврат уравновешивающего слагаемого
    /// </summary>
    /// <param name="amountOfAction">Общее количество выполненных действий в дереве</param>
    /// <param name="numberOfGames">Количесво использований узла</param>
    /// <returns>Уравновешивающее слагаемое</returns>
    double GetBalancingTerm(unsigned int amountOfAction, unsigned int numberOfGames);

public:

    /// <summary>
    /// Действие узла
    /// </summary>
    int ActivAction;
    /// <summary>
    /// Нужно ли увеличивать количество выйгрышных использований
    /// </summary>
    bool isWinningGameUpgrade;

    ActionBranch();
    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="ActivAction_">Действие узла</param>
    /// <param name="followingActions_">Список действий для последующих узлов</param>
    /// <param name="typeBehavior_">Тип поведения узла</param>
    /// <param name="nodeDepth_">Глубина узла</param>
    ActionBranch(int ActivAction_, std::vector<int> followingActions_, TypeBehavior typeBehavior_, int nodeDepth_);

    /// <summary>
    /// Конструктор копирования
    /// </summary>
    /// <param name="actionBranch">Копируемый объект</param>
    ActionBranch(ActionBranch &actionBranch);

    /// <summary>
    /// Вернуть максимальную глубину узла
    /// </summary>
    /// <returns>Максимальную глубина узла</returns>
    virtual int GetMaxDepth() override;

    /// <summary>
    /// Возвращает общее количество выполненных действий у узла и у последющих узлов
    /// </summary>
    /// <returns>Общее количество выполненных действий у узла и у последющих узлов</returns>
    virtual unsigned int GetAmountOfAction() override;

    /// <summary>
    /// Возврат оценки узла
    /// </summary>
    /// <param name="amountOfAction">Общее количество выполненных действий в дереве</param>
    /// <returns>Оценка узла</returns>
    double GetActionBranchEvaluation(unsigned int amountOfAction);

    /// <summary>
    /// Возвращает общий счёт узла и следющих использованных узлов
    /// </summary>
    /// <returns>Общее счёт узла и последющих узлов</returns>
    virtual double GetGeneralScore() override;

    /// <summary>
    /// Повысить количество выйгрышных использований у узла и следующих использованных узлов
    /// </summary>
    virtual void WinningGameUpgrade() override;

    /// <summary>
    /// Возврат изменения модификатора поколения
    /// </summary>
    /// <param name="GeneralScore">Общий рейтинг дерева</param>
    /// <return>Изменение модификатора поколения</return>
    double GetGenerationModifierChanging(double generalScore);

    /// <summary>
    /// Передача инофрмации узлам в дерево-родитель
    /// </summary>
    /// <param name="actionBranch">Узел дерева-родителя</param>
    /// <param name="generalScore">Общий рейтинг дерева</param>
    /// <param name="increaseNumberUses">Увеличивать количество использований</param>
    void InformationTransfer(ActionBranch *actionBranch, double generalScore, bool increaseNumberUses);

    /// <summary>
    /// Ввод счёта последнего выполненного действия
    /// </summary>
    /// <param name="scoreLastAction">Счёт последнего выполненного действия</param>
    /// <param name="amountOfAction">Общее количество выполненных действий в дереве</param>
    void SetScoreLastAction(double scoreLastAction, unsigned int &amountOfAction);

    /// <summary>
    /// Выбор следующего действия
    /// </summary>
    /// <param name="amountOfAction">Общее количество выполненных действий в дереве</param>
    /// <param name="treeDepth">Глубина дерева</param>
    /// <return>Индекс выбранного действия</return>
    int Start(unsigned int& amountOfAction, unsigned int& treeDepth);

    

    void Print(int depth, int treeDepth, std::string outputType, int outputLength);
};

