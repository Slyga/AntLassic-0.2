#include <iostream>
#include <vector>
#include <stdlib.h>
#include "ProgenitorActionForest.h"
#include "ActionForest.h"
#include "BehaviorSelector.h"
#include "TypeBehavior.h"

class MyBehaviorSelector : public BehaviorSelector
{
public:
    MyBehaviorSelector() {}
    MyBehaviorSelector(MyBehaviorSelector* myBehaviorSelector) {}
    /// <summary>
    /// Вернуть индекс следующее активного дерева
    /// </summary>
    /// <returns>Индекс следующее активного дерева</returns>
    virtual int GetIndexNextTree() 
    {
        srand((unsigned int)time(NULL));
        return rand() % 2;
    }

    /// <summary>
    /// Вернуть клон переключателя поведения
    /// </summary>
    /// <returns>Клон переключателя поведения</returns>
    virtual BehaviorSelector* GetCloneBehaviorSelector()
    {
        return (new MyBehaviorSelector(this));
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");

    MyBehaviorSelector* myBehaviorSelector = new MyBehaviorSelector();

    std::vector<ActionTree*> v = std::vector<ActionTree*>{ new ActionTree(std::vector<int>{1, 2},
        TypeBehavior::Attack), new ActionTree(std::vector<int>{3, 4},
        TypeBehavior::Protection) };

    ProgenitorActionForest* progenitorActionForest = 
        new ProgenitorActionForest(v, myBehaviorSelector);
    for (size_t i = 0; i < 10; i++)
    {
        ActionForest actionForest(progenitorActionForest);
        for (size_t j = 0; j < 4; j++)
        {
            actionForest.Start();
            srand((unsigned int)time(NULL));
            actionForest.SetScoreLastAction(rand() % 51 / 100.0);
        }
        std::cout << "actionForest" << std::endl;
        actionForest.Print(0);
        actionForest.InformationTransfer();
    }
    std::cout << "progenitorActionForest" << std::endl;
    progenitorActionForest->Print(4);
    progenitorActionForest->Delete();
}
