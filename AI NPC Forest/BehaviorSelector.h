#pragma once

class BehaviorSelector
{
public:
    /// <summary>
    /// Вернуть индекс следующее активного дерева
    /// </summary>
    /// <returns>Индекс следующее активного дерева</returns>
    virtual int GetIndexNextTree() = 0;

    /// <summary>
    /// Вернуть клон переключателя поведения
    /// </summary>
    /// <returns>Клон переключателя поведения</returns>
    virtual BehaviorSelector* GetCloneBehaviorSelector() = 0;
};

