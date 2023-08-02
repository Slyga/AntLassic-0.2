#pragma once

class BehaviorSelector
{
public:
    /// <summary>
    /// ������� ������ ��������� ��������� ������
    /// </summary>
    /// <returns>������ ��������� ��������� ������</returns>
    virtual int GetIndexNextTree() = 0;

    /// <summary>
    /// ������� ���� ������������� ���������
    /// </summary>
    /// <returns>���� ������������� ���������</returns>
    virtual BehaviorSelector* GetCloneBehaviorSelector() = 0;
};

