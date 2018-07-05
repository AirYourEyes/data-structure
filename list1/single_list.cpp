#include <iostream>
#include <cstdlib>
using namespace std;

#include <stdio.h>
#include "point.h"
#include "single_list.h"

struct NODE{
    PPOINT data;
    PNODE next;
};

struct LIST{
    unsigned int count;
    PNODE head, tail;
};

// ��������
PLIST LiCreate()
{
    PLIST list = new LIST;
    list->head = NULL; // ��Ԫ�ڵ�
    list->tail = NULL;
    list->count = 0;
    return list;
}

// ��������
void LiDestroy(PLIST list)
{
    if (list)
    {
        LiClear(list); // �ͷŷ�����ڵ�Ŀռ�
        delete list;
    }
}

// ������ĩβ��ӽڵ�
void LiAppend(PLIST list, PPOINT point)
{
    if (!list || !point)
    {
        cout << "LiAppend: Parameter illegal." << endl;
        exit(1);
    }

    // �����½ڵ�
    PNODE node = new NODE;
    node->data = point;
    node->next = NULL;

    if (!list->head) // �������Ϊ��
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->count ++;
}

// �������ָ��λ�ò���ڵ�
void LiInsert(PLIST list, PPOINT point, unsigned int pos)
{
    if (!list || !point)
    {
        cout << "LiInsert: Parameter illegal." << endl;
        exit(1);
    }

    // �����ڵ�
    PNODE node = new NODE;
    node->data = point;
    node->next = NULL;

    if (pos == 0) // �ڱ�ͷ����ڵ�
    {
        node->next = list->head;
        list->head = node;
        list->count ++;
    }
    else if (pos < list->count) // ����������
    {
        // Ѱ��Ҫ����ڵ��ǰһ��λ��
        PNODE u = list->head;
        for (unsigned int i = 0; i < pos - 1; i++)
        {
            u = u->next;
        }

        node->next = u->next;
        u->next = node;
        list->count ++;
    }
    else                // ������β����ڵ�
    {
        LiAppend(list, point);
    }
}

// ɾ������ָ��λ�õĽڵ�
void LiDelete(PLIST list, unsigned int pos)
{
    if (!list)
    {
        cout << "LiDelete: Parameter illegal." << endl;
        exit(1);
    }


    if (list->count == 0)
    {
        return;
    }

    if (pos == 0) // ɾ��ͷ�ڵ�
    {
        PNODE t = list->head;
        list->head = t->next;

        if (!t->next) // Ҫɾ���Ľڵ������һ���ڵ��ˣ�����tailָ��
        {
            list->tail = NULL;
        }

        PtDestory(t->data); // �ͷŽڵ�ռ�
        delete t;
    }
    else if (pos < list->count) // Ҫɾ���Ľڵ���������м�λ�ã�����β��
    {
        // �ҳ�Ҫɾ���Ľڵ��ǰһ���ڵ�
        PNODE u = list->head;
        for (unsigned int i = 0; i < pos; i++)
        {
            u = u->next;
        }

        PNODE t = u->next; // Ҫɾ���Ľڵ�

        if (!t->next) // Ҫɾ���������һ���ڵ㣬����tailָ��
        {
            list->tail = u;
        }

        u->next = t->next;
        PtDestory(t->data); // �ͷ��ڴ�ռ�
        delete t;
    }

    list->count --;

}

// �������
void LiClear(PLIST list)
{
    if (list)
    {
        while (list->head)
        {
            PNODE node = list->head;
            list->head = node->next;
            PtDestory(node->data);
            delete node;
        }

        list->count = 0;
        list->tail = NULL;
    }
    else
    {
        cout << "LiClear: Parameter illegal." << endl;
        exit(1);
    }
}

// ��������
void LiTraverse(PLIST list)
{
    if(!list)
    {
        cout << "LiTraverse: Parameter illegal." << endl;
        exit(1);
    }

    PNODE t = list->head;
    while (!t)
    {
        cout << PtTransformIntoString(t->data) << endl;
        t = t->next;
    }

    cout << "NULL";
}

// �������в���ָ���ڵ�
bool LiSearch(PLIST list, PPOINT point)
{
    if (!list || !point)
    {
        cout << "LiSearch: Parameter illegal." << endl;
        exit(1);
    }

    PNODE t = list->head;
    while (t)
    {
        if (PtCompare(t->data, point))
        {
            return true;
        }

        t = t->next;
    }

    return false;
}

// ��ȡ����ڵ������
int LiGetCount(PLIST list)
{
    if (!list)
    {
        cout << "LiGetCount: Parameter illegal." << endl;
        exit(1);
    }

    return list->count;
}

// �ж������Ƿ�Ϊ��
bool LiIsEmpty(PLIST list)
{
    if (!list)
    {
        cout << "LiIsEmpty: Parameter illegal." << endl;
        exit(1);
    }

    return list->count == 0;
}

