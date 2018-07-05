#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include "single_list.h"

struct NODE{
    ADT data;
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
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// ��������
void LiDestroy(PLIST list, DESTORY_OBJECT destory)
{
    if (!list)
    {
        cout << "LiDestory: Parameter(s) illegals." << endl;
        exit(1);
    }

    LiClear(list, destory);
    delete list;
}

// ������ĩβ��ӽڵ�
void LiAppend(PLIST list, ADT obj)
{
    if (!list)
    {
        cout << "LiAppend: Parameter(s) illegal." << endl;
        exit(1);
    }

    // �����µĽڵ�
    PNODE newNode = new NODE;
    newNode->data = obj;
    newNode->next = NULL;

    if (list->count == 0) // ����Ϊ�յ�ʱ��
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode; // ����Ϊ�գ�ֱ�Ӳ�������β
        list->tail = newNode;
    }
    list->count ++;
}

// �������ָ��λ�ò���ڵ�
// objΪ�½ڵ��������
// pos��ֵ��0��ʼ
void LiInsert(PLIST list, ADT obj, unsigned int pos)
{
    if (!list)
    {
        cout << "LiInsert: Parameter(s) illegal." << endl;
        exit(1);
    }

    PNODE newNode = new NODE;
    newNode->data = obj;
    newNode->next = NULL;

    if (pos <= 0) // ���뵽��ͷ
    {
        newNode->next = list->head;
        list->head = newNode;

        if (!list->tail) // Ҫ����������ǿձ�ʱ
        {
            list->tail = newNode;
        }

        list->count ++;
    }
    else if (pos < list->count) // Ҫ�����λ���������м䣨������ͷβ��
    {
        PNODE preNode = list->head; // Ҫ����Ľڵ��ǰһ���ڵ�
        for (unsigned int i = 0; i < pos - 1; i++)
        {
            preNode = preNode->next;
        }

        newNode->next = preNode->next;
        preNode->next = newNode;
        list->count ++;
    }
    else
    {
        LiAppend(list, obj); // ��ӵ���β
    }
}

// ɾ������ָ��λ�õĽڵ�
void LiDelete(PLIST list, unsigned int pos, DESTORY_OBJECT destory)
{
    if (!list)
    {
        cout << "LiDelete: Parameter(s) illegal." << endl;
        exit(1);
    }

    if (list->count == 0) // ������
    {
        return;
    }

    if (pos == 0) // ɾ��ͷ���
    {
        PNODE delNode = list->head;
        list->head = delNode->next;

        if (!delNode->next) // Ҫɾ���Ľڵ������һ���ڵ㣬��tailָ���ÿ�
        {
            list->tail = NULL;
        }

        if (destory)
        {
            (*destory)(delNode->data);
        }

        delete delNode;
    }
    else if (pos < list->count) // ɾ����ͷ�ڵ�
    {
        PNODE preDelNode = list->head; // Ѱ��Ҫɾ���Ľڵ��ǰһ���ڵ�
        for (unsigned int i = 0; i < pos - 1; i++)
        {
            preDelNode = preDelNode->next;
        }

        PNODE delNode = preDelNode->next; // Ҫɾ���Ľڵ�
        preDelNode->next = delNode->next;

        if (!delNode->next) // Ҫɾ���Ľڵ���β�ڵ㣬����tailָ��
        {
            list->tail = preDelNode;
        }

        if (destory)
        {
            (*destory)(delNode->data);
        }

        delete delNode;
    }

    list->count --;
}

// �������
void LiClear(PLIST list, DESTORY_OBJECT destory)
{
    if (!list)
    {
        cout << "LiClear: Parameter(s) illegal." << endl;
        exit(1);
    }

    while (list->head)
    {
        PNODE t = list->head;
        list->head = t->next;

        if (destory)
        {
            (* destory)(t->data);
        }

        delete t;
    }

    list->tail = NULL;
    list->count = 0;
}

// ��������
void LiTraverse(PLIST list, MANIPULATE_OBJECT manipulate, ADT tag)
{
    if (!list)
    {
        cout << "LiTraverse: Parameter(s) illegal." << endl;
        exit(1);
    }

    PNODE node = list->head;
    while (node)
    {
        (*manipulate)(node->data, tag);
        node = node->next;
    }
}

// �������в���ָ���ڵ�
bool LiSearch(PLIST list, ADT obj, COMPARE_OBJECT compare)
{
    if (!list)
    {
        cout << "LiTraverse: Parameter(s) illegal." << endl;
        exit(1);
    }

    PNODE node = list->head;
    while (node)
    {
        if ((*compare)(node->data, obj))
        {
            return true;
        }
        node = node->next;
    }

    return false;
}

// ��ȡ����ڵ������
int LiGetCount(PLIST list)
{
    if (!list)
    {
        cout << "LiTraverse: Parameter(s) illegal." << endl;
        exit(1);
    }

    return list->count;
}

// �ж������Ƿ�Ϊ��
bool LiIsEmpty(PLIST list)
{
    if (!list)
    {
        cout << "LiTraverse: Parameter(s) illegal." << endl;
        exit(1);
    }

    return list->count == 0;
}
