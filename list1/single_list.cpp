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

// 创建链表
PLIST LiCreate()
{
    PLIST list = new LIST;
    list->head = NULL; // 首元节点
    list->tail = NULL;
    list->count = 0;
    return list;
}

// 销毁链表
void LiDestroy(PLIST list)
{
    if (list)
    {
        LiClear(list); // 释放分配给节点的空间
        delete list;
    }
}

// 在链表末尾添加节点
void LiAppend(PLIST list, PPOINT point)
{
    if (!list || !point)
    {
        cout << "LiAppend: Parameter illegal." << endl;
        exit(1);
    }

    // 创建新节点
    PNODE node = new NODE;
    node->data = point;
    node->next = NULL;

    if (!list->head) // 如果链表为空
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

// 在链表的指定位置插入节点
void LiInsert(PLIST list, PPOINT point, unsigned int pos)
{
    if (!list || !point)
    {
        cout << "LiInsert: Parameter illegal." << endl;
        exit(1);
    }

    // 创建节点
    PNODE node = new NODE;
    node->data = point;
    node->next = NULL;

    if (pos == 0) // 在表头插入节点
    {
        node->next = list->head;
        list->head = node;
        list->count ++;
    }
    else if (pos < list->count) // 插入链表中
    {
        // 寻找要插入节点的前一个位置
        PNODE u = list->head;
        for (unsigned int i = 0; i < pos - 1; i++)
        {
            u = u->next;
        }

        node->next = u->next;
        u->next = node;
        list->count ++;
    }
    else                // 在链表尾插入节点
    {
        LiAppend(list, point);
    }
}

// 删除链表指定位置的节点
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

    if (pos == 0) // 删除头节点
    {
        PNODE t = list->head;
        list->head = t->next;

        if (!t->next) // 要删除的节点是最后一个节点了，更新tail指针
        {
            list->tail = NULL;
        }

        PtDestory(t->data); // 释放节点空间
        delete t;
    }
    else if (pos < list->count) // 要删除的节点在链表的中间位置（非首尾）
    {
        // 找出要删除的节点的前一个节点
        PNODE u = list->head;
        for (unsigned int i = 0; i < pos; i++)
        {
            u = u->next;
        }

        PNODE t = u->next; // 要删除的节点

        if (!t->next) // 要删除的是最后一个节点，更新tail指针
        {
            list->tail = u;
        }

        u->next = t->next;
        PtDestory(t->data); // 释放内存空间
        delete t;
    }

    list->count --;

}

// 清空链表
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

// 遍历链表
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

// 在链表中查找指定节点
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

// 获取链表节点的数量
int LiGetCount(PLIST list)
{
    if (!list)
    {
        cout << "LiGetCount: Parameter illegal." << endl;
        exit(1);
    }

    return list->count;
}

// 判断链表是否为空
bool LiIsEmpty(PLIST list)
{
    if (!list)
    {
        cout << "LiIsEmpty: Parameter illegal." << endl;
        exit(1);
    }

    return list->count == 0;
}

