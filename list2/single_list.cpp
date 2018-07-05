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

// 创建链表
PLIST LiCreate()
{
    PLIST list = new LIST;
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// 销毁链表
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

// 在链表末尾添加节点
void LiAppend(PLIST list, ADT obj)
{
    if (!list)
    {
        cout << "LiAppend: Parameter(s) illegal." << endl;
        exit(1);
    }

    // 创建新的节点
    PNODE newNode = new NODE;
    newNode->data = obj;
    newNode->next = NULL;

    if (list->count == 0) // 链表为空的时候
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode; // 链表不为空，直接插入链表尾
        list->tail = newNode;
    }
    list->count ++;
}

// 在链表的指定位置插入节点
// obj为新节点的数据域
// pos的值从0开始
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

    if (pos <= 0) // 插入到表头
    {
        newNode->next = list->head;
        list->head = newNode;

        if (!list->tail) // 要插入的链表是空表时
        {
            list->tail = newNode;
        }

        list->count ++;
    }
    else if (pos < list->count) // 要插入的位置在链表中间（即不是头尾）
    {
        PNODE preNode = list->head; // 要插入的节点的前一个节点
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
        LiAppend(list, obj); // 添加到表尾
    }
}

// 删除链表指定位置的节点
void LiDelete(PLIST list, unsigned int pos, DESTORY_OBJECT destory)
{
    if (!list)
    {
        cout << "LiDelete: Parameter(s) illegal." << endl;
        exit(1);
    }

    if (list->count == 0) // 空链表
    {
        return;
    }

    if (pos == 0) // 删除头结点
    {
        PNODE delNode = list->head;
        list->head = delNode->next;

        if (!delNode->next) // 要删除的节点是最后一个节点，将tail指针置空
        {
            list->tail = NULL;
        }

        if (destory)
        {
            (*destory)(delNode->data);
        }

        delete delNode;
    }
    else if (pos < list->count) // 删除非头节点
    {
        PNODE preDelNode = list->head; // 寻找要删除的节点的前一个节点
        for (unsigned int i = 0; i < pos - 1; i++)
        {
            preDelNode = preDelNode->next;
        }

        PNODE delNode = preDelNode->next; // 要删除的节点
        preDelNode->next = delNode->next;

        if (!delNode->next) // 要删除的节点是尾节点，更新tail指针
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

// 清空链表
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

// 遍历链表
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

// 在链表中查找指定节点
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

// 获取链表节点的数量
int LiGetCount(PLIST list)
{
    if (!list)
    {
        cout << "LiTraverse: Parameter(s) illegal." << endl;
        exit(1);
    }

    return list->count;
}

// 判断链表是否为空
bool LiIsEmpty(PLIST list)
{
    if (!list)
    {
        cout << "LiTraverse: Parameter(s) illegal." << endl;
        exit(1);
    }

    return list->count == 0;
}
